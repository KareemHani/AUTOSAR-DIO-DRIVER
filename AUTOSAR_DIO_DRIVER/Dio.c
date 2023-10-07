/*
 * Dio.c
 *
 *  Created on: Oct 7, 2023
 *      Author: Kareem Hani
 */

#include "Dio.h"
#include "tm4c123gh6pm.h"

/* Define the base addresses of GPIO ports */
#define GPIO_PORTA_BASE 0x40004000
#define GPIO_PORTB_BASE 0x40005000
#define GPIO_PORTC_BASE 0x40006000
#define GPIO_PORTD_BASE 0x40007000
#define GPIO_PORTE_BASE 0x40024000
#define GPIO_PORTF_BASE 0x40025000

// Define the offset addresses for various registers
#define GPIO_O_DATA 0x000
#define GPIO_O_DIR 0x400  /*GPIO Direction*/
#define GPIO_O_DEN 0x51C /*GPIO Digital Enable*/

#define DIO_LEVEL_INVALID 2

Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId)
{
    Dio_LevelType ReadValue;
    uint32_t Port;
    uint8_t Pin;

    switch (ChannelId)
    {
    /* PORTA */
        case 0:
            Port = GPIO_PORTA_BASE;
            Pin = 0;
            break;

        case 1:
            Port = GPIO_PORTA_BASE;
            Pin = 1;
            break;

        case 2:
            Port = GPIO_PORTA_BASE;
            Pin = 2;
            break;

        case 3:
            Port = GPIO_PORTA_BASE;
            Pin = 3;
            break;

        case 4:
            Port = GPIO_PORTA_BASE;
            Pin = 4;
            break;

        case 5:
            Port = GPIO_PORTA_BASE;
            Pin = 5;
            break;

        case 6:
            Port = GPIO_PORTA_BASE;
            Pin = 6;
            break;

        case 7:
            Port = GPIO_PORTA_BASE;
            Pin = 7;
            break;

    /* PORTB */
        case 8:
            Port = GPIO_PORTB_BASE;
            Pin = 0;
            break;

        case 9:
            Port = GPIO_PORTB_BASE;
            Pin = 1;
            break;

        case 10:
            Port = GPIO_PORTB_BASE;
            Pin = 2;
            break;

        case 11:
            Port = GPIO_PORTB_BASE;
            Pin = 3;
            break;

        case 12:
            Port = GPIO_PORTB_BASE;
            Pin = 4;
            break;

        case 13:
            Port = GPIO_PORTB_BASE;
            Pin = 5;
            break;

        case 14:
            Port = GPIO_PORTB_BASE;
            Pin = 6;
            break;

        case 15:
            Port = GPIO_PORTB_BASE;
            Pin = 7;
            break;

    /* PORTC */
        case 16:
            Port = GPIO_PORTC_BASE;
            Pin = 0;
            break;

        case 17:
            Port = GPIO_PORTC_BASE;
            Pin = 1;
            break;

        case 18:
            Port = GPIO_PORTC_BASE;
            Pin = 2;
            break;

        case 19:
            Port = GPIO_PORTC_BASE;
            Pin = 3;
            break;

        case 20:
            Port = GPIO_PORTC_BASE;
            Pin = 4;
            break;

        case 21:
            Port = GPIO_PORTC_BASE;
            Pin = 5;
            break;

        case 22:
            Port = GPIO_PORTC_BASE;
            Pin = 6;
            break;

        case 23:
            Port = GPIO_PORTC_BASE;
            Pin = 7;
            break;

    /* PORTD */
        case 24:
            Port = GPIO_PORTD_BASE;
            Pin = 0;
            break;

        case 25:
            Port = GPIO_PORTD_BASE;
            Pin = 1;
            break;

        case 26:
            Port = GPIO_PORTD_BASE;
            Pin = 2;
            break;

        case 27:
            Port = GPIO_PORTD_BASE;
            Pin = 3;
            break;

        case 28:
            Port = GPIO_PORTD_BASE;
            Pin = 4;
            break;

        case 29:
            Port = GPIO_PORTD_BASE;
            Pin = 5;
            break;

        case 30:
            Port = GPIO_PORTD_BASE;
            Pin = 6;
            break;

        case 31:
            Port = GPIO_PORTD_BASE;
            Pin = 7;
            break;

    /* PORTE */
        case 32:
            Port = GPIO_PORTE_BASE;
            Pin = 0;
            break;

        case 33:
            Port = GPIO_PORTE_BASE;
            Pin = 1;
            break;

        case 34:
            Port = GPIO_PORTE_BASE;
            Pin = 2;
            break;

        case 35:
            Port = GPIO_PORTE_BASE;
            Pin = 3;
            break;

        case 36:
            Port = GPIO_PORTE_BASE;
            Pin = 4;
            break;

        case 37:
            Port = GPIO_PORTE_BASE;
            Pin = 5;
            break;

        case 38:
            Port = GPIO_PORTE_BASE;
            Pin = 6;
            break;

        case 39:
            Port = GPIO_PORTE_BASE;
            Pin = 7;
            break;

    /* PORTF */
        case 40:
            Port = GPIO_PORTF_BASE;
            Pin = 0;
            break;

        case 41:
            Port = GPIO_PORTF_BASE;
            Pin = 1;
            break;

        case 42:
            Port = GPIO_PORTF_BASE;
            Pin = 2;
            break;

        case 43:
            Port = GPIO_PORTF_BASE;
            Pin = 3;
            break;

        case 44:
            Port = GPIO_PORTF_BASE;
            Pin = 4;
            break;

        case 45:
            Port = GPIO_PORTF_BASE;
            Pin = 5;
            break;

        case 46:
            Port = GPIO_PORTF_BASE;
            Pin = 6;
            break;

        case 47:
            Port = GPIO_PORTF_BASE;
            Pin = 7;
            break;

        default:
            /* Handle invalid channel */
            return DIO_LEVEL_INVALID;

    }
    /* Enable digital functionality on the pin */
    (*((volatile uint32_t *)(Port + GPIO_O_DEN))) |= (1 << Pin);

    /* Set the pin as an input */
    (*((volatile uint32_t *)(Port + GPIO_O_DIR))) &= ~(1 << Pin);

    /* Read the pin state */
    if ((*((volatile uint32_t *)(Port + GPIO_O_DATA))) & (1 << Pin))
    {
        ReadValue = STD_HIGH;
    }
    else
    {
        ReadValue = STD_LOW;
    }

    return ReadValue;
}

