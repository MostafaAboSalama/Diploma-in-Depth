

#include <stdint.h>

#define RCC_BASE 	 		0x40021000
#define GPIOA_BASE	 		0x40010800
#define RCC_APB2ENR			*(volatile uint32_t*)(RCC_BASE + 0x18)
#define GPIO_CRL			*(volatile uint32_t*)(GPIOA_BASE + 0x00)
#define GPIO_ODR			*(volatile uint32_t*)(GPIOA_BASE + 0x0C)

void delay(int n);

int main()
{
    /* CLK ENA */
	RCC_APB2ENR |= 1 << 2;  /* Enable clock for GPIOA (bit 2) */

    /* PORTA PIN5 OUTPUT */
	GPIO_CRL &= ~(0b00 << 22);    /* Clear bits 23:20 for PIN5 */
	GPIO_CRL |=  (0b01 << 20);    /* Set MODE5 to 01 (output 10 MHz), CNF5 to 00 (push-pull) */

    while(1)
    {
    	GPIO_ODR |= (1 << 5);    // HIGH
        delay(500);
        GPIO_ODR &= ~(1 << 5);   // LOW
        delay(500);
    }
}

void delay(int n)
{
	int i = 0;
	 for( ; n > 0; n--)
	 {
		 for(i = 0; i < 3195; i++);
	 }


}

