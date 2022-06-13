//------------------------------------------------------------------------------
//                    TITULO PROYECTO
//
// Descripcion: 
//
// PIC: 12F1840
//
//------------------------------------------------------------------------------

#include <12F1840.h>
#device adc=8

#FUSES NOFCMEN		//NO fail safe clock monitor
#FUSES NOIESO		//NO internal external switchover
#FUSES NOBROWNOUT	//NO brownout reset
#FUSES NOCPD		//NO eeprom protegido de lecturas
#FUSES NOPROTECT	//NO codigo protegido de lecturas
#FUSES NOMCLR		//NO mclr
#FUSES PUT			//power up timer
#FUSES NOWDT		//NO watch dog timer
#FUSES INTRC_IO		//oscilador interno, pines CLK como I/O
#FUSES PLL_SW		//PLL controlado en SW

#use delay(clock=16000000)    //clock de 16Mhz
#use fast_io(a)               //se accede al puerto a como memoria

//--- Constantes ---
#byte PORTA	= 0x0C

#define TX	PIN_A0
#define RX	PIN_A1
#bit A2		= PORTA.2
#bit A3		= PORTA.3
#bit A4		= PORTA.4
#bit A5		= PORTA.5

#define TRIS_A	0b00111111	//define cuales son entradas y cuales salidas
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
	setup_timer_2(T2_DISABLED,255,1);		//configuracion timer2
	setup_dac(DAC_OFF);						//configura DAC
	setup_adc(ADC_OFF);						//configura ADC
	setup_ccp1(CCP_OFF);					//configura CCP
	setup_spi(SPI_DISABLED);				//configura SPI
	//setup_uart(FALSE);					//configura UART
	setup_comparator(NC_NC);				//comparador apagado
	setup_vref(VREF_OFF);					//no se usa voltaje de referencia
	
	ext_int_edge(L_TO_H);					//configura int ext
	
	enable_interrupts(INT_TIMER0);			//timer0 overflow
	enable_interrupts(INT_TIMER1);			//timer1 overflow
	enable_interrupts(INT_TIMER2);			//timer2 overflow
	enable_interrupts(INT_EXT);				//interrupcion externa
	enable_interrupts(INT_RA);				//interrupcion por cambio de estado
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
	setup_oscillator(OSC_16MHZ|OSC_INTRC|OSC_PLL_OFF);	//configura oscilador interno
	
	set_tris_a(TRIS_A);					//

	do{
	
	}while(true);
}
