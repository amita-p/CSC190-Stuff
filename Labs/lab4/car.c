#include "lab4.h"

int setSpeed(int speed)
{
	if (speed<=260)
	{
		return speed;
	}
	else
	{
		return -1;
	}
}

int setGear(int gear)
{
	if (gear<=5)
	{
		return gear;
	}
	else
	{
		return -1;
	}
}

int setPassengers(int passengers)
{
	if (passengers<=5)
	{
		return passengers;
	}
	else
	{
		return -1;
	}

}

void setCarState(struct Car * c, int speed, int gear, int passengers, int nav){
	c->hasNav=nav;
	c->veh->numPassengers=(*(c->veh->vehInt.setPassengers))(passengers);
	c->veh->currSpeed=(*(c->veh->vehInt.setSpeed))(speed);
	c->veh->gear=(*(c->veh->vehInt.setGear))(gear);
}

void printCarState(struct Car * c){
	printf("Speed of the Car is: %d ",c->veh->currSpeed);
        printf("Gear of the Car is set at: %d ",c->veh->gear);
        printf("Passengers in the Car are: %d ",c->veh->numPassengers);
        printf("Navigator in the Car: %d ", c->hasNav);

}

struct Car * initCar(int nav, char * model)
{
	struct Car *c=(struct Car*)malloc(sizeof(struct Car));
	c->hasNav=nav;
	c->veh=initVehicle(4,model,initVInterface(&setSpeed,&setGear,&setPassengers));	
	c->setCarState=setCarState;	
}
                       
void cleanUpCar(struct Car * c)
{
	cleanUpVehicle(c->veh);
	free(c);
	c=NULL;	

}
   
