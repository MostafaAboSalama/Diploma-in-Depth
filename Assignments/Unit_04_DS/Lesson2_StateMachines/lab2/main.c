#include "CA.h"
#include "DC_Motor.h"
#include "US.h"

void SetUp()
{
	DC_MOTOR_voidInit();
	US_voidInit();
	
	PF_CA_STATE = STATE(CA_waiting);
	PF_US_STATE = STATE(US_busy);
	PF_DC_STATE = STATE(DC_MOTOR_idle);
}

void main()
{
	volatile int Delay ;

	SetUp();
	while (1)
	{
		PF_US_STATE();
		PF_CA_STATE();
		PF_DC_STATE();
		for (Delay=0 ; Delay<=1000 ; Delay++);
	}
}