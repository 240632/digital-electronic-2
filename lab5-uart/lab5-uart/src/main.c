/***********************************************************************
 * 
 * Use USART unit and transmit data between ATmega328P and computer.
 * 
 * ATmega328P (Arduino Uno), 16 MHz, PlatformIO
 *
 * Copyright (c) 2018 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/


/* Defines -----------------------------------------------------------*/
#ifndef F_CPU
# define F_CPU 16000000  // CPU frequency in Hz required for UART_BAUD_SELECT
#endif


/* Includes ----------------------------------------------------------*/
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC
#include <uart.h>           // Peter Fleury's UART library
#include <stdlib.h>         // C library. Needed for number conversions


/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Use Timer/Counter1 and transmit UART data four times 
 *           per second.
 * Returns:  none
 **********************************************************************/
int main(void)
{
    // Initialize USART to asynchronous, 8N1, 9600
    uart_init(UART_BAUD_SELECT(9600, F_CPU));
    
    // Configure 16-bit Timer/Counter1 to transmit UART data
    // Set prescaler to 262 ms and enable overflow interrupt


    // Enables interrupts by setting the global interrupt mask
    sei();

    // Put strings to ringbuffer for transmitting via UART
    uart_puts("Ukaž ");
    uart_puts("kozy!!\r\n");


    TIM1_overflow_4ms();
    TIM1_overflow_interrupt_enable();
    // Infinite loop
    while (1)
    {
        /* Empty loop. All subsequent operations are performed exclusively 
         * inside interrupt service routines ISRs */
    }

    // Will never reach this
    return 0;
}

/* Interrupt service routines ----------------------------------------*/
/**********************************************************************
 * Function: Timer/Counter1 overflow interrupt
 * Purpose:  Transmit UART data four times per second.
 **********************************************************************/

/*
ISR(TIMER1_OVF_vect)
{   static uint8_t no_of_overflows = 0;   
    no_of_overflows++;
    if (no_of_overflows >= 10)
    {
        uart_puts("Penis ");
        uart_puts("\r\n");
        no_of_overflows=0;

    }
    }
*/
ISR(TIMER1_OVF_vect)
{
    // Transmit UART string(s)
    // uart_puts("Paris\r\n");

    uint8_t value;
    uint8_t even = 0;
    char string[8];  // String for converted numbers by itoa()

    value = uart_getc();
    if (value != '\0') {  // Data available from UART
        // Display ASCII code of received character
        // WRITE YOUR CODE HERE
        uart_putc(value);
        uart_puts("\t");
        uart_puts("\x1b[4;32m");
        itoa(value, string, 10);
        uart_puts(string);

        uart_puts("\tpořadí cecků ");
        uart_puts("\x1b[4;16m");
        itoa(value, string, 2);
        uart_puts(string);


        for (uint8_t i = 0; i < 8; i++) {
            even = even ^ (value & 0x01);
            value = value >> 1;
        }
        uart_puts("\tPočet varlat: ");
        
        itoa(even, string, 10);
        uart_puts(string);
        uart_puts("\n");

    }

}