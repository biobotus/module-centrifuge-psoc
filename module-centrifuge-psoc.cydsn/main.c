/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>
#include <math.h>
#include <CAN_Communication.h>
#include <Door.h>
#include <SSI.h>
// GLOBAL
int8 g_regisPower;
int16 g_sensorPos;
int32 g_rpm;
int32 g_stopPosition;
int16 g_offset_position = 0;
int32 g_control_mode;
int32 g_numberStep;
int32 g_step, g_nbStep;
int16 g_deltaPos;
int16 g_oldPos;
uint8 g_firstConvert;
float g_xLimit, g_xDelta;
float g_yLimit, g_yDelta;
float g_zLimit, g_zDelta;
// EPROM
static const uint8 CYCODE offsetPosition[] = {0,0,0,0};
cystatus cy_status;
// CAN
int messageToBeTreatedCount = 0;
int msgToBeTreatedIndex = 0;
int msgToBeStoredIndex = 0;

CAN_MSG send;
CAN_MSG receivedMsgs[MAX_MSG_BUFFER_SIZE]; 

// PROTOTYPE
void init(void);
void initBrushless(void);
void treatMessage();
void openClose(uint8 status);
void startStop(uint8 status);
void moveToPosition(uint16 position);
void updateRPM(void);
void moveStep(uint8 direction);
// CONVERSION
int FourBytesToInt(uint8 byte1, uint8  byte2, uint8  byte3, uint8  byte4);
float FourBytesToFloat(uint8 byte1, uint8  byte2, uint8  byte3, uint8  byte4);
int GToRPM(int32);
int RPMToClockDivider(int32);
int ClockDividerToRPM(int32);


// INTERRUPT
CY_ISR_PROTO(isr_position);
CY_ISR_PROTO(isr_brushlessStep);
CY_ISR_PROTO(isr_ADC);
CY_ISR_PROTO(isr_SSI_Read);
CY_ISR_PROTO(isr_SSI_Write);
// UNION
union bytesToFloat{
    float f;
    uint8 bytes[4];   
} BTF;

uint16 sinTable[32] = {5000, 5975, 6913, 7778, 8536, 9157, 9619, 9904, 10000, 9904, 9619, 9157, 8536, 7778, 6913, 5975, 5000, 4025, 3087, 2222, 1464, 843, 381, 96, 0, 96, 381, 843, 1464, 2222, 3087, 4025  };

