#ifndef PORT_H
#define	PORT_H

//GPIO
#byte GP    = getenv("SFR:PORTA")

#ifdef EJEMPLO9
#define TRIS_A	0b00001110
#else
#define TRIS_A	0b00001100
#endif

#define PULLUPS_A	0b00001000

#bit LED2		= GP.0	//LED VERDE
#bit LED1		= GP.1	//LED ROJO
#define			POT	2
#bit BTN		= GP.3	//boton

#endif	/* PORT_H */

