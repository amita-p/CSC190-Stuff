#include "lab1.h"

float S(float a, float b)
{
	float m=(a+b)/2;
	return ((b-a)/6)*(f(a)+4*f(m)+f(b));    
}
