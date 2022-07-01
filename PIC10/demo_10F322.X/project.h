#ifndef PROJECT_H
#define	PROJECT_H

#include <10F322.h>

#device adc=8
#use delay(clock=2000000)

#include "fuses.h"
#include "port.h"

#ifndef T2_DIV_BY_64
#define T2_DIV_BY_64        7	//este define no esta declarado en header ¿?
#endif

/* REGISTROS */
//#bit VREGPM1	= getenv("BIT:VREGPM1")	//Voltage Regulator Power Mode Selection bit
#byte VREGCON	= getenv("SFR:VREGCON")		//Voltage Regulator Control Register
#bit VREGPM1	= VREGCON.1				//Voltage Regulator Power Mode Selection bit

//Defines para cada ejemplo, descomentar el que se quiera usar
#define EJEMPLO10

//#define EJEMPLO1	//Encender LEDs
//#define EJEMPLO2	//Usar potenciometro
//#define EJEMPLO3	//Pulsador
//#define EJEMPLO4	//Grabar en HEF
//#define EJEMPLO5	//GRabar en HEF con potenciometro
//#define EJEMPLO6	//PWM LED
//#define EJEMPLO7	//Servo
//#define EJEMPLO8	//Leer varios valores de HEF
//#define EJEMPLO9	//Lee valores de HEF y los envia por serial
//#define EJEMPLO10	//Sleep

#define ADDRESS_TO_USE_FOR_STORAGE 0x1F0 //This is the high endurance flash - 0xF8 for 10F320 
//#ROM int16 ADDRESS_TO_USE_FOR_STORAGE = {0x1fff,0x2fff,0x3fff,0x1fff,0x2fff,0x3fff,0x1fff} //Preload the HEF
#ROM ADDRESS_TO_USE_FOR_STORAGE = {1,2,3,1,2,3,1} //Preload the HEF

#ifdef EJEMPLO9
#use rs232(baud=9600, xmit=PIN_A0,rcv=PIN_A1)
#endif

#endif	/* PROJECT_H */

