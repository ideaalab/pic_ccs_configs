#include "project.h"

#if defined(EJEMPLO1)
/*
 * LEDS
 * Parpadea los LEDS
 */
void main(){
	setup_timer_0(T0_INTERNAL|T0_DIV_1);
	setup_timer_2(T2_DIV_BY_64, 156, 1);
	setup_wdt(WDT_OFF);
	setup_vref(VREF_OFF);
	setup_adc(ADC_CLOCK_INTERNAL);
	setup_adc_ports(sAN2);
	set_adc_channel(POT);
	setup_pwm1(PWM_DISABLED);
	setup_pwm2(PWM_DISABLED);
	setup_oscillator(OSC_2MHZ);
	
	set_tris_a(TRIS_A);
	port_a_pullups(PULLUPS_A);
	
	LED1 = FALSE;
	LED2 = FALSE;

	do{
		LED1 = !LED1;
		LED2 = !LED1;
		delay_ms(200);
	}while(TRUE);
}
#elif defined(EJEMPLO2)
/*
 * POTENCIOMETRO Y LEDS
 * Alterna el LED segun el valor del potenciometro
 */
void main(){
	setup_timer_0(T0_INTERNAL|T0_DIV_1);
	setup_timer_2(T2_DIV_BY_64, 156, 1);
	setup_wdt(WDT_OFF);
	setup_vref(VREF_OFF);
	setup_adc(ADC_CLOCK_INTERNAL);
	setup_adc_ports(sAN2);
	set_adc_channel(POT);
	setup_pwm1(PWM_DISABLED);
	setup_pwm2(PWM_DISABLED);
	setup_oscillator(OSC_2MHZ);
	
	set_tris_a(TRIS_A);
	port_a_pullups(PULLUPS_A);
	
	LED1 = FALSE;
	LED2 = FALSE;

	do{
		if(bit_test(read_adc(), 6) == 1){
			LED1 = TRUE;
			LED2 = FALSE;
		}
		else{
			LED1 = FALSE;
			LED2 = TRUE;
		}
	}while(TRUE);
}
#elif defined(EJEMPLO3)
/*
 * PULSADOR Y LEDS
 * Cada vez que se presiona el boton alterna el LED encendido
 */
void main(){
	setup_timer_0(T0_INTERNAL|T0_DIV_1);
	setup_timer_2(T2_DIV_BY_64, 156, 1);
	setup_wdt(WDT_OFF);
	setup_vref(VREF_OFF);
	setup_adc(ADC_CLOCK_INTERNAL);
	setup_adc_ports(sAN2);
	set_adc_channel(POT);
	setup_pwm1(PWM_DISABLED);
	setup_pwm2(PWM_DISABLED);
	setup_oscillator(OSC_2MHZ);
	
	set_tris_a(TRIS_A);
	port_a_pullups(PULLUPS_A);
	
	LED1 = FALSE;
	LED2 = FALSE;

	do{
		if(BTN == 0){
			LED1 = !LED1;
			LED2 = !LED1;
			while(BTN == 0){delay_ms(20);}
		}
	}while(TRUE);
}
#elif defined(EJEMPLO4)
/*
 * LECTURA Y ESCRITURA DE HEF
 * Cada vez que se inicia el programa graba un valor en la HEF
 * Segun el valor leido enciende un LED u otro
 */
void main(){
	setup_timer_0(T0_INTERNAL|T0_DIV_1);
	setup_timer_2(T2_DIV_BY_64, 156, 1);
	setup_wdt(WDT_OFF);
	setup_vref(VREF_OFF);
	setup_adc(ADC_CLOCK_INTERNAL);
	setup_adc_ports(sAN2);
	set_adc_channel(POT);
	setup_pwm1(PWM_DISABLED);
	setup_pwm2(PWM_DISABLED);
	setup_oscillator(OSC_2MHZ);
	
	set_tris_a(TRIS_A);
	port_a_pullups(PULLUPS_A);
	
	LED1 = FALSE;
	LED2 = FALSE;

	if(read_program_eeprom(ADDRESS_TO_USE_FOR_STORAGE) > 127){
		LED1 = TRUE;
		LED2 = FALSE;
		write_program_eeprom(ADDRESS_TO_USE_FOR_STORAGE, 1);
	}
	else{
		LED1 = FALSE;
		LED2 = TRUE;
		write_program_eeprom(ADDRESS_TO_USE_FOR_STORAGE, 200);
	}
	
	do{
		if(BTN == 0){
			while(BTN == 0){delay_ms(20);}
			reset_cpu();
		}
	}while(TRUE);
}
#elif defined(EJEMPLO5)
/*
 * HEF, LEDS, pulsador y potenciometro
 * Cuando se presiona el boton se guarda en HEF el valor del potenciometro
 * y se reinicia el PIC. Al iniciar lee si el valor y enciende un LED segun el valor
 */
