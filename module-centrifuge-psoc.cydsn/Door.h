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

// Mask used for bitwise operations
#define MASK_BIT_0  0x01
#define MASK_BIT_1  0x02
#define MASK_BIT_2  0x04
#define MASK_BIT_3  0x08
#define MASK_BIT_4  0x10
#define MASK_BIT_5  0x20
#define MASK_BIT_6  0x40
#define MASK_BIT_7  0x80

// Variables
uint32 pwm_counter1;    // Is incremented during interrupt routine
uint32 actualStep1;        // Current absolute position
uint32 step_max1;       // Maximum step for this stepper motor
uint32 step_nb1;        // Step number of the recevied command
uint8 running_flag1;    // Indicate that stepper-motor 1 is running
uint8 Door_Homing_Flag;
uint8 Door_Homing_Command;

uint32 pwm_counter2;
uint32 actualStep2;
uint32 step_max2;
uint32 step_nb2;
uint8 running_flag2;

uint8 Bumper_Register_Int_Flag;     // Used to store Bumper_Register value when interrupt occurs
uint8 Bumper_Z_Up_Int_Flag;
uint8 Bumper_Z_Down_Int_Flag;
uint8 Bumper_Pipette_Empty_Int_Flag;
uint8 Bumper_Pipette_Fill_Int_Flag;

CY_ISR_PROTO(Door_Bumper_ISR);

/*Public functions declarations*/
void Door_Home();
void Door_GoTo(uint16);
void Door_Init();
void Bumper_Stops();

// Functions Prototype
/*void Init_Stepper_Motor();      // Initialization
void Stepper_Motor1_Init();     // Eventually split Init_Stepper_Motor into Init_Stepper_Motor1 and 2
void Stepper_Motor2_Init();

void Bumper_Init();

void Set_DIR1(int);             // Set direction
void Enable_StepperDrive_1();   // Enable the stepper motor driver
void Disable_StepperDrive_1();  // Disable the stepper motor driver
void Set_StepSize1();           // Set step size
void Door_Homing();           // Bring back the axis of the stepper motor to home
void Door_Stop();             // Stop the stepper motor
void Door_Up();               // Start the stepper motor to go up
void Door_Down();             // Start the stepper motor to go down
CY_ISR(PWM_isr_1);              // ISR for the PWM of this stepper motor

void Set_DIR2(int);
void Enable_StepperDrive_2();
void Disable_StepperDrive_2();
void Set_StepSize2();
void Pipette_Homing();
void Pipette_Stop();
void Pipette_Fill();
void Pipette_Empty();
CY_ISR(PWM_isr_2);

CY_ISR(Bumper_isr);             // Bumpers ISR
*/
CY_ISR(Door_Bumper_ISR);


/* [] END OF FILE */
