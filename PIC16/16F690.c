//------------------------------------------------------------------------------
//                    TITULO PROYECTO
//
// Descripcion: 
//
// PIC: 16F690
//
//------------------------------------------------------------------------------

#include <16F690.h>
#device adc=8

#FUSES NOWDT		//No Watch Dog Timer
#FUSES INTRC_IO		//oscilador interno, pines CLK como I/O
#FUSES PUT			//Power up timer
#FUSES MCLR			//Un pin para el reset
#FUSES BROWNOUT		//reinicia por bajo voltage
#FUSES PROTECT		//code protected

#use delay(clock=8000000)     //clock de 8Mhz
#use fast_io(a)               //se accede al puerto a como memoria
#use fast_io(b)               //se accede al puerto b como memoria
#use fast_io(c)               //se accede al puerto c como memoria

//--- Constantes ---
#byte PORTA	= 0x05
#byte PORTB	= 0x06
#byte PORTC	= 0x07

#bit A0		= PORTA.0
#bit A1		= PORTA.1
#bit A2		= PORTA.2
#bit A3		= PORTA.3
#bit A4		= PORTA.4
#bit A5		= PORTA.5

#bit B4		= PORTB.4
#bit RX		= PORTB.5
#bit B6		= PORTB.6
#bit TX		= PORTB.7

#bit C0		= PORTC.0
#bit C1		= PORTC.1
#bit C2		= PORTC.2
#bit C3		= PORTC.3
#bit C4		= PORTC.4
#bit C5		= PORTC.5
#bit C6		= PORTC.6
#bit C7		= PORTC.7
//------------------

//--- Variables ---

//-----------------

#use rs232(baud=19200,xmit=PIN_B7,rcv=PIN_B5,parity=N,bits=8,stop=1)

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
#int_TIMER1
void TIMER1_isr(void) {
//Timer de 16 bits --> 65536 valores
//Clock 8Mhz --> 1 ciclo cada 0.5uS
//Pescaler de 1:1 --> 1 tick cada 0.5uS

}
// ---------------

void main(void) {
	
	setup_oscillator(OSC_8MHZ|OSC_INTRC);	//configura oscilador interno
	setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);//configuracion timer0
	setup_timer_1(T1_DISABLED);				//configuracion timer1
	setup_timer_2(T2_DISABLED,0,1);			//configuracion timer2
	setup_ccp1(CCP_OFF);					//configuracion CCP
	setup_adc(ADC_OFF);						//configuracion analogica
	setup_adc_ports(NO_ANALOGS);			//configuracion puerto analogico
	setup_spi(FALSE);						//configuracion SPI
	setup_comparator(NC_NC_NC_NC);			//comparador apagado
	setup_vref(FALSE);						//no se usa voltaje de referencia

	enable_interrupts(GLOBAL);			//habilita las interrupciones
	//enable_interrupts(INT_RTCC);		//habilita interrupcion 
	//enable_interrupts(INT_RB);			//habilita interrupcion 
	//enable_interrupts(INT_EXT);			//habilita interrupcion 
	//enable_interrupts(INT_AD);			//habilita interrupcion 
	//enable_interrupts(INT_TBE);			//habilita interrupcion 
	//enable_interrupts(INT_RDA);			//habilita interrupcion 
	//enable_interrupts(INT_TIMER0);		//habilita interrupcion timer0
	//enable_interrupts(INT_TIMER1);		//habilita interrupcion timer1
	//enable_interrupts(INT_TIMER2);		//habilita interrupcion timer2
	//enable_interrupts(INT_CCP1);		//habilita interrupcion 
	//enable_interrupts(INT_SSP);			//habilita interrupcion 
	//enable_interrupts(INT_EEPROM);		//habilita interrupcion 
	//enable_interrupts(INT_RA);			//habilita interrupcion 
	//enable_interrupts(INT_OSC_FAIL);	//habilita interrupcion 
	//enable_interrupts(INT_COMP);		//habilita interrupcion 
	//enable_interrupts(INT_COMP2);		//habilita interrupcion 
	//enable_interrupts(INT_RA0);			//habilita interrupcion 
	//enable_interrupts(INT_RA1);			//habilita interrupcion 
	//enable_interrupts(INT_RA2);			//habilita interrupcion 
	//enable_interrupts(INT_RA3);			//habilita interrupcion 
	//enable_interrupts(INT_RA4);			//habilita interrupcion 
	//enable_interrupts(INT_RA5);			//habilita interrupcion 
	//enable_interrupts(INT_RB4);			//habilita interrupcion 
	//enable_interrupts(INT_RB5);			//habilita interrupcion 
	//enable_interrupts(INT_RB6);			//habilita interrupcion 
	//enable_interrupts(INT_RB7);			//habilita interrupcion 
	
	port_a_pullups(0b00011111);		//pullups del puerto a
	port_b_pullups(0b11110000);		//pullups del puerto b
	set_tris_a(0b00011111);			//
	set_tris_b(0b11110000);			//
	set_tris_c(0b11111111);			//

	do{
	
	}while(true);
}
