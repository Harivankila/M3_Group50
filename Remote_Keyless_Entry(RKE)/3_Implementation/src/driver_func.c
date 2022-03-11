#include "own_drivers_and_func.h"

const int for_delay = 100000; // for delay initial values
const int encrypt1 = 1;		  // for keeping encrypt1 as a constant throught the program
const int encrypt2 = 2;		  // for keeping encrypt2 as a constant throught the program
const int encrypt3 = 3;		  // for keeping encrypt3 as a constant throught the program
const int encrypt4 = 4;		  // for keeping encrypt4 as a constant throught the program
int un_used_var;
void my_delay_ms(uint32_t time) // this is
{								// for time = 1000 this gives delay of approx 1sec
	for (uint32_t i = 0; i < (time * for_delay); i++)
	{
		un_used_var++;
	}
}

void button_init(void)
{
	//(for Gpio A)
	// for clocking and making it input(here) or output
	uint32_t *pRccAhb1enr = (uint32_t *)0x40023830; // 0x40023800 + 0x30(offset) pg.no --> 65 (RCC) , 265 (RCC_AHB1ENR)
	*pRccAhb1enr |= (1 << 0);						// enable GPIOA (GPIOAEN) pg.no 265

	/*This is optional because its input by default*/
	/*------*/
	uint32_t *pGpiodModeReg = (uint32_t *)0x40020000; // 0x40020000 pg.no --> 65 (GPIOA)
	*pGpiodModeReg &= ~(1 << 0);					  // setting it as input
	*pGpiodModeReg &= ~(1 << 1);
	/*------*/

	uint32_t *pGpioPuPdReg = (uint32_t *)0x4002000C; //(GPIOx_PUPDR) + 0x0C(offset) for Pull up and pull down
	*pGpioPuPdReg |= (1 << 1);						 // for setting pull down for A0 page no 282
}

void led_init_all(void)
{													  //(for Gpio D)
													  // for clocking and making it input or output(here)
	uint32_t *pRccAhb1enr = (uint32_t *)0x40023830;	  // 0x40023800 + 0x30(offset) pg.no --> 65 (RCC) , 265 (RCC_AHB1ENR)
	uint32_t *pGpiodModeReg = (uint32_t *)0x40020C00; // 0x40020C00 pg.no --> 65 (GPIOD) (GPIOx_MODER)

	*pRccAhb1enr |= (1 << 3); // enable GPIOD (GPIODEN) pg.no 265
	// configure it as General purpose output mode
	//  see pg.no 281 -> GPIO port mode register, MODERy[1:0] for understanding
	*pGpiodModeReg |= (1 << (2 * LED_GREEN));  // setting MODER12 as an output port
	*pGpiodModeReg |= (1 << (2 * LED_ORANGE)); // setting MODER13 as an output port
	*pGpiodModeReg |= (1 << (2 * LED_RED));	   // settingMODER14 as an output port
	*pGpiodModeReg |= (1 << (2 * LED_BLUE));   // setting MODER15 as an output port

	led_off(LED_GREEN);
	led_off(LED_ORANGE);
	led_off(LED_RED);
	led_off(LED_BLUE);
}

void led_on(uint8_t led_no)							  // here this will on led for given LED pin
{													  // for outputting data
	uint32_t *pGpiodDataReg = (uint32_t *)0x40020C14; //(GPIOx_ODR) + 0x14(offset)
	*pGpiodDataReg |= (1 << led_no);
}

void led_off(uint8_t led_no)						  // here this will off led for given LED pin
{													  // for outputting data
	uint32_t *pGpiodDataReg = (uint32_t *)0x40020C14; //(GPIOx_ODR) + 0x14(offset)
	*pGpiodDataReg &= ~(1 << led_no);
}

int btn_press(void) 
{ // for inputting button press data and returns button count
	int count = 0;
	int hfmilsec = 10000000;						  // for some milli seconds
	uint32_t *pGpioaDataReg = (uint32_t *)0x40020010; //(GPIOx_IDR) + 0x10(offset)
	while (hfmilsec--)
	{
		if ((*pGpioaDataReg) & (1 << user_btn)) // Checking if the switch is pressed or not (Polling)
		{										// check if the button is pressed or not
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

	if (data == encrypt1)
	{ int dta = 1000 + 244;
		return dta;
	}
	else if (data == encrypt2)
	{int dta = 1000 + 843;
		return dta;
	}
	else if (data == encrypt3)
	{int dta = 6000 + 789;
		return dta;
	}
	else if (data == encrypt4)
	{int dta = 5000 + 478;
		return dta;
	}
	return 0;
}