void Dio_WriteChannel (Dio_ChannelType ChannelId,Dio_LevelType Level)
{
    uint32_t Port;
    uint8_t Pin;

    switch (ChannelId)
    {
    /* PORTA */
        case 0:
            Port = GPIO_PORTA_BASE;
            Pin = 0;
            break;

        case 1:
            Port = GPIO_PORTA_BASE;
            Pin = 1;
            break;

        case 2:
            Port = GPIO_PORTA_BASE;
            Pin = 2;
            break;

        case 3:
            Port = GPIO_PORTA_BASE;
            Pin = 3;
            break;

        case 4:
            Port = GPIO_PORTA_BASE;
            Pin = 4;
            break;

        case 5:
            Port = GPIO_PORTA_BASE;
            Pin = 5;
            break;

        case 6:
            Port = GPIO_PORTA_BASE;
            Pin = 6;
            break;

        case 7:
            Port = GPIO_PORTA_BASE;
            Pin = 7;
            break;

    /* PORTB */
        case 8:
            Port = GPIO_PORTB_BASE;
            Pin = 0;
            break;

        case 9:
            Port = GPIO_PORTB_BASE;
            Pin = 1;
            break;

        case 10:
            Port = GPIO_PORTB_BASE;
            Pin = 2;
            break;

        case 11:
            Port = GPIO_PORTB_BASE;
            Pin = 3;
            break;

        case 12:
            Port = GPIO_PORTB_BASE;
            Pin = 4;
            break;

        case 13:
            Port = GPIO_PORTB_BASE;
            Pin = 5;
            break;

        case 14:
            Port = GPIO_PORTB_BASE;
            Pin = 6;
            break;

        case 15:
            Port = GPIO_PORTB_BASE;
            Pin = 7;
            break;

    /* PORTC */
        case 16:
            Port = GPIO_PORTC_BASE;
            Pin = 0;
            break;

        case 17:
            Port = GPIO_PORTC_BASE;
            Pin = 1;
            break;

        case 18:
            Port = GPIO_PORTC_BASE;
            Pin = 2;
            break;

        case 19:
            Port = GPIO_PORTC_BASE;
            Pin = 3;
            break;

        case 20:
            Port = GPIO_PORTC_BASE;
            Pin = 4;
            break;

        case 21:
            Port = GPIO_PORTC_BASE;
            Pin = 5;
            break;

        case 22:
            Port = GPIO_PORTC_BASE;
            Pin = 6;
            break;

        case 23:
            Port = GPIO_PORTC_BASE;
            Pin = 7;
            break;

    /* PORTD */
        case 24:
            Port = GPIO_PORTD_BASE;
            Pin = 0;
            break;

        case 25:
            Port = GPIO_PORTD_BASE;
            Pin = 1;
            break;

        case 26:
            Port = GPIO_PORTD_BASE;
            Pin = 2;
            break;

        case 27:
            Port = GPIO_PORTD_BASE;
            Pin = 3;
            break;

        case 28:
            Port = GPIO_PORTD_BASE;
            Pin = 4;
            break;

        case 29:
            Port = GPIO_PORTD_BASE;
            Pin = 5;
            break;

        case 30:
            Port = GPIO_PORTD_BASE;
            Pin = 6;
            break;

        case 31:
            Port = GPIO_PORTD_BASE;
            Pin = 7;
            break;

    /* PORTE */
        case 32:
            Port = GPIO_PORTE_BASE;
            Pin = 0;
            break;

        case 33:
            Port = GPIO_PORTE_BASE;
            Pin = 1;
            break;

        case 34:
            Port = GPIO_PORTE_BASE;
            Pin = 2;
            break;

        case 35:
            Port = GPIO_PORTE_BASE;
            Pin = 3;
            break;

        case 36:
            Port = GPIO_PORTE_BASE;
            Pin = 4;
            break;

        case 37:
            Port = GPIO_PORTE_BASE;
            Pin = 5;
            break;

        case 38:
            Port = GPIO_PORTE_BASE;
            Pin = 6;
            break;

        case 39:
            Port = GPIO_PORTE_BASE;
            Pin = 7;
            break;

    /* PORTF */
        case 40:
            Port = GPIO_PORTF_BASE;
            Pin = 0;
            break;

        case 41:
            Port = GPIO_PORTF_BASE;
            Pin = 1;
            break;

        case 42:
            Port = GPIO_PORTF_BASE;
            Pin = 2;
            break;

        case 43:
            Port = GPIO_PORTF_BASE;
            Pin = 3;
            break;

        case 44:
            Port = GPIO_PORTF_BASE;
            Pin = 4;
            break;

        case 45:
            Port = GPIO_PORTF_BASE;
            Pin = 5;
            break;

        case 46:
            Port = GPIO_PORTF_BASE;
            Pin = 6;
            break;

        case 47:
            Port = GPIO_PORTF_BASE;
            Pin = 7;
            break;

        default:
            /* Handle invalid channel */
            return;

    }
    /* Enable digital functionality on the pin */
    (*((volatile uint32_t *)(Port + GPIO_O_DEN))) |= (1 << Pin);

    /* Set the pin as an output */
    (*((volatile uint32_t *)(Port + GPIO_O_DIR))) |= (1 << Pin);

    /* Write the level to the pin */
    if (Level == STD_HIGH)
    {
        (*((volatile uint32_t *)(Port + GPIO_O_DATA))) |= (1 << Pin);
    }
    else
    {
        (*((volatile uint32_t *)(Port + GPIO_O_DATA))) &= ~(1 << Pin);
    }
}

