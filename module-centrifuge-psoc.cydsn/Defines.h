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
#include <CyLib.h>
//DEFINE for specific module (use internally only)
#define START                       (0x01)
#define STOP                        (0x00)
#define OPEN                        (0x01)
#define CLOSE                       (0x00)
#define RADIUS_CM                   (0x06)
#define LOW_SPEED                   (0xFF)
#define STOP_SPEED                  (0x6F)
#define LOW_RPM                     60
#define DEFAULT_RPM                 200  // Use to set PWM value at the beginning


#define PWM_MIN                     60
#define PWM_MAX                     200
#define PHASE0                      1
#define PHASE1                      2
#define PHASE2                      4
#define PHASE3                      8
#define PHASE4                      16
#define PHASE5                      32

#define SPEED_CONTROL               (0x00)
#define POSITION_CONTROL            (0x01)
#define CALIBRATION_CONTROL         (0x02)

#define X_AXE                       (0x00)
#define Y_AXE                       (0x01)
#define Z_AXE                       (0x02)

#define DELTA_ANGLE                 10 // 10 degree by phase step

//CAN message Instructions list
#define OPEN_CLOSE                  (0x00)  //
#define START_STOP                  (0x01)  //
#define MOVE_TO_POSITION            (0x02)  //
#define MOVE_X_STEP                 (0x03)  //
#define SET_RPM                     (0x04)  //
#define SET_G                       (0x05)  //
#define GET_POSITION                (0x06)  //
#define SET_POSITION_OFFSET         (0x07)  //  
#define GET_POSITION_OFFSET         (0x08)  // 
#define SET_VIBRATION_LIMIT         (0x09)  // 
#define SET_DUTY_CYCLE              (0x0A)  //

//CAN POSSIBLE ANSWERS
#define BAD_COMMAND                 (0x11)  // To send if the instruction received is not recognized
#define BAD_VALUE                   (0x12)  // To send if the value is not inside defined limits

//Device ID
#define DEVICE_ID                   (0x00)  // Unique ID for the device on the platform (to change between different devices)
//#define DEVICE_TYPE               (0)     // Type of device (0=TAC, 1=MC1.5, 2=MC96)

/* [] END OF FILE */
