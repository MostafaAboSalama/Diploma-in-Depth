#ifndef _CA_H_
#define _CA_H_

#include "states.h"
#include <stdio.h>
#include <stdlib.h>



extern void (*PF_CA_STATE)();

enum
{
	CA_waiting,
	CA_driving
}CA_STATE_ID;

STATE_FUNC_DEFINE(CA_waiting);
STATE_FUNC_DEFINE(CA_driving);






#endif /* _CA_H_ */