Dio_PortLevelType Dio_ReadPort (Dio_PortType PortId)
{
    uint32_t Port;

    switch (PortId)
    {
        case 0:
            Port = GPIO_PORTA_BASE;
            break;
        case 1:
            Port = GPIO_PORTB_BASE;
            break;
        case 2:
            Port = GPIO_PORTC_BASE;
            break;
        case 3:
            Port = GPIO_PORTD_BASE;
            break;
        case 4:
            Port = GPIO_PORTE_BASE;
            break;
        case 5:
            Port = GPIO_PORTF_BASE;
            break;

        default:
            /* Handle invalid port */
            return 0xFF; /* Return an invalid value */
    }

    /* Enable digital functionality on all pins in the port */
    (*((volatile uint32_t *)(Port + GPIO_O_DEN))) |= 0xFF;

    /* Set all pins as inputs */
    (*((volatile uint32_t *)(Port + GPIO_O_DIR))) &= ~0xFF;

    /* Read the port state */
    return (*((volatile uint32_t *)(Port+ GPIO_O_DATA))) & 0xFF;
}

void Dio_WritePort (Dio_PortType PortId,Dio_PortLevelType Level)
{
    uint32_t Port;

    switch(PortId)
    {
            case 0:
                Port = GPIO_PORTA_BASE;
                break;
            case 1:
                Port = GPIO_PORTB_BASE;
                break;
            case 2:
                Port = GPIO_PORTC_BASE;
                break;
            case 3:
                Port = GPIO_PORTD_BASE;
                break;
            case 4:
                Port = GPIO_PORTE_BASE;
                break;
            case 5:
                Port = GPIO_PORTF_BASE;
                break;

            default:
                /* Handle invalid port */
                return; /* Return an invalid value */
     }

        /* Enable digital functionality on all pins in the port */
        (*((volatile uint32_t *)(Port + GPIO_O_DEN))) |= 0xFF;

        /* Set all pins as Output */
        (*((volatile uint32_t *)(Port + GPIO_O_DIR))) &= 0xFF;

        /* Write the level to the port */
        (*((volatile uint32_t *)(Port + GPIO_O_DATA))) = Level;

}
