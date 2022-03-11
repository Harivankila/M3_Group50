#ifndef OWN_DRIVERS_AND_FUNC_H_
#define OWN_DRIVERS_AND_FUNC_H_


#include <stdint.h>


 /**
  * @brief For green led pin use LED_GREEN
  * 
  */
#define LED_GREEN 12  // here we are defining green led pin as 12

/**
 * @brief For orange led pin use LED_ORANGE
 * 
 */
#define LED_ORANGE 13 // here we are defining orange led pin as 13

/**
 * @brief For red led pin use LED_RED
 * 
 */
#define LED_RED 14    // here we are defining red led pin as 14

/**
 * @brief For blue led pin use LED_BLUE
 * 
 */
#define LED_BLUE 15   // here we are defining blue led pin as 15

/**
 * @brief For user button pin use user_btn
 * 
 */
#define user_btn 0    // here we are defining user button pin as 0

/**
 * @brief This Function Initilizes the LED's 
 * 
 */
void led_init_all(void);      // This will initialize all the LED's

/**
 * @brief This function takes LED number as input and glows that led
 * 
 * @param led_no 
 */
void led_on(uint8_t led_no);  // This is to on custom LED

/**
 * @brief This function takes LED number as input and turns off that led
 * 
 * @param led_no 
 */
void led_off(uint8_t led_no); // This is to off custom LED

/**
 * @brief This function gives us a certain delay
 * 
 * @param time 
 */
void my_delay_ms(uint32_t time); // This is to provide some delay

/**
 * @brief This function Initilizes the Button
 * 
 */
void button_init(void);   // This will initialize the button

/**
 * @brief This function Counts no of button presses in a certain anount of time
 * 
 * @return int 
 */
int btn_press(void);      // This will check no of button presses

/**
 * @brief This function Encrypts the data that is given as input and outputs encrypted data
 * 
 * @param data 
 * @return int 
 */
int Encryption(int data); // This will encrypt no of button presses and returns encrypted data

#endif
