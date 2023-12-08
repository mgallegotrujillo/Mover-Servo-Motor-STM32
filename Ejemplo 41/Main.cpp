// ************************** LIBRERIAS **********************
		#include <stdio.h>
		#include "STM32F7xx.h"
// ***********************************************************

// ************************** VARIABLES GLOBALES *************
		short tiempo=100; 
		bool bandera_servo=1;
// ***********************************************************

// ************************** FUNCIONES **********************
		void mover_servo(){
			tiempo=tiempo-1;
			GPIOA->ODR =0x01;
			for(int i=0; i<tiempo; i++){}
			GPIOA->ODR =0x00; 
			if(tiempo>1000){
				tiempo=0;
				bandera_servo=0;
			}
		}
// ***********************************************************

// ************************** INTERRUPCIONES *****************
		extern "C"{
			void SysTick_Handler(void){
				if(bandera_servo==1){
					mover_servo();
				}
			}
		}
// ***********************************************************

// ************************** MAIN ***************************
int main(void){
		// ********************** PUERTOS ************************
				RCC->AHB1ENR |=0x01;
		// *******************************************************
	
		// ********************** PINES **************************
				GPIOA->MODER |=0x01;
				GPIOA->OTYPER |=0x00; 
				GPIOA->OSPEEDR |=0x01; 
				GPIOA->PUPDR |=0x01; 
		// *******************************************************
	
		// ********************** SYSTICK ************************
				SystemCoreClockUpdate();
				SysTick_Config(SystemCoreClock/1000);
		// *******************************************************
	
		// ********************** BUCLE **************************
				while(true){
					
				}
		// *******************************************************
}
// ***********************************************************