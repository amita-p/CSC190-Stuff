#include "lab4.h"

struct ExpressLaneRec * initExpressLane(float enterTime, float exitTime)
{
	struct ExpressLaneRec *e=(struct ExpressLaneRec *)malloc(sizeof(struct ExpressLaneRec));
	e->enterTime=enterTime;
	e->exitTime=exitTime;
	e->car=NULL;
	e->nextRec=NULL;
	return e;
	
}

struct ExpressLaneRec * addCarRec(struct Car * c, float enterTime, float exitTime, struct ExpressLaneRec * eL)
{
	struct ExpressLaneRec *newRec=initExpressLane(enterTime, exitTime);
	newRec->car=c;
	if (eL!=NULL)
	{
		eL->nextRec=newRec;
	}
	return newRec;
}

void printRecords(struct ExpressLaneRec * eLCurr)
{
	struct ExpressLaneRec *pointer=eLCurr;
	while(pointer!=NULL)
	{
		printf("Car enter time is %f",pointer->enterTime);
		printf("Car exit time is %f",pointer->exitTime);
		printCarState(pointer->car);
		pointer=pointer->nextRec;
	}
}

void cleanUpRec(struct ExpressLaneRec * eL)
{
	struct ExpressLaneRec *pointer=eL;
	struct ExpressLaneRec *temp=eL;
	while (pointer!=NULL)
	{
		cleanUpCar(pointer->car);
		temp=pointer;
		pointer=pointer->nextRec;
		free(temp);
		temp=NULL;
	}
}