//----------------------------------------------------------------------------------------
int main()
{
    init();
    initBrushless();
    enableProg(); 
    for(;;)
    {
        
           
        treatMessage();
        //g_sensorPos = readSSI();
        //clearReadSSI();
        //writeSSI(0);
        
        switch(g_control_mode){
            case SPEED_CONTROL:
            {
                updateRPM();
                break;
            }
            case POSITION_CONTROL:
            {
                break;
            }
            case CALIBRATION_CONTROL:
            {   
                break;   
            }
        }
        CyDelay(25); // will be removed modified for proper updateRPM
    }
}
//----------------------------------------------------------------------------------------
void init()
{
    Em_EEPROM_1_Start();
    ADC_Start();
    PWM_Start();
    PositionCounter_Start();
    CAN_1_Start();
    CAN_1_GlobalIntEnable();
    Door_Init();
    
    CyGlobalIntEnable;
    isr_position_StartEx(isr_position);
    isr_position_Enable();
    
    isr_ADC_StartEx(isr_ADC);
    isr_ADC_Enable();
 
    Clock_2_Stop();
    isr_SSI_Read_StartEx(isr_SSI_Read);
    isr_SSI_Write_StartEx(isr_SSI_Write);
    isr_SSI_Read_Disable();
    
    // Initialize accelero default position
    g_firstConvert = 0;
    g_xDelta = 0.025;
    g_yDelta = 0.025;
    g_zDelta = 0.025;
    g_step = 0;
    g_nbStep = 0;
    g_numberStep = 0;
    g_regisPower = 0;
    // Initialize default RPM
    // This is important to set the Value to the RPM
    g_rpm = DEFAULT_RPM;
    g_control_mode = CALIBRATION_CONTROL;
}
//----------------------------------------------------------------------------------------
void initBrushless()
{
    ControlMode_Write(1);
    PhaseControl_Write(PHASE0);
    PWM_WriteCompare(PWM_MIN);
    StartStop_Write(1);
    CyDelay(1000);
    g_offset_position = g_sensorPos;
}
//----------------------------------------------------------------------------------------
void treatMessage()
{
    if(messageToBeTreatedCount>0)
    {
        // Treat the last message received and echo it back on the CAN bus as an acknowledgement.
        CAN_MSG msgToTreat = getReceivedMessage();
        if( msgToTreat.msgBytes.byte[INDEX_DEVICE_ID_BYTE] == DEVICE_ID)
        {
            echoBackToMaster(&msgToTreat); 
            switch( msgToTreat.msgBytes.byte[INDEX_INSTRUCTION_BYTE])
            {
                case OPEN_CLOSE:
                {   // Open or close the door
                    int32 status;        
                
                    status = FourBytesToInt(msgToTreat.msgBytes.byte[INDEX_DATABYTE1],
                                            msgToTreat.msgBytes.byte[INDEX_DATABYTE2],
                                            msgToTreat.msgBytes.byte[INDEX_DATABYTE3],
                                            msgToTreat.msgBytes.byte[INDEX_DATABYTE4]);
                    openClose(status);
                    break;
                }
                case START_STOP:
                {   // start the centrifuge, will use the last RPM or g force given.
                    g_control_mode = SPEED_CONTROL;
                    int32 status;  
                    status = FourBytesToInt(msgToTreat.msgBytes.byte[INDEX_DATABYTE1],
                                            msgToTreat.msgBytes.byte[INDEX_DATABYTE2],
                                            msgToTreat.msgBytes.byte[INDEX_DATABYTE3],
                                            msgToTreat.msgBytes.byte[INDEX_DATABYTE4]);
                    ControlMode_Write(0);
                    startStop(status);
                    
                    break;
                }
                case MOVE_TO_POSITION:
                {   // Move the centrifuge to the desired position
                    g_control_mode = POSITION_CONTROL;
                    g_stopPosition = FourBytesToInt(msgToTreat.msgBytes.byte[INDEX_DATABYTE1],
                                                  msgToTreat.msgBytes.byte[INDEX_DATABYTE2],
                                                  msgToTreat.msgBytes.byte[INDEX_DATABYTE3],
                                                  msgToTreat.msgBytes.byte[INDEX_DATABYTE4]);
                    startStop(START);
                    break;
                }
                case MOVE_X_STEP:
                {   // MOVE_STEP can be used for calibration.
                    g_control_mode = CALIBRATION_CONTROL;
                    g_numberStep = FourBytesToInt(msgToTreat.msgBytes.byte[INDEX_DATABYTE1],
                                                msgToTreat.msgBytes.byte[INDEX_DATABYTE2],
                                                msgToTreat.msgBytes.byte[INDEX_DATABYTE3],
                                                msgToTreat.msgBytes.byte[INDEX_DATABYTE4]);
                   
                    moveStep(1);
                    //isr_brushlessStep_Enable();
                    //startStop(START);
                    break;
                }
                case SET_RPM:
                {   // Set the RPM to apply (the last g or RPM will be used)
                    g_rpm = FourBytesToInt(msgToTreat.msgBytes.byte[INDEX_DATABYTE1],
                                         msgToTreat.msgBytes.byte[INDEX_DATABYTE2],
                                         msgToTreat.msgBytes.byte[INDEX_DATABYTE3],
                                         msgToTreat.msgBytes.byte[INDEX_DATABYTE4]);
                    break;
                }
                case SET_G:
                {   // Set the g force to apply (the last g or RPM will be used)
                    int32 g;
                    g = FourBytesToInt(msgToTreat.msgBytes.byte[INDEX_DATABYTE1],
                                       msgToTreat.msgBytes.byte[INDEX_DATABYTE2],
                                       msgToTreat.msgBytes.byte[INDEX_DATABYTE3],
                                       msgToTreat.msgBytes.byte[INDEX_DATABYTE4]);
                    g_rpm = GToRPM(g);
                    break;
                }
                case GET_POSITION:
                {   // Get the actual position of the centrifuge
                    CAN_MSG send;
                    send.msgBytes.byte[INDEX_DEVICE_ID_BYTE] = 0;
                    send.msgBytes.byte[INDEX_SUBMODULE_NUMBER_BYTE] = 0;
                    send.msgBytes.byte[INDEX_INSTRUCTION_BYTE] = GET_POSITION;
                    send.msgBytes.byte[INDEX_SPARE_BYTE] = 0;
                    send.msgBytes.byte[INDEX_DATABYTE1] = 0;//(angle>>24) & 0xFF;
                    send.msgBytes.byte[INDEX_DATABYTE2] = 0;//(angle>>16) & 0xFF;
                    send.msgBytes.byte[INDEX_DATABYTE3] = (g_sensorPos>>8) & 0xFF;
                    send.msgBytes.byte[INDEX_DATABYTE4] = (g_sensorPos>>0) & 0xFF;
                    sendMessage(&send, 1);
                    
                    break;
                }
                case SET_POSITION_OFFSET:
                {   // Set the offset position of the centrifuge.
                    uint8 temp[] = {msgToTreat.msgBytes.byte[INDEX_DATABYTE1],
                                    msgToTreat.msgBytes.byte[INDEX_DATABYTE2],
                                    msgToTreat.msgBytes.byte[INDEX_DATABYTE3],
                                    msgToTreat.msgBytes.byte[INDEX_DATABYTE4]};
                    cy_status = Em_EEPROM_1_Write(temp, offsetPosition,4u);
                    // We send the status for debuging use only, will be removed. 
                    /*CAN_MSG send;
                    send.msgBytes.byte[INDEX_DEVICE_ID_BYTE] = 0;
                    send.msgBytes.byte[INDEX_SUBMODULE_NUMBER_BYTE] = 0;
                    send.msgBytes.byte[INDEX_INSTRUCTION_BYTE] = SET_POSITION_OFFSET;
                    send.msgBytes.byte[INDEX_SPARE_BYTE] = 0;
                    send.msgBytes.byte[INDEX_DATABYTE1] = cy_status;
                    send.msgBytes.byte[INDEX_DATABYTE2] = 0;
                    send.msgBytes.byte[INDEX_DATABYTE3] = 0;
                    send.msgBytes.byte[INDEX_DATABYTE4] = 0;
                    sendMessage(&send, DEVICE_ID);
                    */
                    break;
                }
                case GET_POSITION_OFFSET:
                {   // Get the offset position of the centrifuge.
                    //CAN_MSG send;
                    send.msgBytes.byte[INDEX_DEVICE_ID_BYTE] = 0;
                    send.msgBytes.byte[INDEX_SUBMODULE_NUMBER_BYTE] = 0;
                    send.msgBytes.byte[INDEX_INSTRUCTION_BYTE] = GET_POSITION_OFFSET;
                    send.msgBytes.byte[INDEX_SPARE_BYTE] = 0;
                    send.msgBytes.byte[INDEX_DATABYTE1] = *(volatile uint8 *)&offsetPosition[0];
                    send.msgBytes.byte[INDEX_DATABYTE2] = *(volatile uint8 *)&offsetPosition[1];
                    send.msgBytes.byte[INDEX_DATABYTE3] = *(volatile uint8 *)&offsetPosition[2];
                    send.msgBytes.byte[INDEX_DATABYTE4] = *(volatile uint8 *)&offsetPosition[3];
                    sendMessage(&send, DEVICE_ID);
                    break;
                }
                case SET_VIBRATION_LIMIT:
                {   // Set x,y,z vibration limit
                    float delta;
                    delta = FourBytesToFloat(msgToTreat.msgBytes.byte[INDEX_DATABYTE1],
                                                      msgToTreat.msgBytes.byte[INDEX_DATABYTE2],
                                                      msgToTreat.msgBytes.byte[INDEX_DATABYTE3],
                                                      msgToTreat.msgBytes.byte[INDEX_DATABYTE4]);
                    switch(msgToTreat.msgBytes.byte[INDEX_SPARE_BYTE])
                    {
                        case X_AXE:
                        {
                            g_xDelta = delta;
                        }
                        case Y_AXE:
                        {
                            g_yDelta = delta;
                        }
                        case Z_AXE:
                        {
                            g_zDelta = delta;
                        }
                    }
                    break;
                }
                case SET_DUTY_CYCLE:
                {   // Set the duty cycle of PWM.
                    int32 power;
                    power = FourBytesToInt(msgToTreat.msgBytes.byte[INDEX_DATABYTE1],
                                                      msgToTreat.msgBytes.byte[INDEX_DATABYTE2],
                                                      msgToTreat.msgBytes.byte[INDEX_DATABYTE3],
                                                      msgToTreat.msgBytes.byte[INDEX_DATABYTE4]);
                    PWM_WriteCompare(4*power);
                    break;
                }
            }
        }
    }
}
//----------------------------------------------------------------------------------------
void openClose(uint8 status)
{
    if(status)
    {
        // open door
        Door_Home();
    }
    else{
        // close door
        Door_GoTo(75);
    }
}
//----------------------------------------------------------------------------------------
void startStop(uint8 status)
{
    if(status)
    {   // Start centrifuge
        PWM_WriteCompare(PWM_MIN);
        Clock_1_SetDividerValue(RPMToClockDivider(LOW_RPM));
        Clock_1_Start();
        StartStop_Write(1);  
    }
    else{
        // Stop centrifuge
        // We do not use the update RPM because we don't want to lose the previous value
        int32 currentRPM;
        currentRPM = ClockDividerToRPM(Clock_1_GetDividerRegister() + 1);
        while(LOW_RPM < currentRPM)
        {
            // pourrait avoir une courbe d'accélération
            currentRPM -= 100;
            Clock_1_SetDividerValue(RPMToClockDivider(currentRPM));
            CyDelay(10);
        }
        Clock_1_Stop();
        StartStop_Write(0);
    }
}
//----------------------------------------------------------------------------------------
void updateRPM()
{
    int32 currentRPM;
    currentRPM = ClockDividerToRPM(Clock_1_GetDividerRegister() + 1);
    if(g_rpm < currentRPM)
    {
        
        // pourrait avoir une courbe d'accélération
        currentRPM -= 100; 
        Clock_1_SetDividerValue(RPMToClockDivider(currentRPM));
    }
    else if(g_rpm > currentRPM)
    {
        // pourrait avoir une courbe décélération
        currentRPM += 100;   
        Clock_1_SetDividerValue(RPMToClockDivider(currentRPM));
    }
    
}

