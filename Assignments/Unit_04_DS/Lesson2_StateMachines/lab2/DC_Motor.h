#ifndef _DC_MOTOR_H_
#define _DC_MOTOR_H_

#include "states.h"



extern void (*PF_DC_STATE)();

enum 
{
	DC_MOTOR_idle,
	DC_MOTOR_busy
}DC_MOTOR_STATE_ID;

STATE_FUNC_DEFINE(DC_MOTOR_idle);
STATE_FUNC_DEFINE(DC_MOTOR_busy);


void DC_MOTOR_voidInit();




#endif /* _DC_MOTOR_H_ */