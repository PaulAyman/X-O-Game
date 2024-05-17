#include "../../common/tm4c123gh6pm.h"
#include "ADC.h"

int temp_delay;

void ADC_Init(void){
	// ADC1, SEQ3, PE1(AN2)
	SYSCTL_RCGCADC_R |= (1<<1); // ENABLE ADC1
	SYSCTL_RCGCGPIO_R |= (1<<4) | (1<<5); // ENABLE PORTS E,F
	temp_delay= 0;
	
	GPIO_PORTE_AFSEL_R |= (1<<1); // ENABLE ALTERNATIVE FUNC FOR PE1
	GPIO_PORTE_DEN_R  &= ~(1<<1); // DISABLE DIG FUNC FOR PE1
	GPIO_PORTE_AMSEL_R |= (1<<1); // ENABLE ANALOG FUNC FOR PE1
	ADC1_ACTSS_R &= ~(1<<3); // DISABLE SAMPLE SEQ
	ADC1_EMUX_R = (0xF << 12); // TRIGGER: ALWAYS SAMPLING
	ADC1_SSMUX3_R = 2; // READ SEQ3 FROM AIN2, SHOK
	ADC1_SSCTL3_R |= (1<<1) | (1<<2); // End bit set, interrupt bit enabled for ss3
	ADC1_IM_R |= (1<<3); // enable int mask for ss3
	ADC1_RIS_R  |= (1<<3); // clear int status for ss3 
	ADC1_ACTSS_R |= (1<<3); // ENABLE SAMPLE SEQ
	NVIC_EN2_R |= (1<<3);
	
}
