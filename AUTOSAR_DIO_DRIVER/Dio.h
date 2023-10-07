/*
 * Dio.h
 *
 *  Created on: Oct 7, 2023
 *      Author: Kareem Hani
 */

#include <stdint.h>

/*These will be passed for Dio_LevelType*/
#define STD_LOW     ( 0x00U )
#define STD_HIGH     ( 0x01U )

typedef uint8_t Dio_ChannelType;  /* Numeric ID of a DIO channel */
typedef uint8_t Dio_PortType  ; /*Numeric ID of a DIO port */
typedef uint8_t Dio_LevelType; /*These are the possible levels a DIO channel can have (input or output)*/
typedef uint8_t Dio_PortLevelType; /*If the µC owns ports of different port widths (e.g. 4, 8,16...Bit) Dio_PortLevelType inherits the size of the largest port*/


/* Leave it now for simplicity */
typedef struct
{


}Dio_ChannelGroupType;

#ifndef DIO_H_
#define DIO_H_

Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId);
void Dio_WriteChannel (Dio_ChannelType ChannelId,Dio_LevelType Level);
Dio_PortLevelType Dio_ReadPort (Dio_PortType PortId);
void Dio_WritePort (Dio_PortType PortId,Dio_PortLevelType Level);



#endif /* DIO_H_ */
