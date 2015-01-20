/* 
 * File:   leds.h
 * Author: Joshua Lowe
 *
 * Contains function prototypes and macros related to LEDS
 *
 * Created on December 6, 2014, 4:02 PM
 */

#ifndef LEDS_H
#define	LEDS_H

// MACROS
/*
 * LEDx -> SFR/bit combination for on-board LEDS
 */
#define LED1    PORTBbits.RB10
#define LED2    PORTBbits.RB11
#define LED3    PORTBbits.RB12
#define LED4    PORTBbits.RB13


#ifdef	__cplusplus
extern "C" {
#endif

    // FUNCTIONS
    /* init_leds()
     * inputs: none         outputs: none
     * initializes on-board LEDS
     */
   void init_leds();

#ifdef	__cplusplus
}
#endif

#endif	/* LEDS_H */

