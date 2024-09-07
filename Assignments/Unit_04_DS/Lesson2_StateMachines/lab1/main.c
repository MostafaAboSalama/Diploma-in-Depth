#include "CA.h"

void SetUp()
{
	PF_CA_STATE = STATE(CA_waiting);
}

void main()
{
	volatile int Delay ;

	SetUp();
	while (1)
	{
		//call sate for each block
		PF_CA_STATE();
		for (Delay=0 ; Delay<=1000000 ; Delay++);

	}
}