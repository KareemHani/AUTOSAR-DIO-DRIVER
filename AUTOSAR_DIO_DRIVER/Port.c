/*
 * Port.c
 *
 *  Created on: Oct 7, 2023
 *      Author: Kareem Hani
 */
#include "Port.h"
#include "tm4c123gh6pm.h"

void Port_Init(void)
{
    SYSCTL_RCGCGPIO_R|=0x00000020;
    GPIO_PORTF_LOCK_R=0x4C4F434B;
    GPIO_PORTF_CR_R=0x1F;
    GPIO_PORTF_DIR_R=0X0E;
    GPIO_PORTF_PUR_R=0x11;
    GPIO_PORTF_DEN_R=0X1F;

}


