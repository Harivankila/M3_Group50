#include "driver_func.h"

const int for_delay = 100;
const int encode1 = 1;		  
const int encode2 = 2;		
const int encode3 = 3;		  
const int encode4 = 4;		  
int un_used_var;
void my_delay_ms(uint32_t time) 
{								
	for (uint32_t i = 0; i < (time * for_delay); i++)
	{
		un_used_var++;
	}
}

void button_init(void)
{
	
	uint32_t *pRccAhb1enr = (uint32_t *)0x40023830; 
	*pRccAhb1enr |= (1 << 0);						

  uint32_t *pGpioPuPdReg = (uint32_t *)0x4002000C; 
	*pGpioPuPdReg |= (1 << 1);						
}

void led_init_all(void)
{													  
													  
	uint32_t *pRccAhb1enr = (uint32_t *)0x40023830;	  
	uint32_t *pGpiodModeReg = (uint32_t *)0x40020C00; 

	*pRccAhb1enr |= (1 << 3); 
	
	*pGpiodModeReg |= (1 << (2 * LED_GREEN)); 
	*pGpiodModeReg |= (1 << (2 * LED_ORANGE)); 
	*pGpiodModeReg |= (1 << (2 * LED_RED));	   
	*pGpiodModeReg |= (1 << (2 * LED_BLUE));   

	led_off(LED_GREEN);
	led_off(LED_ORANGE);
	led_off(LED_RED);
	led_off(LED_BLUE);
}

void on_led(uint8_t on_led)							  
{													 
	uint32_t *pGpiodDataReg = (uint32_t *)0x40020C14; 
	*pGpiodDataReg |= (1 << on_led);
}

void led_off(uint8_t on_led)						  
{													  
	uint32_t *pGpiodDataReg = (uint32_t *)0x40020C14; 
	*pGpiodDataReg &= ~(1 << on_led);
}

int btn_press(void) 
{ 
	int count = 0;
	int hfmilsec = 100;						  
	uint32_t *pGpioaDataReg = (uint32_t *)0x40020010;
	while (hfmilsec--)
	{
		if ((*pGpioaDataReg) & (1 << user_btn))
		{										
			my_delay_ms(150);
			count++;
			if (count > 4)
				count = 0;
		}
	}
	return count;
}

int Encryption(int data)
{

	if (data == encode1)
	{ int shs = 1000 + 244;
		return shs;
	}
	else if (data == encode2)
	{int shs = 1000 + 843;
		return shs;
	
	else if (data == encode3)
	{int shs = 6000 + 789;
		return shs;
	}
	else if (data == encode4)
	{int shs = 5000 + 478;
		return shs;
	}
	return 0;
}