void main(){	
	setup_timer_0(T0_INTERNAL|T0_DIV_1);
	setup_timer_2(T2_DIV_BY_64, 156, 1);
	setup_wdt(WDT_OFF);
	setup_vref(VREF_OFF);
	setup_adc(ADC_CLOCK_INTERNAL);
	setup_adc_ports(sAN2);
	set_adc_channel(POT);
	setup_pwm1(PWM_DISABLED);
	setup_pwm2(PWM_DISABLED);
	setup_oscillator(OSC_2MHZ);
	
	set_tris_a(TRIS_A);
	port_a_pullups(PULLUPS_A);
	
	LED1 = FALSE;
	LED2 = FALSE;

	if(read_program_eeprom(ADDRESS_TO_USE_FOR_STORAGE) > 127){
		LED1 = TRUE;
	}
	else{
		LED2 = TRUE;
	}
	
	do{
		if(BTN == 0){
			write_program_eeprom(ADDRESS_TO_USE_FOR_STORAGE, (long)read_adc());
			while(BTN == 0){delay_ms(20);}
			reset_cpu();
		}
	}while(TRUE);
}
#elif defined(EJEMPLO6)
/*
 * PWM, POT, LED
 * Cambia el brillo del LED segun el valor del potenciometro
 */
void main(){
	long adc;
	
	setup_timer_0(T0_INTERNAL|T0_DIV_1);
	setup_timer_2(T2_DIV_BY_64, 156, 1);
	setup_wdt(WDT_OFF);
	setup_vref(VREF_OFF);
	setup_adc(ADC_CLOCK_INTERNAL);
	setup_adc_ports(sAN2);
	set_adc_channel(POT);
	setup_pwm1(PWM_ENABLED | PWM_OUTPUT);
	setup_pwm2(PWM_DISABLED);
	setup_oscillator(OSC_2MHZ);
	
	set_tris_a(TRIS_A);
	port_a_pullups(PULLUPS_A);
	
	LED1 = FALSE;
	LED2 = FALSE;
	
	do{
		//ADC 8 bits
		//Osc = 2Mhz
		//Tick = 1/Osc * 4 = 2uS
		//Prescaler2 = 64
		//PR2 = 156
		//Pediodo = (PR2 + 1) * Prescaler2 * Tick  = (156+1) * 64  * 2uS = 20.096mS
		//Timer2 tick = Tick * Prescaler2 = 2uS * 64 = 128uS
		//PWM ticks = (PR + 1) * 4 = 628	//no se por que 
		//PWM tick = 32uS //no se por que
		
		adc = read_adc() * 628LL / 256;	//se usa un cast a int32 (LL) para que no desborde
		set_pwm1_duty(adc);
	}while(TRUE);
}
#elif defined(EJEMPLO7)
/*
 * SERVO, PWM, POT
 * Posiciona servo con potenciometro
 */
void main(){
	int adc;
	long pos;
	
	setup_timer_0(T0_INTERNAL|T0_DIV_1);
	setup_timer_2(T2_DIV_BY_64, 156, 1);
	setup_wdt(WDT_OFF);
	setup_vref(VREF_OFF);
	setup_adc(ADC_CLOCK_INTERNAL);
	setup_adc_ports(sAN2);
	set_adc_channel(POT);
	setup_pwm1(PWM_ENABLED | PWM_OUTPUT);
	setup_pwm2(PWM_DISABLED);
	setup_oscillator(OSC_2MHZ);
	
	set_tris_a(TRIS_A);
	port_a_pullups(PULLUPS_A);
	
	LED1 = FALSE;
	LED2 = FALSE;
	
	do{
		//ADC 8 bits
		//Osc = 2Mhz
		//Tick = 1/Osc * 4 = 2uS
		//Prescaler2 = 64
		//PR2 = 156
		//Pediodo = (PR2 + 1) * Prescaler2 * Tick  = (156+1) * 64  * 2uS = 20.096mS
		//Timer2 tick = Tick * Prescaler2 = 2uS * 64 = 128uS
		//PWM ticks = (PR + 1) * 4 = 628	//no se por que 
		//PWM tick = 32uS //no se por que
		//Min = 500/32 = 15.6;	//Ticks necesarios para tiempo minimo = minimo tiempo del servo div entre PWM tick
		//Max = 2500/32 = 78.125
		//Rango = 2000 / 32 = 62.5;	//rango de ticks (entre 0.5 y 2.5mS = 2mS)
		//Escala = Rango / 256 = 0.244
		
		adc = read_adc();
		pos = 16 + (adc >> 2);	//solo uso los 6MSB (64 valores) bastante proximo a 62.5
		set_pwm1_duty(pos);
	}while(TRUE);
}
#elif defined(EJEMPLO8)
/*
 * Lectura por lote de HEF
 * Lee 7 valores pregrabados en HEF
 */
