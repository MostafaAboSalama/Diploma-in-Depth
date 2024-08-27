#include <stdint.h>

extern int _stack_top;
extern int _E_text;
extern int _S_data;
extern int _E_data;
extern int _S_bss;
extern int _E_bss;

extern int main();

void _Reset_Handler();

void _Default_Handler()
{
	_Reset_Handler();
}

void _NMI_Handler	   (void) __attribute__((weak, alias("_Default_Handler")));
void _H_Fault_Handler  (void) __attribute__((weak, alias("_Default_Handler")));
void _MM_Fault_Handler (void) __attribute__((weak, alias("_Default_Handler")));
void _Bus_Fault_Handler(void) __attribute__((weak, alias("_Default_Handler")));

uint32_t _vectors_array[] __attribute__((section(".vectors"))) = 
{
	(uint32_t) &_stack_top,
	(uint32_t) &_Reset_Handler,
	(uint32_t) &_NMI_Handler	  ,
	(uint32_t) &_H_Fault_Handler  ,
	(uint32_t) &_MM_Fault_Handler ,
	(uint32_t) &_Bus_Fault_Handler,
};

void _Reset_Handler()
{
	// Copy .data from flash to ram
	uint32_t dataSize = (uint32_t)_E_data - (uint32_t)_S_data;
	uint8_t* P_SRC  = (uint8_t*)&_E_text ;
	uint8_t* P_DEST = (uint8_t*)&_S_data ;
	for(int i = 0; i < dataSize; i++)
	{
		*P_DEST = *P_SRC;
		P_DEST++;
		P_SRC++;
	}
	
	// Init bss with 0
	uint32_t bssSize = (uint32_t)_E_bss - (uint32_t)_S_bss;
	uint8_t* P_BSS  = (uint8_t*)&_S_bss ;
	for(int i = 0; i < bssSize; i++)
	{
		*P_BSS = 0;
		P_BSS++;
	}
	
	// Call main()
	main();
}