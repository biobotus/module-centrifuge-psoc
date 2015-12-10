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

#include <Door.h>

//#include <CAN_Communication.h>
//#include <Defines.h>

/*----Private functions declarations----*/
//CY_ISR_PROTO(Door_Bumper_ISR);

/*----Private variables---*/
uint16 Door_pos;
uint16 screw_lead = 2;           // in milimeters/turn
uint16 motor_steps_turn = 200;      // steps/turn for motor
uint16 f_ustepping = 4;             // microstepping factor (1,2,4,8,16)
uint8 motor_direction = 0;          // 0 = up, 1 = down
const uint8 motor_up = 0;
const uint8 motor_down = 1;
const uint16 max_distance = 76;   // hundreds of micrometers 76mm

void Door_Init()
{
     //*****Init variables******///
    Door_Clock_Start();
    
    //Motor speed init
    Door_Motor_Speed_Start();
    //Distance init
    Door_Step_Dist_Start();
    //Motor power init
    Door_Power_Start();
    
    //Interrupt initialization
    Door_Bumper_ISR_StartEx(Door_Bumper_ISR);
    Door_Bumper_ISR_Enable();
    //Bumper_isr_StartEx(Bumper_isr);
    //Door_Bumper_Port_ClearInterrupt();
    Door_Bumper_ISR_ClearPending();
    
    switch (f_ustepping) {
        case 1: // 1 ustepping
        {
            Door_StepSizeA_Write(0);
            Door_StepSizeB_Write(0);
            break;
        }
        
        case 2: // 1/2 ustepping
        {
            Door_StepSizeA_Write(1);
            Door_StepSizeB_Write(0);
            break;
        }
        
        case 4: // 1/4 ustepping
        {
            Door_StepSizeA_Write(0);
            Door_StepSizeB_Write(1);
            break;
        }
        
        case 8: // 1/8 ustepping
        {
            //Allegro chip can't make 1/8 ustepping
            break;
        }
        
        case 16: // 1/16 ustepping
        {
            Door_StepSizeA_Write(1);
            Door_StepSizeB_Write(1);
            break;
        }
        default:
        {
            break;
        }
    }
    Door_Direction_Write(motor_direction);
    Door_Enable_Write(0);
    
    Door_Home();
}

void Door_Home() {
    //Verifies if already on bumper, otherwise gets to bumper
    if (Door_Bumper_Port_Read() == 0){
        
        // Activate motor to get to bumper
        Door_Direction_Write(motor_up);
        Door_Step_Dist_WriteCompare(max_distance/screw_lead*(motor_steps_turn*f_ustepping));
        Door_GO_Write(1); //Motor starts
    }
    Door_pos = 0;
}

// Initialization for
void Bumper_Stops()
{   
    Door_Step_Dist_WriteCompare(0);
    Door_pos = 0;
}

void Door_GoTo(uint16 position){
    uint16 travel;
    uint32 steps_to_do;
    if (position < Door_pos) {
        travel = Door_pos - position;
        steps_to_do = travel/screw_lead*(motor_steps_turn*f_ustepping);
        motor_direction = motor_up;
    }
    
    else if (position > Door_pos) {
        travel = position - Door_pos;
        steps_to_do = travel/screw_lead*(motor_steps_turn*f_ustepping);
        motor_direction = motor_down;
    }
    
    else {
        travel = 0;
        steps_to_do = 0;
    }
    Door_pos = position;
    // Setting up motor direction
    Door_Direction_Write(motor_direction);
    Door_Step_Dist_WriteCompare(steps_to_do);
    Door_GO_Write(1);
}

CY_ISR(Door_Bumper_ISR){
    Bumper_Stops();
    //Door_Bumper_Port_ClearInterrupt();
}
/* [] END OF FILE */
