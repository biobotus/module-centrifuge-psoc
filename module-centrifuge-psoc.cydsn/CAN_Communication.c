/* ========================================
 *
 * Copyright BioBot Instrumentation, 2015
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF BioBot Instrumentation.
 *
 * WRITTEN BY : Philippe-Antoine Major &
 *              Louis-Vincent Major
 * ========================================
*/

#include "CAN_Communication.h"

// Treating the messages in the order they were received by the master.
CAN_MSG getReceivedMessage()
{
    //struct RX_Msg msgToTreat = receivedMessages[msgToBeTreatedIndex];
    CAN_MSG msgToTreat = receivedMsgs[msgToBeTreatedIndex];
   
    // If we reached the limit of the message buffer table, we reset the index of messages to be treated to 0.            
    if (msgToBeTreatedIndex == MAX_MSG_BUFFER_SIZE)
    {
        msgToBeTreatedIndex = 0;
    }
    else
    {
        msgToBeTreatedIndex++; // Increment the counter indicating at which index starts the last message.
    }
    // A message was treated, we decrement the counter of messages to be treated.
    messageToBeTreatedCount += -1;
    
    return msgToTreat;
}

// Send a message on the CAN Bus.
int8 sendMessage(CAN_MSG* msgPtr, uint32 CAN_ID)
{
    CAN_1_TX_MSG msgToSend;
    
    msgToSend.id = CAN_ID;   
    msgToSend.rtr = MSG_RTR;
    msgToSend.ide = MSG_IDE;
    msgToSend.irq = MSG_IRQ;
    msgToSend.msg = &msgPtr->msgBytes;
    msgToSend.dlc = msgPtr->DLC;
    
    CAN_1_SendMsg(&msgToSend);
    return 1;
}

int8 echoBackToMaster(CAN_MSG* msgPtr)
{
    CAN_1_TX_MSG msgToSendBack;
    // Setting all the parameters for the message to send back.    
    msgToSendBack.id = MASTER_ID;
    msgToSendBack.rtr = MSG_RTR;
    msgToSendBack.ide = MSG_IDE;
    msgToSendBack.irq = MSG_IRQ;
    msgToSendBack.dlc = msgPtr->DLC;
    msgToSendBack.msg = &msgPtr->msgBytes; 
    
    CAN_1_SendMsg(&msgToSendBack);
    
    return 1;
}

int8 answerToMaster(uint8 definedAnswer, uint8 submoduleNumber)
{
    CAN_1_TX_MSG msgToSendBack;
    // Setting all the parameters for the message to send back.    
    msgToSendBack.id = MASTER_ID;
    msgToSendBack.rtr = MSG_RTR;
    msgToSendBack.ide = MSG_IDE;
    msgToSendBack.irq = MSG_IRQ;
    msgToSendBack.msg->byte[INDEX_DEVICE_ID_BYTE] = DEVICE_ID;
    msgToSendBack.msg->byte[INDEX_SUBMODULE_NUMBER_BYTE] = submoduleNumber;
    msgToSendBack.msg->byte[INDEX_INSTRUCTION_BYTE] = definedAnswer;
    msgToSendBack.dlc = 3;     
    
    CAN_1_SendMsg(&msgToSendBack);
    
    return 1;    
}
/* [] END OF FILE */
