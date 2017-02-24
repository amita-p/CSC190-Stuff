#include "assignment3.h"

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
	for (i=0;i<NODES;i++){
		fN->visitedNodes[i]=0;
	}
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
void maximizeFlowNetwork(struct flowNetwork * fN, int s, int t){
	
	int parent;
	int t2;
	int max;
	
	while (breadthFirstPathSearch(fN, s, t)!=0){
	
			t2=t;
			max=INF;
			while (t2!=s)
			{
				parent=fN->parent[t2];
				if (((fN->adjMatrix)[parent][t2].flowCap-(fN->adjMatrix)[parent][t2].flow)<max)
				{
					max=(fN->adjMatrix)[parent][t2].flowCap-(fN->adjMatrix)[parent][t2].flow;
				}
				t2=parent;
				
			}	
			t2=t;
			while (t2!=s)
			{
				parent=fN->parent[t2];
				((fN->adjMatrix)[parent][t2].flow)+=max;
				t2=parent;
				
			}
						
	
	}
}
