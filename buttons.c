/*
 * File:    buttons.c
 * Author:  Joshua Lowe
 *
 * Functions related to on-board buttons
 *
 * Created on December 6, 2014, 4:05 PM
 */

#include <xc.h>
#include "buttons.h"

/* init_buttons()
 * inputs: none        outputs: none
 * initializes on-board buttons as digital input, results occur in PORTx SFR. 
 */
void init_buttons(){
    ODCACLR = 0xFFFF;   // clears PORTA ODC SFR
    PORTA = 0x0;        // clears PORTA to transmit logic low
    TRISA = 0xFFFF;     // sets PORTA TRIS SFR to input
}

/* 
 * get_buttonX();
 * input: none          outputs: state of button (boolean)
 * checks and returns the state of the specified button
 * contains debouncing function for error detection.
 *
 * Button1 and Button2 are identical with the exception being the bit which button
 * the function checks. See header file for definitions of BUTTONx.
 * 
 * Only get_button1() is commented for the above reason.
 */
int get_button1(){
    int i = 0;              // iterator
    int btn_shadow;         // shadow "register"( bit), follows physical button state.

    // simple debounce function
    while ( i < DEBOUNCE_TIME){         // while still within debounce period
        btn_shadow = BUTTON1;           // set shadow = physical button state
        // while still in debounce period, if shadow and physical differ,
        // restart debounce iteration.
        for (i = 0; i < DEBOUNCE_TIME; i++){
            if (BUTTON1 != btn_shadow)  break;
        }
    }
    // while exits only when shadow = physical for longer than debounce time.

    // returns shadow because it repressents the state when function was called.
    return btn_shadow;
}
int get_button2(){
    int i = 0;
    int btn_shadow;

    while ( i < DEBOUNCE_TIME){
        btn_shadow = BUTTON2;
        for (i = 0; i < DEBOUNCE_TIME; i++){
            if (BUTTON2 != btn_shadow)  break;
        }
    }
    return btn_shadow;
}
