#include "uart.h"

#define UART0DR 	*(unsigned int*)(0x101f1000)

void UART_voidSendString(unsigned char* StringPtr)
{
	while(*StringPtr != '\0')
	{
		UART0DR = (unsigned int)(*StringPtr);
		StringPtr++;
	}
}