/* 
 * File:   timer.h
 * Author: jl2582
 *
 * Contains timer macros and prototypes
 * Timer 2 is chosen as designated timer for motor control
 *
 * Created on December 6, 2014, 4:29 PM
 */

#include "system.h"

#ifndef TIMER_H
#define	TIMER_H

#ifdef	__cplusplus
extern "C" {
#endif

// MACROS
/*
 * MOTOR_TIMER_ON -> turns timer2 on
 * MOTOR_TIMER_OFF -> turns timer2 off
 * MOTOR_TIMER_1MS -> value of 1 ms in ticks of timer2
 * MOTOR_TIMER_PRESCALER -> prescaler for timer2
 */
#define MOTOR_TIMER_ON          T2CONSET = 0x8000
#define MOTOR_TIMER_OFF         T2CONCLR = 0x8000
#define MOTOR_TIMER_1MS         (PB_CLK / 1000 / MOTOR_TIMER_PRESCALER)
#define MOTOR_TIMER_PRESCALER   32

    // EXTERNS
    extern int duty_cycle;      // global -> length of logic 1 portion of period
    extern int motor_state;     // global -> indicates whether motor on/off

    // FUNCTIONS
    /*
     * init_motor_timer()
     * inputs: none         outputs: none
     * initializes peripherals needed to control motor
     */
    void init_motor_timer();


#ifdef	__cplusplus
}
#endif

#endif	/* TIMER_H */

