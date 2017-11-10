/*
 * timer_28335.h
 *
 *  Created on: 2017Äê11ÔÂ10ÈÕ
 *      Author: Wiiboox
 */

#ifndef TIMER_28335_H_
#define TIMER_28335_H_

#include "DSP28x_Project.h"

enum TIMERSTATUS
{
    IDEL = 0,
    CONFIG = 1,
    START = 2,
    WAIT = 3,
    ELAPSED = 4,
    ABORT = 5
};

typedef struct SOFTTIMER
{
    Uint32 period;
    Uint32 mincounter;//use 100ms systerm interrupt for example
    Uint32 starttimer;
    Uint32 currenttimer;
    Uint32 endtimer;
    TIMERSTATUS timerstat;
}SoftTimer;

extern void TimerInit(SoftTimer *timer, Uint32 Mincounter, TIMESTATUS Timerstat);
extern void ConfigTimer(Uint32 timer);
extern TIMERSTATUS (*gettimerstatus)(void);
extern void refreshtimer(SoftTimer *timer);

#endif /* TIMER_28335_H_ */
