#include "lab8.h"

struct flowNetwork * initFlowNetwork(){
	struct flowNetwork * network=(struct flowNetwork *)malloc(sizeof(struct flowNetwork));
	network->adjMatrix=initAdjMatrix();
	int i;
	for (i=0;i<NODES;i++)
	{
		network->visitedNodes[i]=0;
		network->parent[i]=-1;
	}
	
	return network;		
}

void deleteFlowNetwork(struct flowNetwork * fN){
	deleteAdjMatrix(fN->adjMatrix);
	free(fN);
	fN=NULL;	
}

int isInArray(int array[], int num)
{
	int i;
	for (i=0;i<NODES;i++)
	{
		if (array[i]==num){
			return 1;
		}
	}
	return 0;
}
int breadthFirstPathSearch(struct flowNetwork * fN, int s, int d){
	struct Queue * queue;
	initQueue (&queue);
	struct Data data;
	data.vertex=s;
	enqueue(queue,data);
	int i;
	while (!isQueueEmpty(queue))
	{
		struct Data data2;
		dequeue (queue, &data2);
		struct Edge ** matrix=fN->adjMatrix;
		for (i=0;i<NODES;i++)
		{
			if((matrix[data2.vertex][i].flowCap)>0 && i!=data2.vertex)
			{
				if ((fN->visitedNodes)[i]==0 && ((matrix[data2.vertex][i].flowCap-matrix[data2.vertex][i].flow)>0))
				{
					(fN->parent)[i]=data2.vertex;
					struct Data data3;
					data3.vertex=i;
					enqueue(queue,data3);
					(fN->visitedNodes)[i]=1;
					
				}
			}
		}
				
	}
	free(queue);
	queue=NULL;
	if ((fN->visitedNodes[d])==1)
	{
		return 1;
	}
	else
	{
		return 0;
	}		
}
