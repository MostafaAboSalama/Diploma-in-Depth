#include "CA.h"

int GetRandomDistance(int l, int r, int count);

static int CA_speed = 0;
static int CA_distance = 0;
static int CA_threshold = 50;

void (*PF_CA_STATE)();

STATE_FUNC_DEFINE(CA_waiting)
{
	/* STATE NAME */
	CA_STATE_ID = CA_waiting;
	
	/* ACTION */
	CA_speed = 0; 				// CALL DC_STOP
	
	/* EVENT CHECK */
	CA_distance = GetRandomDistance(45, 55, 1);
	(CA_distance <= CA_threshold) ? (PF_CA_STATE = STATE(CA_waiting)) : (PF_CA_STATE = STATE(CA_driving));
	printf ("CA_Waiting state : distance=%d  speed=%d \n" ,CA_distance, CA_speed );

}

STATE_FUNC_DEFINE(CA_driving)
{
	/* STATE NAME */
	CA_STATE_ID = CA_driving;
	
	/* ACTION */
	CA_speed = 30; 				// CALL DC_MOVE
	
	/* EVENT CHECK */
	CA_distance = GetRandomDistance(45, 55, 1);
	(CA_distance <= CA_threshold) ? (PF_CA_STATE = STATE(CA_waiting)) : (PF_CA_STATE = STATE(CA_driving));
	printf ("CA_Driving state : distance=%d  speed=%d \n" ,CA_distance,CA_speed );

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