void main(){
	long Hef[7] = {1,1,1,1,1,1,1};
	int x = 0;
	int y = 0;

	setup_timer_0(T0_INTERNAL|T0_DIV_1);
	setup_timer_2(T2_DIV_BY_64, 156, 1);
	setup_wdt(WDT_OFF);
	setup_vref(VREF_OFF);
	setup_adc(ADC_CLOCK_INTERNAL);
	setup_adc_ports(sAN2);
	set_adc_channel(POT);
	setup_pwm1(PWM_DISABLED);
	setup_pwm2(PWM_DISABLED);
	setup_oscillator(OSC_2MHZ);
	
	set_tris_a(TRIS_A);
	port_a_pullups(PULLUPS_A);
	
	LED1 = FALSE;
	LED2 = FALSE;
	
	do{
		if(BTN == 0){
			read_program_memory(ADDRESS_TO_USE_FOR_STORAGE, Hef, 14);	//leer HEF cada posicion son 2 bytes, para leer 7 words necesitamos leer 14 bytes
			
			//parpadear led tantas veces como el valor de cada posicion
			//con un tiempo muerto entre cada posicion
			for(x=0; x<7; x++){
				for(y=0; y<Hef[x]; y++){
					LED1 = TRUE;
					delay_ms(100);
					LED1 = FALSE;
					delay_ms(100);
				}
				
				delay_ms(500);
			}
		}
	}while(TRUE);
}
#elif defined(EJEMPLO9)
/*
 * SERIAL, HEF
 * Lee los valores de 7 posiciones de HEF y los muestra por puerto serie
 */
void main(){
	long Hef[7] = {0,0,0,0,0,0,0};

	setup_timer_0(T0_INTERNAL|T0_DIV_1);
	setup_timer_2(T2_DIV_BY_64, 156, 1);
	setup_wdt(WDT_OFF);
	setup_vref(VREF_OFF);
	setup_adc(ADC_CLOCK_INTERNAL);
	setup_adc_ports(sAN2);
	set_adc_channel(POT);
	setup_pwm1(PWM_DISABLED);
	setup_pwm2(PWM_DISABLED);
	setup_oscillator(OSC_2MHZ);
	
	set_tris_a(TRIS_A);
	port_a_pullups(PULLUPS_A);
	
	LED1 = FALSE;
	LED2 = FALSE;
	
	do{
		if(BTN == 0){
			read_program_memory(ADDRESS_TO_USE_FOR_STORAGE, Hef, 14);	//leer HEF
			
			printf("\r");
			
			printf("R:%u ", getenv("FLASH_WRITE_SIZE"));
			printf("W:%u { ", getenv("FLASH_ERASE_SIZE"));

			printf("%Lu, ", Hef[0]);
			printf("%Lu, ", Hef[1]);
			printf("%Lu, ", Hef[2]);
			printf("%Lu, ", Hef[3]);
			printf("%Lu, ", Hef[4]);
			printf("%Lu, ", Hef[5]);
			printf("%Lu }", Hef[6]);
			
			while(BTN == 0){delay_ms(20);}
		}
	}while(TRUE);
}
#elif defined(EJEMPLO10)
/*
 * SLEEP
 * El PIC entra en modo sleep de muy bajo consumo
 */

void main(){
	setup_timer_0(T0_INTERNAL);
	setup_timer_2(T2_DISABLED, 0, 1);
	setup_wdt(WDT_OFF);
	setup_vref(VREF_OFF);
	setup_adc(ADC_CLOCK_INTERNAL);
	setup_adc_ports(NO_ANALOGS);
	setup_pwm1(PWM_DISABLED);
	setup_pwm2(PWM_DISABLED);
	setup_oscillator(OSC_31KHZ);
	
	set_tris_a(TRIS_A);
	port_a_pullups(PULLUPS_A);
	
	LED1 = TRUE;
	LED2 = FALSE;
	
	VREGPM1 = 1;	//power save mode

	do{
		if(BTN == 0){
			LED1 = FALSE;
			
			while(BTN == 0){delay_ms(20);}
			sleep();
			// < --- ESTAMOS DURMIENDO --- >
		}
	}while(TRUE);
}
#endif