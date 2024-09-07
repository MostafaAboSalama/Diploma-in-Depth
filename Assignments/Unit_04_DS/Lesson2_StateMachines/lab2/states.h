#ifndef _STATES_H_
#define _STATES_H_

#include <stdio.h>
#include <stdlib.h>


#define STATE_FUNC_DEFINE(STATE_FUNC_)	void ST_##STATE_FUNC_()
#define STATE(STATE_FUNC_)	ST_##STATE_FUNC_


void DC_MOTOR_voidMove(int speed);
void SetCarState(int distance);







#endif /* _STATES_H_ */