//----------------------------------------------------------------------------------------
void moveStep(uint8 direction)
{
    switch(PhaseControl_Read())
    {
        case PHASE0:
        {
            if(direction)
            {
                PhaseControl_Write(PHASE1);    
            }
            else
            {
                PhaseControl_Write(PHASE5);
            }
            
            break;
        }
        case PHASE1:
        {
            if(direction)
            {
                PhaseControl_Write(PHASE2);    
            }
            else
            {
                PhaseControl_Write(PHASE0);
            }
            break;
        }
        case PHASE2:
        {
            if(direction)
            {
                PhaseControl_Write(PHASE3);    
            }
            else
            {
                PhaseControl_Write(PHASE1);
            }
            break;
        }
        case PHASE3:
        {
            if(direction)
            {
                PhaseControl_Write(PHASE4);    
            }
            else
            {
                PhaseControl_Write(PHASE2);
            }
            break;
        }
        case PHASE4:
        {
            if(direction)
            {
                PhaseControl_Write(PHASE5);    
            }
            else
            {
                PhaseControl_Write(PHASE3);
            }
            break;
        }
        case PHASE5:
        {
            if(direction)
            {
                PhaseControl_Write(PHASE0);    
            }
            else
            {
                PhaseControl_Write(PHASE4);
            }
            break;
        }
    }
}
//----------------------------------------------------------------------------------------

