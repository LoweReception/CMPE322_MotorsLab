/*
 * File:    leds.c
 * Author:  Joshua Lowe
 *
 * Functions related to on-board LEDs
 *
 * Created on December 6, 2014, 4:30 PM
 */
#include "leds.h"
#include <xc.h>

/* init_leds()
 * inputs: none			outputs: none
 * initializes on-board leds as digital outputs.
 * see readme for template.
 */
void init_leds(){
    ODCBCLR = 0xFFFF;
    PORTB = 0x0;
    TRISB = 0x0;
}