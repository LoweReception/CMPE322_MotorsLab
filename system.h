/* 
 * File:   system.h
 * Author: Joshua Lowe
 *
 * Contains system information
 *
 * Created on December 7, 2014, 8:26 PM
 */

#ifndef SYSTEM_H
#define	SYSTEM_H

#ifdef	__cplusplus
extern "C" {
#endif

// MACROS
/*
 * System clock defined as 80 MHz
 * Peripheral Bus clock defined as 10 MHz
*/
#define SYS_CLK     80000000
#define PB_CLK      (SYS_CLK / 8)

#ifdef	__cplusplus
}
#endif

#endif	/* SYSTEM_H */

