#include "lab7.h"

struct Node * insertBST(struct Node * r, struct Data d){
	if (n==	NULL){
		struct Node *newNode=(struct Node *)malloc(sizeof(struct Node);
		newNode->d=d;
		return newNode;
	}
	else{
		if (n->d.data>d.data){
			n->lChild=insertR(n->lChild, d);
		}
		else if (n->d.dat<d.data){
			n->rChild=insertR(n->rChild, d);
		}
	}
	return n;
}

void printInOrder(struct Node * r){
	if (r!=NULL)
	{
		printInOrder(r->lChild);
		printf("%d ",r->d.data);
		printInOrder(r->rChild);
	}
}

void deleteTree(struct Node * r){
	if (r==NULL)
	{
		
	}
}

void printBSTs(struct Node * r1, struct Node * r2){

}
