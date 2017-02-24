#include "lab2.h"

//filename is a pointer to the array of chars 
//matrix is a pointer to the array of ints 
void readMatrix(char * filename, int * matrix)
{
	FILE *fp=fopen(filename,"r"); //pointer to contents in file
	// *matrix is the array of ints that we're modifying
	int j=0;
	int i=0;
	int k=0;
	for (i=0;i<MATSIZE*MATSIZE;i++)
	{
		fscanf(fp,"%d",matrix+i);
	}
	fclose(fp);
} 

void printMatrix(int n, int *A)
{
	int i=0;
	for (i=0;i<n*n;i++)
	{
		if((i+1)%n==0)
		{
			printf("%d\n",A[i]);
		}
		else
		{
			printf("%d ",A[i]);
		}	
	}
	
}

void sum(int *A, int *B, int *res, int n)
{
	int i;
	for (i=0;i<n*n;i++)
	{
		res[i]=A[i]+B[i];
	}	
}

void sub(int *A, int *B, int *res, int n)
{
	int i;
	for (i=0;i<n*n;i++)
	{
		res[i]=A[i]-B[i];
	}	
}

int determinant(int n, int *matrix)
{
	if (n==2)
	{
		return matrix[0]*matrix[3]-matrix[1]*matrix[2];
	}
	else if (n==1)
	{	
		return matrix[0];
	}
	else
	{
		int i;
		int k=0;
		int det=0;
		int j;
		for (i=0;i<n;i++)
		{
			int matrix2[n-1][n-1];
			int *matrix2p=(int *)matrix2;
			for (j=0;j<n*n;j++)
			{
				if ( ((j-i)%n)!=0 && j>=n)
				{
					matrix2p[k]=matrix[j];
					k++;
				} 
			}
			k=0;	
			det+=pow(-1,i+2)*matrix[i]*determinant(n-1,matrix2p);	
		}
		return det;		

	}
	
}



