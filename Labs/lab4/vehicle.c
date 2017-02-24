#include "lab4.h"

struct Vehicle * initVehicle(int wheels, char * model, struct vInterface vInt)
{
	struct Vehicle *v=(struct Vehicle *)malloc(sizeof(struct Vehicle));
	v->numWheels=wheels;
	strcpy(v->model,model);
	v->vehInt=vInt;
	return v;

}

void cleanUpVehicle(struct Vehicle * v)
{
	free(v);
	v=NULL;
}
