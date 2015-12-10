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
// SSI

#include <SSI.h>

int32 ssiReadBuf [256];
int32 ssiReadHead = 0;
int32 ssiReadTail = 0;

int32 ssiWriteBuf [256];
int32 ssiWriteHead = 0;
int32 ssiWriteTail = 0;
//----------------------------------------------------------------------------------------
void writeSSI(uint8 input)
{
    
    int i;
    clearWriteSSI();
    for(i = 0; i < 8 ; i++ )
    {
        pushWriteSSI((input>>i) & 0x01);
    }
    isr_SSI_Write_Enable();
    SSI_Enable_Write(1);
    Clock_2_Start();
    
}
//----------------------------------------------------------------------------------------
uint16 readSSI()
{
    // get the angle from the magnetic sensor
    int16 angle = 0;
    if(lengthReadSSI() >= 16)
    {
        int32 i;
        uint8 junk;
        
        junk = pullReadSSI();
        junk = pullReadSSI();
        junk = 0;
        for(i = 0; i<=8;i++)
        {
            angle += pullReadSSI() <<(8-i);   
        }
        while(lengthReadSSI())
        {
            junk = pullReadSSI();
        }
    }
    return angle;
}
//----------------------------------------------------------------------------------------
void pushReadSSI(uint8 input)
{
    ssiReadBuf[ssiReadHead] = input;   
    ssiReadHead += 1;
    if(ssiReadHead >= 256)
    {
        ssiReadHead = 0;
    }
}
//----------------------------------------------------------------------------------------
uint8 pullReadSSI()
{
    uint8 output;
    output = ssiReadBuf[ssiReadTail];
    ssiReadTail+=1;
    if(ssiReadTail >= 256){
        ssiReadTail = 0;   
    }
    return output;
}
//----------------------------------------------------------------------------------------
int32 lengthReadSSI()
{
    int32 length;
    length = ssiReadHead - ssiReadTail;
    if(length < 0)
    {
        length += 256;
    }
    return length;
}
//----------------------------------------------------------------------------------------
void clearReadSSI(void)
{
    ssiReadTail = ssiReadHead;
}
//----------------------------------------------------------------------------------------
void pushWriteSSI(uint8 input)
{
    ssiWriteBuf[ssiWriteHead] = input;   
    ssiWriteHead += 1;
    if(ssiWriteHead >= 256)
    {
        ssiWriteHead = 0;
    }
}
//----------------------------------------------------------------------------------------
uint8 pullWriteSSI()
{
    uint8 output;
    output = ssiWriteBuf[ssiWriteTail];
    ssiWriteTail+=1;
    if(ssiWriteTail >= 256)
    {
        ssiWriteTail = 0;   
    }
    return output;
}
//----------------------------------------------------------------------------------------
int32 lengthWriteSSI()
{
    int32 length;
    length = ssiWriteHead - ssiWriteTail;
    if(length < 0)
    {
        length += 256;
    }
    return length;
}
//----------------------------------------------------------------------------------------
void clearWriteSSI(void)
{
    ssiWriteTail = ssiWriteHead;
}

void enableProg()
{
    pushWriteSSI(1);
    pushWriteSSI(0);
    pushWriteSSI(0);
    pushWriteSSI(0);
    pushWriteSSI(0);
    pushWriteSSI(1);
    pushWriteSSI(0);
    pushWriteSSI(0);
    pushWriteSSI(0);
    pushWriteSSI(1);
    pushWriteSSI(1);
    pushWriteSSI(0);
    pushWriteSSI(0);
    pushWriteSSI(1);
    pushWriteSSI(0);
    pushWriteSSI(1);
    pushWriteSSI(0);
    pushWriteSSI(1);
    pushWriteSSI(1);
    pushWriteSSI(1);
    pushWriteSSI(0);
    pushWriteSSI(0);
    pushWriteSSI(0);
    pushWriteSSI(0);
    
    isr_SSI_Write_Enable();
    SSI_Enable_Write(1);
    Clock_2_Start();
}
/* [] END OF FILE */
