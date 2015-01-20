/* 
 * File:   motor.c
 * Author: Joshua Lowe
 *
 * motor functions
 *
 * Created on December 6, 2014
 */

#include "motor.h"
#include <xc.h>

// FUNCTIONS
/* 
 * init_motor()
 * inputs: none			outputs:none
 * initializes port/bit which act as motor control
 * port/bit selected must be 5V tolerant.
 * see peripheral initialization template.
 */
void init_motor(){
    motor_state = 1;

    ODCE = 0xFFFF;
    PORTE = 0xFFFF;
    TRISE = 0xFFFF;
}