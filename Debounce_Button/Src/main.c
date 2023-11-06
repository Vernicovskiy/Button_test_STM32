#include "main.h"

#define LED_ON() GPIOA->BSRR = GPIO_BSRR_BS5;
#define LED_OFF() GPIOA->BSRR = GPIO_BSRR_BR5;


	//uint8_t res = 0;
	uint32_t count = 0;
	uint32_t ref_count = 3;
	uint32_t state = 0;



	void gpio_init(){

		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; //RCC on for GPIO A
	    GPIOA->MODER &= ~0x00000C00; /* clear pin mode */
	    GPIOA->MODER |= GPIO_MODER_MODER5_0; /* set pin to output mode */

	    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN; //RCC on for GPIO C
	    GPIOC->PUPDR |= GPIO_PUPDR_PUPD13_0; // pull_up

	}

	uint8_t Debounce_Handler(uint32_t state){

		if (state == 0){

			if (count < ref_count){
				count++;
				return 0;
			}

			else {
					return 1;		// button pressed
				}
			}

		else {
				if (count > 0){
					count--;
					return 1;
				}

				else {

					if (state != 0){
						return 0;
					}
				}

		}

		}



	int main(void){

		gpio_init();


		while(1){

			state = READ_BIT(GPIOC->IDR, GPIO_IDR_ID13);

			if (Debounce_Handler(state) == 1){
				LED_ON();
			}
			else {
				LED_OFF();
			}


		}


	}
