/* 
 * File:   main.c
 * Author: Joshua Lowe
 *
 * Created on December 6, 2014, 3:50 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <plib.h>

#include "buttons.h"
#include "leds.h"
#include "timers.h"
#include "motor.h"

// PIC32MX460F512L Configuration Bit Settings
// 'C' source line config statements

// DEVCFG3
// USERID = No Setting

// DEVCFG2
#pragma config FPLLIDIV = DIV_2         // PLL Input Divider (2x Divider)
#pragma config FPLLMUL = MUL_20         // PLL Multiplier (21x Multiplier)
#pragma config UPLLIDIV = DIV_12        // USB PLL Input Divider (12x Divider)
#pragma config UPLLEN = OFF             // USB PLL Enable (Disabled and Bypassed)
#pragma config FPLLODIV = DIV_1       // System PLL Output Clock Divider (PLL Divide by 1)

// DEVCFG1
#pragma config FNOSC = FRCPLL           // Oscillator Selection Bits (Fast RC Osc with PLL)
#pragma config FSOSCEN = ON             // Secondary Oscillator Enable (Enabled)
#pragma config IESO = ON                // Internal/External Switch Over (Enabled)
#pragma config POSCMOD = OFF            // Primary Oscillator Configuration (Primary osc disabled)
#pragma config OSCIOFNC = ON            // CLKO Output Signal Active on the OSCO Pin (Enabled)
#pragma config FPBDIV = DIV_8           // Peripheral Clock Divisor (Pb_Clk is Sys_Clk/8)
#pragma config FCKSM = CSDCMD           // Clock Switching and Monitor Selection (Clock Switch Disable, FSCM Disabled)
#pragma config WDTPS = PS1048576        // Watchdog Timer Postscaler (1:1048576)
#pragma config FWDTEN = ON              // Watchdog Timer Enable (WDT Enabled)

// DEVCFG0
#pragma config DEBUG = OFF              // Background Debugger Enable (Debugger is disabled)
#pragma config ICESEL = ICS_PGx2        // ICE/ICD Comm Channel Select (ICE EMUC2/EMUD2 pins shared with PGC2/PGD2)
#pragma config PWP = OFF                // Program Flash Write Protect (Disable)
#pragma config BWP = OFF                // Boot Flash Write Protect bit (Protection Disabled)
#pragma config CP = OFF                 // Code Protect (Protection Disabled)

// MACROS
/*
 * DUTY_CYCLE_MAX -> maximum length of duty cycle in ms.
 * DUTY_CYCLE_MIN -> minimum length of duty cycle in ms.
 */
#define DUTY_CYCLE_MAX      5
#define DUTY_CYCLE_MIN      1

// GLOBALS
/*
 * duty_cycle -> length of current duty cycle of motor in ms. 
 * motor_state -> indicates state of motor (on or off)
 */
int duty_cycle;
int motor_state;

int main(int argc, char** argv) {

    duty_cycle = 3;		// initial value as dictated by project desc.

	// PERIPHERAL INITALIZATION
    init_buttons();
    init_leds();
    init_motor();
    init_motor_timer();

    // START SYSTEM
    MOTOR_ON;				// turn on motor
    // motor_state = 1;		// sets global to motor state  <- instr in init_motor()
    MOTOR_TIMER_ON;         // start timer
    
	// INTERRUPT INITALIZATION
    INTConfigureSystem(INT_SYSTEM_CONFIG_MULT_VECTOR);
    INTEnableSystemMultiVectoredInt(); // Enable the interrupt handling from the core

	// MAIN FUNCTIONALITY
	/* When BUTTONx is pressed:
	 *		turn of all leds
	 *		call get_buttonX(), if true:
	 *      	if true: turn on corresponding LED, inc/dec duty cycle
	 *			else: do nothing
	 *		else: do nothing
	 *		while button is still depressed, busy-wait.
	 *		turn off all leds except for corresponding
	 *
	 *		button1 increases duty_cyclem, button2 decreases duty_cycle.
	 */
    while(1){
        if (BUTTON1){
            PORTBCLR = 0xF00;
            if (get_button1()) {
                PORTBSET = 0x400;
                if (duty_cycle < DUTY_CYCLE_MAX) duty_cycle++;
                else duty_cycle = DUTY_CYCLE_MAX;
            }
            else ;
            while (BUTTON1){;}
            PORTBCLR = 0xF00;
        }
        if (BUTTON2){
            PORTBCLR = 0xF00;
            if (get_button2()){
                if (duty_cycle > DUTY_CYCLE_MIN) duty_cycle--;
                else duty_cycle = DUTY_CYCLE_MIN;
                PORTBSET = 0x800;
            }
            else ;
            while (BUTTON2){;}
            PORTBCLR = 0xF00;
        }
    }

    return (EXIT_SUCCESS);
}