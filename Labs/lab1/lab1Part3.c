#include "lab1.h"

void simpsonsAdaptiveIntegration(float aOrig, float bOrig, float eps, float minIntSize)
{
	float intervals[(int)(((bOrig-aOrig)/0.00001)+1)];
	intervals[0]=aOrig;
	intervals[1]=bOrig;
	int arraySize=2;
	float intervals2[(int)(((bOrig-aOrig)/0.00001)+1)];
	int splitted=1;
	float area=0;
	float m = 0.5*(aOrig+bOrig);
	int k;
	int j;
	int i=0;
	int l;
	float a;
	float b;
	
	
	while (splitted==1)
	{
		splitted=0;
		for(i=0;i<arraySize-1;i++)
		{
			a=intervals[i];
			b=intervals[i+1];
			if (satisfied(a,b,eps)==1 || (b-a)<=minIntSize )
			{
				//continue;
			}
			else
			{
       				for (k=0;k<=i;k++)
       				{
               				 intervals2[k]=intervals[k];
       				}
       				intervals2[i+1]=0.5*(intervals[i]+intervals[i+1]);
        			for (j=i+1;j<arraySize;j++)
        			{
               				 intervals2[j+1]=intervals[j];
       				}

				arraySize++;
				for (l=0;l<arraySize;l++)
				{                                
					intervals[l] =intervals2[l];
				}
				splitted=1;
			}		
		}
	}
	for (i=0;i<arraySize-1;i++)
	{
		a=intervals[i];
		b=intervals[i+1];
		area+=S(a,b);
	}

	printf("Result is: %f\n",area);		
}

int satisfied (float a, float b,float eps) 
{
	float m=(a+b)/2;
	float num=(fabs(S(a,m)+S(m,b)-S(a,b)))/15;
	if (num<eps)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

