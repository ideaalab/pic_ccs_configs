#include <16F648A.h>

#FUSES XT,INTRC_IO,NOWDT,PUT,NOMCLR,NOBROWNOUT,NOLVP,NOCPD,NOPROTECT

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
#bit X		= PORTA.5
#bit X		= PORTA.6
#bit X		= PORTA.7

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

#use rs232(baud=19200,xmit=TX,rcv=RX)

//Variables

//Rutinas
void Funcion(void);

#int_EXT
void INT_EXT_isr(void){

}

#int_TIMER1
void TIMER1_isr(void){
//Timer de 16 bits --> 65536 = 1 RTCC
//Pescaler de 1:x
//1 tick cada x uS

}

void main() {
	setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
	setup_timer_1(T1_INTERNAL|T1_DIV_BY_1);
	setup_timer_2(T2_DISABLED,0,1);
	setup_ccp1(CCP_COMPARE_INT);
	setup_comparator(NC_NC_NC_NC);
	setup_vref(FALSE);

	enable_interrupts(INT_TIMER0);
	enable_interrupts(INT_TIMER1);
	enable_interrupts(INT_TIMER2);
	enable_interrupts(INT_EXT);
	enable_interrupts(INT_CCP1);
	enable_interrupts(INT_RB);
	enable_interrupts(INT_EEPROM);
	enable_interrupts(INT_OSC_FAIL);
	enable_interrupts(GLOBAL);

	setup_oscillator(OSC_4MHZ);
	set_tris_a(0b00000000);
	set_tris_b(0b00000000);
	ext_int_edge(0,H_TO_L);	//configura INT para que solo se active a la bajada
	
	do{
		
	}while(TRUE);

}
void Funcion(void){

}