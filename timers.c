/*
 * File: timers.c
 * Author: Joshua Lowe
 *
 * motor timer functions and ISRs
 *
 * Created on December 6, 2014
 */
#include "timers.h"
#include "motor.h"
#include <xc.h>
#include <plib.h>

// FUCTIONS
/* init_motor_timer()
 * inputs: none			outputs: none 
 * initializes timer2 and sets appropriate related SFRs
 * this initialization functions differs from the others because 
 * the timer uses interrupts, thus the corresponding interrupt 
 * register must be set up.
 */
void init_motor_timer(){
    T2CON = 0x0;            		// clear T2 configuration reg
    TMR2 = 0x0;             		// clear T2 counter register
    T2CON =  0x50;         			// set T2 prescaler = 32, 16bit mode, pbclk
    PR2 =  10 * MOTOR_TIMER_1MS;    // set T2 period to 10Ms

    // T2 interrupt vector = 8
    IPC2SET = 0xD;          // priority = 3, sub-priority = 1
    IFS0CLR = 0x100;        // clear T2 flag status
    IEC0SET = 0x100;        // enable T2 interrupts
}

// ISR
/* 
 * timer2_ISR()
 * inputs: none 			outputs: none
 * this ISR is called whenever t2_period = t2_count
 */
void __ISR(_TIMER_2_VECTOR,IPL3)Timer2Handler(void){
    MOTOR_TIMER_OFF;            // turn off timer
    TMR2 = 0x0;                 // clear T2 count register
    if (motor_state) {          // on -> off state transition
        PR2 = (10 - duty_cycle) * MOTOR_TIMER_1MS;
        MOTOR_OFF;
        motor_state = 0;
    }
    else {                      // off -> on state transition
        PR2 = duty_cycle * MOTOR_TIMER_1MS;
        MOTOR_ON;
        motor_state = 1;
    }
    MOTOR_TIMER_ON;  			// turn on motor timer
    IFS0CLR = 0x100;            // clear T2 interrupt flag
}