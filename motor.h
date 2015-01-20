/* 
 * File:   motor.h
 * Author: jl2582
 *
 * Created on December 6, 2014,
 */

#ifndef MOTOR_H
#define	MOTOR_H

#ifdef	__cplusplus
extern "C" {
#endif

// MACROS
/*
 * MOTOR_CONTROL -> SFR/bit combo to pin which controls motor (5V tolerant)
 * MOTOR_ON -> sets MOTOR_CONTROL bit
 * MOTOR_OFF -> clears MOTOR_CONTROL bit
 */
#define MOTOR_CONTROL   PORTEbits.RE4
#define MOTOR_ON        PORTEbits.RE4 = 1;
#define MOTOR_OFF       PORTEbits.RE4 = 0;

    // EXTERNS
    extern int motor_state;     // global var which indicates motor on/off

    // FUNCITONS
    void init_motor();          // Initialized motor control pin


#ifdef	__cplusplus
}
#endif

#endif	/* MOTOR_H */

