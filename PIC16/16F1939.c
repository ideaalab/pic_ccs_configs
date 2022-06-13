#include <16F1939.h>
#device adc=8

// --- FUSES ---
// CONF WORD 1

//Oscilator Selection (FOSC bit 0-2)
//#fuses LP
//#fuses XT
//#fuses HS
//#fuses RC
#fuses INTRC_IO
//#fuses ECL
//#fuses ECM
//#fuses ECH

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

//Data Code Protection (CPD bit 8)
//#fuses CPD
#fuses NOCPD

//Brown-out Reset Enable (BOREN bit 9-10)
#fuses BROWNOUT
//#fuses NOBROWNOUT
//#fuses BROWNOUT_SW
//#fuses BROWNOUT_NOSL

//Clock Out Enable (CLOCKOUTEN bit 11)
//#fuses CLKOUT
#fuses NOCLKOUT

//Internal External Switchover (IESO bit 12)
//#fuses IESO
#fuses NOIESO

//Fail Safe Clock Monitor (FCMEN bit 13)
//#fuses FCMEN
#fuses NOFCMEN

//CONF WORD 2

//Flash Memory Self-Write Protection (WRT bit 0-1)
#fuses NOWRT
//#fuses WRT
//#fuses WRT_200
//#fuses WRT_2000

//Voltage Regulator Capacitor (VCAPEN bit 4-5)
//#fuses VCAP_A0
//#fuses VCAP_A5
//#fuses VCAP_A6
#fuses NOVCAP

//PLL Enable (PLLEN bit 8)
#fuses PLL_SW
//#fuses PLL

//Stack Overflow/Underflow Reset (STVREN bit 9)
#fuses NOSTVREN
//#fuses STVREN

//Brown-out Reset Voltage Selection (BORV bit 10)
//#fuses BORV27
#fuses BORV24

//In-Circuit Debug Mode (DEBUG bit 12)
#fuses NODEBUG	
//#fuses DEBUG

//Low-Voltage Programing Enabled (LVP bit 13)
#fuses NOLVP	
//#fuses LVP
// --- FUSES ---

#use delay(clock=32000000)    //clock de 32Mhz

#use fast_io(a)               //se accede al puerto a como memoria
#use fast_io(b)               //se accede al puerto b como memoria
#use fast_io(c)               //se accede al puerto c como memoria
#use fast_io(d)               //se accede al puerto d como memoria
#use fast_io(e)               //se accede al puerto e como memoria

//--- Constantes ---
#byte PORTA	= 0x0C
#byte PORTB	= 0x0D
#byte PORTC	= 0x0E
#byte PORTD	= 0x0F
#byte PORTE	= 0x10

#define TX	PIN_A0
#define RX	PIN_A1
#bit A2		= PORTA.2
#bit A3		= PORTA.3
#bit A4		= PORTA.4
#bit A5		= PORTA.5
#bit A6		= PORTA.6
#bit A7		= PORTA.7

#bit B0		= PORTB.0
#bit B1		= PORTB.1
#bit B2		= PORTB.2
#bit B3		= PORTB.3
#bit B4		= PORTB.4
#bit B5		= PORTB.5
#bit B6		= PORTB.6
#bit B7		= PORTB.7

#bit C0		= PORTC.0
#bit C1		= PORTC.1
#bit C2		= PORTC.2
#bit C3		= PORTC.3
#bit C4		= PORTC.4
#bit C5		= PORTC.5
#bit C6		= PORTC.6
#bit C7		= PORTC.7

#bit D0		= PORTD.0
#bit D1		= PORTD.1
#bit D2		= PORTD.2
#bit D3		= PORTD.3
#bit D4		= PORTD.4
#bit D5		= PORTD.5
#bit D6		= PORTD.6
#bit D7		= PORTD.7

#bit E0		= PORTE.0
#bit E1		= PORTE.1
#bit E2		= PORTE.2
//------------------

//--- Variables ---

//-----------------

#use rs232(baud=9600, xmit=TX,rcv=RX)
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
	
	setup_wdt(WDT_OFF);						//configuracion wdt
	setup_timer_0(T0_INTERNAL|RTCC_DIV_1);	//configuracion timer0
	setup_timer_1(T1_INTERNAL|T1_DIV_BY_1);	//configuracion timer1
	setup_timer_2(T2_DISABLED,0,1);			//configuracion timer2
	setup_timer_4(T2_DISABLED,0,1);			//configuracion timer4
	setup_timer_6(T2_DISABLED,0,1);			//configuracion timer6
	setup_dac(DAC_OFF);						//configura DAC
	setup_adc(ADC_OFF);						//configura ADC
	setup_ccp1(CCP_OFF);					//configura CCP
	setup_ccp2(CCP_OFF);					//configura CCP
	setup_ccp3(CCP_OFF);					//configura CCP
	setup_ccp4(CCP_OFF);					//configura CCP
	setup_ccp5(CCP_OFF);					//configura CCP
	setup_spi(FALSE);						//configura SPI
	setup_comparator(NC_NC_NC_NC);			//comparador apagado
	setup_vref(FALSE);						//no se usa voltaje de referencia
	
	ext_int_edge(L_TO_H);					//configura int ext
	
	enable_interrupts(INT_TIMER0);			//timer0 overflow
	enable_interrupts(INT_TIMER1);			//timer1 overflow
	enable_interrupts(INT_TIMER2);			//timer2 overflow
	enable_interrupts(INT_EXT);				//interrupcion externa
	enable_interrupts(INT_AD);				//conversion ADC completa
	enable_interrupts(INT_RDA);				//recepcion USART (recieved data available)
	enable_interrupts(INT_TBE);				//buffer USART vacio (transmit buffer empty)
	enable_interrupts(INT_SSP);				//actividad I2C o SPI
	enable_interrupts(INT_CCP1);			//interrupcion por captura o comparacion
	enable_interrupts(INT_OSC_FAIL);		//fallo en oscilador
	enable_interrupts(INT_COMP);			//comparador analogico
	enable_interrupts(INT_EEPROM);			//escritura eeprom completa
	enable_interrupts(INT_BUSCOL);			//colision en bus MSSP
		
	enable_interrupts(GLOBAL);				//habilita las interrupciones
	setup_oscillator(OSC_16MHZ|OSC_INTRC|OSC_PLL_ON);	//configura oscilador interno
	
	set_tris_a(0x00);					//
	set_tris_b(0x00);					//
	set_tris_c(0x00);					//
	set_tris_d(0x00);					//
	set_tris_e(0x00);					//

	do{
	
	}while(true);
}