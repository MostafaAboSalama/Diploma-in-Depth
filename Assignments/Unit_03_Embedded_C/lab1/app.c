#include "uart.h"

int bssVar;
int dataVar = 5;
const int rodataVar = 10;

int main()
{
	int stackVar = 20;
	UART_voidSendString("Mostafa AboSalama From Scratch");

}