/*----------------------------------------------------------------------------------------
        CONVERTION
----------------------------------------------------------------------------------------*/
int FourBytesToInt(uint8 byte1, uint8  byte2, uint8  byte3, uint8  byte4)
{
    int32 integer;
    integer =  byte1 + (byte2<<8) + (byte3<<16) + (byte4<<24);
    return integer;
}
//----------------------------------------------------------------------------------------
float FourBytesToFloat(uint8 byte1, uint8  byte2, uint8  byte3, uint8  byte4)
{
    BTF.bytes[0] = byte1;
    BTF.bytes[1] = byte2;
    BTF.bytes[2] = byte3;
    BTF.bytes[3] = byte4;
    
    return BTF.f;
}
//----------------------------------------------------------------------------------------
int GToRPM(int32 gInput)
{
    // equation to convert g force to rpm
    return (int)sqrt(gInput/1.118/0.00001/RADIUS_CM);
}
//----------------------------------------------------------------------------------------
int RPMToClockDivider(int32 rpmInput)
{  
    // Have to multiply by the number of clock needed to complete one turn.
    // /60 -> convert min to sec
    // *6 -> number of step in a electrical revolution
    // *7 -> number of electrical revolution in a mechanical revolution for the specific motor
    // *10 -> frequency divider that allow a better range of Clock divider for rpm between 60 and 16500
    // 24000000 = master clock frequency
    return 24000000/(rpmInput/60*6*7*10); 
}
//----------------------------------------------------------------------------------------
int ClockDividerToRPM(int32 clockDividerInput)
{  
    // Have to multiply by the number of clock needed to complete one turn.
    // *60 -> convert min to sec
    // /6 -> number of step in a electrical revolution
    // /7 -> number of electrical revolution in a mechanical revolution for the specific motor
    // /10 -> frequency divider that allow a better range of Clock divider for rpm between 60 and 16500
    // 24000000 = master clock frequency
    return (24000000/clockDividerInput)*60/6/7/10; 
}


