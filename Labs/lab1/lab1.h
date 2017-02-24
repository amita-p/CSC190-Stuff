#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define ARRAYSIZE 100

float f(float x);
void simpsonsAdaptiveIntegration(float aOrig, float bOrig, float eps, float minIntSize);
float S(float a, float b);
int satisfied(float a, float b, float eps);
