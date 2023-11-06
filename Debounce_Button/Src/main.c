#include "main.h"

#define LED_ON() GPIOA->BSRR = GPIO_BSRR_BS5;
#define LED_OFF() GPIOA->BSRR = GPIO_BSRR_BR5;


	__IO uint32_t Tim10_Count = 0;


	void gpio_init(){

		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; //RCC on for GPIO A
	    GPIOA->MODER &= ~0x00000C00; /* clear pin mode */
	    GPIOA->MODER |= GPIO_MODER_MODER5_0; /* set pin to output mode */

	    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN; //RCC on for GPIO C
	    GPIOC->PUPDR |= GPIO_PUPDR_PUPD13_0; // pull_up

	}


	int main(void){

		gpio_init();


		while(1){
			if (!READ_BIT(GPIOC->IDR, GPIO_IDR_ID13)){
				LED_ON();
			}
			else {
				LED_OFF();
			}


		}


	}
