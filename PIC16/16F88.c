//------------------------------------------------------------------------------
//                    TITULO PROYECTO
//
// Descripcion: 
//
// PIC: 16F88
//
//------------------------------------------------------------------------------

#include <16F88.h>
#device adc=8

#FUSES NOWDT		//No Watch Dog Timer
#FUSES INTRC_IO		//oscilador interno, pines CLK como I/O
#FUSES PUT			//Power up timer
#FUSES MCLR			//Un pin para el reset
#FUSES NOLVP		//no low voltage programing

#use delay(clock=8000000)     //clock de 8Mhz
#use fast_io(a)               //se accede al puerto a como memoria
#use fast_io(b)               //se accede al puerto b como memoria

//--- Constantes ---

//------------------

//--- Variables ---

//-----------------

// --- Timer 0 ---
#int_TIMER0
void TIMER0_isr(void) {
//Timer de 8 bits --> 256 valores
//Clock 8Mhz --> 1 ciclo cada 0.5uS
//Prescaler de 1:1 --> 1 tick cada 0.5uS
//Set_timer0(0) --> Overflow cada 128uS

}
// ---------------

// --- Timer 1 ---
#int_TIMER1 //timer control de servo
void TIMER1_isr(void) {
//Timer de 16 bits --> 65536 valores
//Clock 8Mhz --> 1 ciclo cada 0.5uS
//Pescaler de 1:1 --> 1 tick cada 0.5uS

}
// ---------------

void main(void) {
	
	setup_adc_ports(NO_ANALOGS|VSS_VDD);      //no hay entradas analogicas
	setup_adc(ADC_OFF);                       //adc apagado
	setup_spi(FALSE);
	setup_timer_0(RTCC_INTERNAL|RTCC_DIV_8);  //configuracion timer0
	setup_timer_1(T1_INTERNAL|T1_DIV_BY_2);   //configuracion timer1
	setup_timer_2(T2_DISABLED,0,1);           //timer2 apagado
	setup_comparator(NC_NC_NC_NC);            //comparador apagado
	setup_vref(FALSE);                        //no se usa voltaje de referencia
	enable_interrupts(INT_TIMER1);            //habilita interrupcion timer1
	enable_interrupts(GLOBAL);                //habilita las interrupciones
	setup_oscillator(OSC_8MHZ|OSC_INTRC);     //configura oscilador interno
	set_tris_a(0x00);                         //
	set_tris_b(0x00);                         //

	do{
	
	}while(true);
}
