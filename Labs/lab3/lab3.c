#include "lab3.h"

int testBits(int * a, int n, unsigned int regVar)
{
	int i;
	int num;
	for (i=0;i<n;i++)
	{
		num=(regVar & (1 << a[i])) >> a[i];
		if (num!=1)
		{
			return 0;
		}
	}
	return 1;
}

void setBits(int * a, int n, unsigned int * regVar)
{
	int i;
	for (i=0;i<n;i++)
	{
		*regVar=(*regVar |=1 << a[i]);
	}
}

void clearBits(int * a, int n, unsigned int * regVar)
{
	int i;
	for (i=0;i<n;i++)
	{
		*regVar=(*regVar &= ~(1 << a[i]));
	}
}
