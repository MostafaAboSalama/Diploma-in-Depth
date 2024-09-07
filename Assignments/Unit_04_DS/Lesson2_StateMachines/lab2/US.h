#ifndef _US_H_
#define _US_H_

#include "states.h"



extern void (*PF_US_STATE)();

enum 
{
	US_busy
}US_STATE_ID;

/* Declare State Functions of US */
STATE_FUNC_DEFINE(US_busy);  //void ST_US_busy();

/* INIT */
void US_voidInit();



#endif /* _US_H_ */