/*----------------------------------------------------------------------------------------
        INTERRUPT
----------------------------------------------------------------------------------------*/
CY_ISR(isr_position)
{
    // as explained in the datasheet of the magnetic sensor, 
    // there is 16 high step at the beginning of the pwm signal.
    uint32 newPos;
    newPos = PositionCounter_ReadCapture() - 16 - FourBytesToInt(*(volatile uint8 *)&offsetPosition[0],
                                                                      *(volatile uint8 *)&offsetPosition[1],
                                                                      *(volatile uint8 *)&offsetPosition[2],
                                                                      *(volatile uint8 *)&offsetPosition[3]);
    if (newPos <= 0)
    {
        newPos += 360;   
    }
    
    PositionCounter_ReadStatusRegister();
    
    
    g_sensorPos = newPos;
}
//----------------------------------------------------------------------------------------
CY_ISR(isr_brushlessStep)
{
   /* g_step ++;
    if(g_step >= g_numberStep)
    {
        Clock_1_Stop();
        isr_brushlessStep_Disable();
        //CyDelay(25);
        StartStop_Write(0);
        
        g_step = 0;
    }*/
    
    /*if(StartStop_Read())
    {
        g_deltaPos = fabsf(g_oldPos - g_sensorPos);
        if(DELTA_ANGLE +1 <= g_deltaPos)
        {   
            g_regisPower = -1;
        }
        else
        {
            if(g_deltaPos == 0)
            {
                startStop(STOP);
            }
            if(g_deltaPos < DELTA_ANGLE -1)
            {
                // lever un flag
                g_regisPower = 1;
            }
            else
            {
                g_regisPower = 0;   
            }
        }
    }
    g_oldPos = g_sensorPos;
*/
}
//----------------------------------------------------------------------------------------
CY_ISR(isr_ADC)
{
    if(g_firstConvert == 0)
    {
        g_xLimit = ADC_CountsTo_Volts(ADC_GetResult16(3));
        g_yLimit = ADC_CountsTo_Volts(ADC_GetResult16(4));
        g_zLimit = ADC_CountsTo_Volts(ADC_GetResult16(5));
        g_firstConvert = 1;
    }
    if(fabs(ADC_CountsTo_Volts(ADC_GetResult16(3)) - g_xLimit) >= g_xDelta)
    {
        startStop(STOP);
    }
    if(fabs(ADC_CountsTo_Volts(ADC_GetResult16(4)) - g_yLimit) >= g_yDelta)
    {
        startStop(STOP);
    }
    if(fabs(ADC_CountsTo_Volts(ADC_GetResult16(5)) - g_zLimit) >= g_zDelta)
    {
        startStop(STOP);
    }   
}
//----------------------------------------------------------------------------------------
CY_ISR(isr_SSI_Read)
{
   pushReadSSI(RotarySensor_SSI_DIO_Read());
    if(lengthReadSSI() >= 16)
    {
        isr_SSI_Read_Disable();
        SSI_Enable_Write(0);
        Clock_2_Stop();
        
    }
}
//----------------------------------------------------------------------------------------
CY_ISR(isr_SSI_Write)
{
    
    RotarySensor_SSI_DIO_Write(pullWriteSSI());
    if(lengthWriteSSI() == 0)
    {
        isr_SSI_Write_Disable();
        SSI_Enable_Write(0);
        Clock_2_Stop();
        //isr_SSI_Read_Enable();
        
    }
}
/* [] END OF FILE */
