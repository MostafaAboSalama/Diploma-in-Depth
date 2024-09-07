#include "DC_Motor.h"


static int DC_MOTOR_speed = 0;


void (*PF_DC_STATE)();

STATE_FUNC_DEFINE(DC_MOTOR_idle)
{
	/* STATE NAME */
	DC_MOTOR_STATE_ID = DC_MOTOR_idle;
	
	
	printf ("DC_MOTOR_idle state : speed=%d \n" , DC_MOTOR_speed );

}

STATE_FUNC_DEFINE(DC_MOTOR_busy)
{
	/* STATE NAME */
	DC_MOTOR_STATE_ID = DC_MOTOR_busy;
	
	PF_DC_STATE = STATE(DC_MOTOR_idle);
	printf ("DC_MOTOR_busy state : speed=%d \n", DC_MOTOR_speed );

}

void DC_MOTOR_voidInit()
{
	printf ("DC_Init\n");
}

void DC_MOTOR_voidMove(int speed)
{
	DC_MOTOR_speed = speed;
	PF_DC_STATE = STATE(DC_MOTOR_busy);
	printf ("CA ---------- speed=%d ----------> DC\n" ,DC_MOTOR_speed);
}