#include "lab8.h"

struct Edge ** initAdjMatrix(){
	struct Edge ** matrixPtr =(struct Edge **)malloc(sizeof(struct Edge *)*NODES);
	int i,k;
	for (i=0;i<NODES;i++)
	{
		matrixPtr[i]=(struct Edge *)malloc(sizeof(struct Edge)*NODES);
	}
	for (i=0;i<NODES;i++)
	{
		for (k=0;k<NODES;k++)
		{
			matrixPtr[i][k].flow=0;
			matrixPtr[i][k].flowCap=0;
		}
	}
	return matrixPtr;
}

void insertAdjMatrix(struct Edge ** aM, int vi, int vj, int flow, int flowCap){
	aM[vi][vj].flow=flow;
	aM[vi][vj].flowCap=flowCap;
}

void deleteAdjMatrix(struct Edge ** aM){
	int i;
	for (i=0;i<NODES;i++)
	{
		free(aM[i]);	
		aM[i]=NULL;
	}
	free(aM);
	aM=NULL;
}

void printAdjMat(struct Edge ** aM){
	//Edge: (0, 1) Flow: 0 Max Cap: 5 
	int i,k;
	for (i=0;i<NODES;i++)
	{
		for (k=0;k<NODES;k++)
		{
			if (aM[i][k].flowCap>0)
			{
				printf("Edge: (%d, %d) Flow: %d Max Cap: %d \n", i, k, aM[i][k].flow, aM[i][k].flowCap);
			}
		}
	}
}
