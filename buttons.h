/* 
 * File:   buttons.h
 * Author: Joshua Lowe
 *
 * Contains function prototypes and macros related to on-board buttons
 *
 * Created on December 6, 2014, 3:51 PM
 */

#ifndef BUTTONS_H
#define	BUTTONS_H

#ifdef	__cplusplus
extern "C" {
#endif
    
// MACROS
/*
 * DEBOUNCE TIME -> used in the debounce function, its notes the number
 *      of sys_clk cycles to account of physical debounce in the buttons
 * BUTTON1 & BUTTON2 -> SFR/bit combination for the buttons of the board.
 */
#define DEBOUNCE_TIME    150
#define BUTTON1          PORTAbits.RA6
#define BUTTON2          PORTAbits.RA7

/* init_buttons()
 * inputs: none        outputs: none
 * initializes on-board buttons.
 */
    void init_buttons();

/* get_buttonX();
 * input: none          outputs: state of button (boolean)
 * checks and returns the state of the specified button
 * contains debouncing function for error detection.
 */
    int get_button1();
    int get_button2();

#ifdef	__cplusplus
}
#endif

#endif	/* BUTTONS_H */

