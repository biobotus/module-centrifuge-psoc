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

#include <project.h>

uint16 readSSI(void);
void writeSSI(uint8);

void pushReadSSI(uint8);
uint8 pullReadSSI(void);
int32 lengthReadSSI(void);
void clearReadSSI(void);

void pushWriteSSI(uint8);
uint8 pullWriteSSI(void);
int32 lengthWriteSSI(void);
void clearWriteSSI(void);

void enableProg(void);
/* [] END OF FILE */
