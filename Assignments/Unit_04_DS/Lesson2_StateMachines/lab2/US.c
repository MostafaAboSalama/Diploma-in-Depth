#include "US.h"


static int US_distance = 0;

int GetRandomDistance(int l, int r, int count);
int US_intReadDistance();

void (*PF_US_STATE)();


STATE_FUNC_DEFINE(US_busy)
{
	// State_Name
	US_STATE_ID=US_busy;

	//State_Action
	US_distance = GetRandomDistance(45,55,1);

	printf ("US_busy state : distance=%d \n" ,US_distance);


	SetCarState(US_distance);
	PF_US_STATE = STATE(US_busy);


}

void US_voidInit()
{
	printf("UltraSonic Start\n");
}

int US_intReadDistance()
{
	return GetRandomDistance(45, 55, 1);
}

int GetRandomDistance(int l, int r, int count)
{
	/* Generate one(count) random number in the range [l:r] */
	int i,rand_num;
	for (i=0 ; i<count ; i++)
	{
		rand_num = (rand() % (r - l + 1 )) + l ;
	}
	return rand_num;
}