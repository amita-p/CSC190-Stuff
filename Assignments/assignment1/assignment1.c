#include "assignment1.h"

double ** choleskyDecomp(double ** A, int n, int i)
{
	
	if (identity(A,n))
	{
		return A;		
	}
	else
	{
		i=i+1;
		double **nextA;
		initMatrix(&nextA, n);
		double **L;
		initMatrix(&L,n);
		int k;
		int j;
		//CREATING NEXTA
		//adding identity matrix to nextA
		for (k=0;k<i;k++)
		{
			nextA[k][k]=1;
		}
		double B[n-i][n-i];
		double V[n-i];
		double VVT[n-i][n-i];
		//filling in V
		for (k=i;k<n;k++)
		{
			V[k-i]=A[i-1][k];
		}
		//filling in VVT
		for (j=0;j<n-i;j++)
		{
			for (k=0;k<n-i;k++)
			{
				VVT[j][k]=(V[j]*V[k])/A[i-1][i-1];
			}
		}
		//filling in B
		for (j=i;j<n;j++)
		{
			for (k=i;k<n;k++)
			{
				B[j-i][k-i]=A[j][k];
			}
		}
		//completing nextA
		for (k=i;k<n;k++)
		{
			for (j=i;j<n;j++)
			{
				nextA[k][j]=B[k-i][j-i]-VVT[k-i][j-i];
			}
		}

		//CREATING L

		//adding identity matrix to L
		for (k=0;k<i-1;k++)
		{
			L[k][k]=1;
		}
		L[i-1][i-1]=sqrt(A[i-1][i-1]);
		for (k=i;k<n;k++)
		{
			L[k][i-1]=V[k-i]/sqrt(A[i-1][i-1]);
		}
		//adding another identity to L
		for (k=i;k<n;k++)
		{
			L[k][k]=1;
		}
		
		double **product=mult(L,choleskyDecomp(nextA,n,i),n);
		freeMatrix(A,n);			
		return product;
	}
	
}

double ** mult(double ** L1,double ** L2, int n)
{
	
	double **product;
	initMatrix(&product,n);
	
	int i;
	int j;
	int k;
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			product[i][j]=0;
			for (k=0;k<n;k++)
			{
				product[i][j]+=L1[i][k]*L2[k][j];
			}		
		}	
	}
	if (&(*L1)==&(*L2))
	{
		freeMatrix(L1,n);
	}
	else
	{
		freeMatrix(L1,n);
		freeMatrix(L2,n);
	}
	
	return product;
}

int identity(double ** A, int n)
{
	int isIdentity=1;
	int i;
	int k;
	for (i=0;i<n;i++)
	{
		/*for (k=0;k<n;k++)
		{
			if (k==i && A[k][k]!=1)
			{
				isIdentity=0;
			}
			else
			{
				if (A[i][k]!=0)
				{
					isIdentity=0;
				}
			}
		}*/
		if (A[i][i]!=1)
		{
			isIdentity=0;
		}
	}
	return isIdentity;
}


void initMatrix(double ***mat,int n)
{
	double **a=(double**)malloc(n*sizeof(double*));
	int i,j;
	for (i=0;i<n;i++)
	{
		a[i]=(double*)malloc(n*sizeof(double));
		for (j=0;j<n;j++)
		{
			a[i][j]=0.0;
		}
	}
	*mat=a;
}

double **readMatrix(char * filename)
{
	double **mat;
	initMatrix(&mat,MATSIZE);
	FILE *fp=fopen(filename, "r");
	int i,j;
	for (i=0;i<MATSIZE;i++)
	{
		for (j=0;j<MATSIZE;j++)
		{
			fscanf(fp,"%lf",&(mat[i][j]));
		}
		
	}
	fclose(fp);	
	return mat;
}

void freeMatrix(double ** matrix, int n)
{
	int i;
	int j;
	for (i=0;i<n;i++)
	{
		free(matrix[i]);
	}
	free(matrix);	
}

void printMatrix(double ** A, int n)
{
	int i,j=0;
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			if(j==n-1)
			{
				printf("%f\n",A[i][j]);
			}
			else
			{
				printf("%f ",A[i][j]);
			}
		}
	}
	

}


