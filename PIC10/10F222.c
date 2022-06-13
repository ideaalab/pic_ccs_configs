#include <10F222.h>
#device adc=8

#FUSES NOWDT,NOMCLR,IOSC8,PROTECT

#use delay(clock=8000000)
#use fast_io(b)

//GPIO
#byte GP    = 0x06

#define POT	0
#bit XX	= GP.1
#bit XX	= GP.2
#bit XX	= GP.3

//Constantes
//--- Configurar ---

//------------------


//Variables


//Funciones
void set_options(void){
//declaro el registro OPTION
int Opciones = 0;

#bit nGPWU		= Opciones.7
#bit nGPPU		= Opciones.6
#bit T0CS		= Opciones.5
#bit T0SE		= Opciones.4
#bit PSA		= Opciones.3
#bit PS2		= Opciones.2
#bit PS1		= Opciones.1
#bit PS0		= Opciones.0

//seleccionar configuracion
nGPWU = 1;	//Wake-up on pin change (Enable = 0, Disable = 1)
nGPPU = 0;	//Weak pull ups (Enable = 0, Disable = 1)
T0CS = 0;	//Timer0 Clock source (T0CKl pin = 1, Interno = 0)
T0SE = 0;	//Timer0 Source Edge (L_to_H = 0, H_to_L = 1)
PSA = 0;	//Prescaler assignment (WDT = 1, Timer0 = 0)
PS2 = 0;	//Prescaler rate (mirar datasheet)
PS1 = 0;	//Prescaler rate (mirar datasheet)
PS0 = 0;	//Prescaler rate (mirar datasheet)

#asm
	movf Opciones,0	//Opciones -> W
	option			//W -> option
#endasm
}

void set_adc(int An){
	An = An | 0b00001101;
#asm
	movf An,0	//An -> W
	movwf 0x7	//W -> ADCON0
#endasm
}

void main(){

	set_options();		//configura pullups, wake on change y timer
	set_adc(sAN0);
	set_adc_channel(0);
	set_tris_b(0b00001011);
	   
	do{

	}while(true);
}
