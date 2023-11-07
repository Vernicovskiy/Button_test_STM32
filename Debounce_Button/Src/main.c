#include "main.h"

#define LED_ON() GPIOA->BSRR = GPIO_BSRR_BS5;
#define LED_OFF() GPIOA->BSRR = GPIO_BSRR_BR5;

uint8_t counter = 0;



	/*void gpio_init(){

		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; //RCC on for GPIO A
	    GPIOA->MODER &= ~0x00000C00; //clear pin mode
	    GPIOA->MODER |= GPIO_MODER_MODER5_0; //set pin to output mode

	    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN; //RCC on for GPIO C
	    GPIOC->PUPDR |= GPIO_PUPDR_PUPD13_0; // pull_up

	} */

	void exti_init(){
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN; // тактирование на порт
		RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
		GPIOC->MODER &= ~GPIO_MODER_MODER13;
		GPIOC->PUPDR |= GPIO_PUPDR_PUPD13_0;
		SYSCFG->EXTICR[3] |= SYSCFG_EXTICR4_EXTI13_PC ;
		EXTI->IMR |= EXTI_IMR_MR13;
		EXTI->FTSR |= EXTI_FTSR_TR13;
		NVIC_EnableIRQ(EXTI15_10_IRQn);
	}


	void EXTI15_10_IRQHandler(void){
		counter++;
		EXTI->PR |= EXTI_PR_PR13;

	}


	int main(void){

		//gpio_init();
		exti_init();
		DWT->CTRL |= 1;



		while(1){
			asm("NOP");
			DWT->CYCCNT = 0;

			//asm("NOP");
			//DWT->CYCCNT = 0;
			/*if (!READ_BIT(GPIOC->IDR, GPIO_IDR_ID13)){
				LED_ON();
			}
			else {
				LED_OFF();
			}*/


		}


	}
