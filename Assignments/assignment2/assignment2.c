#include "assignment2.h"

double calcAverageWaitingTime(struct Simulation * S)
{
	double avg=0;
	struct Node * pointer=S->eventQueue.front;
	while (pointer!=NULL)
	{
		avg+=((pointer->data.departureTime)-(pointer->data.arrivalTime));
		pointer=pointer->next;
	}
	avg=avg/S->eventQueue.currSize;
	return avg;
}

struct Simulation initSimulation(double arrivalRate, double serviceTime, double simTime)
{
	struct Simulation s;
	s.currTime=0;
	s.arrivalRate=arrivalRate;
	s.serviceTime=serviceTime;
	s.timeForNextArrival=getRandTime(arrivalRate);
	s.timeForNextDeparture=serviceTime+s.timeForNextArrival;
	s.totalSimTime=simTime;
	s.buffer=initQueue();
	s.eventQueue=initQueue();
	s.e=ARRIVAL;
	return s;	
}

double runSimulation(double arrivalRate, double serviceTime, double simTime)
{
	struct Simulation s=initSimulation(arrivalRate,serviceTime,simTime);
	while (s.currTime<s.totalSimTime)
	{
		if (s.e==ARRIVAL)
		{
			s.currTime=s.timeForNextArrival;
			struct Data d;
			d.arrivalTime=s.timeForNextArrival;
			enqueue(&(s.buffer),d);
			s.timeForNextArrival=s.currTime+getRandTime(s.arrivalRate);
		}
		else if (s.e==DEPARTURE)
		{
			s.currTime=s.timeForNextDeparture;
			struct Data d=dequeue(&s.buffer);
			d.departureTime=s.currTime;
			enqueue(&(s.eventQueue),d);
			if(s.buffer.currSize>0){
				s.timeForNextDeparture=s.currTime+serviceTime;
			}
			else{
				s.timeForNextDeparture=s.timeForNextArrival+serviceTime;
			}
		}
		if (s.timeForNextArrival<s.timeForNextDeparture)
		{
			s.e=ARRIVAL;
		}
		else
		{
			s.e=DEPARTURE;
		}
	}
	double avg=calcAverageWaitingTime(&s);
	freeQueue(&(s.eventQueue));
	freeQueue(&(s.buffer));	
	return avg;
}
