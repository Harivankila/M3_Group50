

#ifndef DRIVER_FUNC_H_
#define DRIVER_FUNC_H_
#include <stdint.h>
#define LED_GREEN 12  // defining green led pin as 12
#define LED_ORANGE 13 // defining orange led pin as 13
#define LED_RED 14    // defining red led pin as 14
#define LED_BLUE 15   // defining blue led pin as 15
#define user_btn 0    // defining user button pin as 0
void led_init_all(void);      // initialization all LED's
void led_on(uint8_t led_no);  // LED on
void led_off(uint8_t led_no); // LED off
void my_delay_ms(uint32_t time); // This is to provide some delay
void button_init(void);   //  initialization of button
int btn_press(void);      //  no of presses
int Encryption(int data); // This will encrypt no of button presses and returns encrypted data
#endif
