#ifndef FUSES_H
#define	FUSES_H

// --- FUSES ---
//Oscilator Selection (FOSC bit 0)
#fuses INTRC	
//#fuses EC

//Brown-out Reset Enable (BOREN bit 1-2)
#fuses BROWNOUT
//#fuses NOBROWNOUT
//#fuses BROWNOUT_SW
//#fuses BROWNOUT_NOSL

//Watchdog Enable (WDTE bit 3-4)
#fuses NOWDT	
//#fuses WDT_SW
//#fuses WDT_NOSL
//#fuses WDT

//Power-up Timer Enable (PWRTE bit 5)
#fuses PUT		
//#fuses NOPUT

//MCLR-Vpp Pin Function Select (MCLRE bit 6)
#fuses NOMCLR	
//#fuses MCLR

//Code Protection (CP bit 7)
//#fuses PROTECT	
#fuses NOPROTECT

//Low-Voltage Programing Enabled (LVP bit 8)
#fuses NOLVP	
//#fuses LVP

//Low-Power Brown-out Reset Enable (LPBOR bit 9)
//#fuses LPBOR
#fuses NOLPBOR

//Brown-out Reset Voltage Selection (BORV bit 10)
//#fuses BORV25
#fuses BORV19

//Flash Memory Self-Write Protection (WRT bit 11-12)
#fuses NOWRT
//#fuses WRT
//#fuses WRT_50%
//#fuses WRT_25%

//Debug Mode
#fuses NODEBUG	
//#fuses DEBUG

#endif	/* FUSES_H */