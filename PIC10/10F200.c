#include <10F200.h>

#FUSES NOWDT,NOMCLR,PROTECT

#use delay(clock=4000000)
#use fast_io(b)

//GPIO
#byte GP    =  0x06

#bit X0		= GP.0
#bit X1		= GP.1
#define X2	PIN_A2
#bit X3		= GP.3

//Constantes

//Variables

//Rutinas
void Funcion(void);


void main() {
	setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);

	set_tris_b(0b00000000);

}
void Funcion(void){

}