#include "CA.h"


static int CA_speed = 0;
static int CA_distance = 0;
static int CA_threshold = 50;

void (*PF_CA_STATE)();


STATE_FUNC_DEFINE(CA_waiting)
{
	/* STATE NAME */
	CA_STATE_ID = CA_waiting;
	printf ("CA_Waiting state : distance=%d  speed=%d \n" ,CA_distance, CA_speed );
	
	/* ACTION */
	CA_speed = 0; 				// CALL DC_STOP
	DC_MOTOR_voidMove(CA_speed);
		

}

STATE_FUNC_DEFINE(CA_driving)
{
	/* STATE NAME */
	CA_STATE_ID = CA_driving;
	printf ("CA_Driving state : distance=%d  speed=%d \n" ,CA_distance,CA_speed );
	
	/* ACTION */
	CA_speed = 30; 				// CALL DC_MOVE
	DC_MOTOR_voidMove(CA_speed);
	
	

}

void SetCarState(int distance)
{
	CA_distance = distance;

	( CA_distance <= CA_threshold ) ? (PF_CA_STATE = STATE(CA_waiting)) : (PF_CA_STATE = STATE(CA_driving));

	printf ("US ---------- distance=%d ----------> CA\n" ,CA_distance);

}


