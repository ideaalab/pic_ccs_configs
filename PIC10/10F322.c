#include <10F322.h>

// --- FUSES ---
//Oscilator Selection (FOSC bit 0)
#fuses INTRC	
//#fuses EC

//Brown-out Reset Enable (BOREN bit 1-2)
#fuses BROWNOUT
//#fuses NOBROWNOUT
//#fuses BROWNOUT_SW
//#fuses BROWNOUT_NOSL

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

//Low-Voltage Programing Enabled (LVP bit 8)
#fuses NOLVP	
//#fuses LVP

//Low-Power Brown-out Reset Enable (LPBOR bit 9)
//#fuses LPBOR
#fuses NOLPBOR

//Brown-out Reset Voltage Selection (BORV bit 10)
//#fuses BORV25
#fuses BORV19

//Flash Memory Self-Write Protection (WRT bit 11-12)
#fuses NOWRT
//#fuses WRT
//#fuses WRT_50%
//#fuses WRT_25%

//Debug Mode
#fuses NODEBUG	
//#fuses DEBUG
// --- FUSES ---

#device adc=8
#use delay(clock=8000000)
#use fast_io(a)

//GPIO
#byte PORTA    = getenv("SFR:PORTA")
#define TRIS_A	0b00001111
#define WPU_A	0b00001111

#define POT	0
#bit XX		= PORTA.1
#bit YY		= PORTA.2
#bit ZZ		= PORTA.3

//Constantes
//--- Configurar ---

//------------------


//Variables


//Funciones


void main(){
	
	setup_timer_0(T0_INTERNAL);		//configura timer 0
	setup_timer_2(T2_DISABLED,0,1);	//configura timer 2
	setup_wdt(WDT_OFF);				//configura watch dog
	setup_vref(VREF_2v048);			//configura VRef
	setup_pwm1(PWM_DISABLED);
	setup_pwm2(PWM_DISABLED);
	setup_adc(ADC_CLOCK_INTERNAL);	//configura ADC
	setup_adc_ports(NO_ANALOGS);	//configura pines ADC
	setup_oscillator(OSC_8MHZ);	//configura oscilador interno
	
	set_tris_a(TRIS_A);
	port_a_pullups(WPU_A);
	
	set_adc_channel(FVR_CHANNEL);	//selecciona canal
	ext_int_edge(L_TO_H);			//flanco para INTE EXT
	
	enable_interrupts(INT_TIMER0);
	enable_interrupts(INT_TIMER2);
	enable_interrupts(INT_EXT);
	enable_interrupts(INT_RA);
	enable_interrupts(INT_CLC1);
	enable_interrupts(INT_NCO1);
	enable_interrupts(INT_AD);
	enable_interrupts(PERIPH);
	enable_interrupts(GLOBAL);
	   
	do{

	}while(true);
}
