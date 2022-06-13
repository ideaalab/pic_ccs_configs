#include <16F84A.h>

#FUSES XT,NOWDT,NOPROTECT

#use delay(clock=4000000)
#use fast_io(a)
#use fast_io(b)

//GPIO
#byte PORTA    =  0x05
#byte PORTB		= 0x06

#bit X		= PORTA.0
#bit X		= PORTA.1
#bit X		= PORTA.2
#bit X		= PORTA.3
#bit X		= PORTA.4
//#bit MCLR		= PORTA.5

#bit X		= PORTB.0
#bit X		= PORTB.1
#bit X		= PORTB.2
#bit X		= PORTB.3
#bit X		= PORTB.4
#bit X		= PORTB.5
#bit X		= PORTB.6
#bit X		= PORTB.7
//#define X	PIN_B7

//Constantes

//Variables

//Rutinas
void Funcion(void);

#int_EXT
void INT_EXT_isr(void){

}

#int_TIMER0
void TIMER0_isr(void){
//Timer de 8 bits --> 256 = 1 RTCC
//Pescaler de 1:x
//1 tick cada x uS

}

void main() {
	setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
	ext_int_edge(0,H_TO_L);	//configura INT para que solo se active a la bajada

	enable_interrupts(INT_TIMER0);
	enable_interrupts(INT_EXT);
	enable_interrupts(INT_RB);
	enable_interrupts(GLOBAL);

	set_tris_a(0b00000000);
	set_tris_b(0b00000000);
	
	do{
		
	}while(TRUE);

}

void Funcion(void){

}