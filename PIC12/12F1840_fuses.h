/* 
 * File:   fuses.h
 * Author: Martin
 *
 * Created on 24 de diciembre de 2016, 14:02
 */

#ifndef FUSES_H
#define	FUSES_H

/* Oscillator Selection */
//#FUSES LP			//Low-power crystal connected between OSC1 and OSC2 pins
//#FUSES XT			//Crystal/resonator connected between OSC1 and OSC2 pins
//#FUSES HS			//High-speed crystal/resonator connected between OSC1 and OSC2 pins
//#FUSES RC			//External RC circuit connected to CLKIN pin
#FUSES INTRC_IO		//I/O function on CLKIN pin
//#FUSES ECL		//External Clock, Low-Power mode (0-0.5 MHz): device clock supplied to CLKIN pin
//#FUSES ECM		//External Clock, Medium-Power mode (0.5-4 MHz): device clock supplied to CLKIN pin
//#FUSES ECH		//External Clock, High-Power mode (4-20 MHz): device clock supplied to CLKIN pin

/* Watchdog Timer Enable */
#FUSES NOWDT		//WDT disabled
//#FUSES WDT_SW		//WDT controlled by software
//#FUSES WDT_NOSL	//WDT enabled while running and disabled in Sleep
//#FUSES WDT		//WDT enabled

/* Power-up Timer Enable */
#FUSES PUT			//PWRT enabled
//#FUSES NOPUT		//PWRT disabled

/* MCLR/VPPPin Function */
#FUSES NOMCLR		//MCLR/VPP pin function is digital input.
//#FUSES MCLR			//MCLR/VPP pin function is MCLR; Weak pull-up enabled.

/* Code Protection */
#FUSES PROTECT		//Program memory code protection is enabled
//#FUSES NOPROTECT	//Program memory code protection is disabled

/* Data Code Protection */
//#FUSES CPD			//Data memory code protection is enabled
#FUSES NOCPD		//Data memory code protection is disabled

/* Brown-out Reset Enable */
//#FUSES NOBROWNOUT	//BOR disabled
//#FUSES BROWNOUT_SW	//BOR controlled by software
#FUSES BROWNOUT_NOSL	//BOR enabled during operation and disabled in Sleep
//#FUSES BROWNOUT		//BOR enabled

/* Clock Out Enable */
//#FUSES CLKOUT		//CLKOUT function is enabled on the CLKOUT pin
#FUSES NOCLKOUT		//CLKOUT function is disabled. I/O function on the CLKOUT pin.

/* Internal External Switchover */
#FUSES NOIESO		//Internal/External Switchover mode is disabled
//#FUSES IESO			//Internal/External Switchover mode is enabled

/* Fail-Safe Clock Monitor Enable */
#FUSES NOFCMEN		//Fail-Safe Clock Monitor is disabled
//#FUSES FCMEN		//Fail-Safe Clock Monitor is enabled

/* Flash Memory Self-Write Protection */
//#FUSES WRT			//000h to FFFh write-protected, no addresses may be modified
//#FUSES WRT_800		//000h to 7FFh write-protected, 800h to FFFh may be modified
//#FUSES WRT_200		//000h to 1FFh write-protected, 200h to FFFh may be modified
#FUSES NOWRT		//Write protection off

/* PLL Enable */
#FUSES PLL_SW		//4xPLL disabled (can be enabled by software)
//#FUSES PLL			//4xPLL enabled

/* Stack Overflow/Underflow Reset Enable */
#FUSES NOSTVREN		//Stack Overflow or Underflow will not cause a Reset
//#FUSES STVREN		//Stack Overflow or Underflow will cause a Reset

/* Brown-out Reset Voltage Selection */
#FUSES BORV25		//Brown-out Reset voltage (Vbor), high trip point selected
//#FUSES BORV19		//Brown-out Reset voltage (Vbor), low trip point selected

/* In-Circuit Debugger Mode */
//#FUSES DEBUG		//In-Circuit Debugger enabled, ICSPCLK and ICSPDAT are dedicated to the debugger
#FUSES NODEBUG		//In-Circuit Debugger disabled, ICSPCLK and ICSPDAT are general purpose I/O pins

/* Low-Voltage Programming Enable */
#FUSES NOLVP		//High-voltage on MCLRmust be used for programming
//#FUSES LVP			//Low-voltage programming enabled 

#endif	/* FUSES_H */