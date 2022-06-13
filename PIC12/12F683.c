#include <12F683.h>
#device adc=8

#FUSES NOWDT,NOMCLR,PUT,INTRC_IO,PROTECT

#use delay(clock=8000000)
#use fast_io(a)

//GPIO
#byte GP    =  0x05

#bit X		= GP.0
#bit X		= GP.1
#define X	PIN_A2
#bit X		= GP.3
#define X	PIN_A4
#define X	PIN_A5

//Constantes

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
//x tick cada x uS

}

void main() {
	setup_adc_ports(sAN0|VSS_VDD);
	setup_adc(ADC_CLOCK_INTERNAL);
	setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
	setup_timer_1(T1_INTERNAL|T1_DIV_BY_1);
	setup_timer_2(T2_DISABLED,0,1);
	setup_ccp1(CCP_COMPARE_INT);
	setup_comparator(NC_NC);
	setup_vref(FALSE);

	enable_interrupts(INT_TIMER0);
	enable_interrupts(INT_TIMER1);
	enable_interrupts(INT_TIMER2);
	enable_interrupts(INT_EXT);
	enable_interrupts(INT_CCP1);
	enable_interrupts(INT_RA);
	enable_interrupts(INT_EEPROM);
	enable_interrupts(INT_AD);
	enable_interrupts(INT_OSC_FAIL);
	enable_interrupts(GLOBAl);

	setup_oscillator(OSC_8MHZ);
	set_tris_a(0b00000000);
	set_adc_channel(ADC);
	ext_int_edge(0,H_TO_L);	//configura INT para que solo se active a la bajada

}
void Funcion(void){

}