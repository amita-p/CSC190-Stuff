#include "lab3.h"

void p1(void)
{
    int a[5]={0,4,5,19,23};
    int b[5]={1,4,5,19,23};
    printf("The first set of bits are set? %u\n", testBits(a, 5, 9131953));
    printf("The second set of bits are set? %u\n", testBits(b, 5, 9131953));
}

void p2(void)
{
    unsigned int b=9131953;
    int a[5]={1,2,8,18,21};
    setBits(a, 5, &b);
    printf("The result of setting bits is %u\n", b);
}

void p3(void)
{
    unsigned int b=11491255;
    int a[5]={1,2,8,18,21};
    clearBits(a, 5, &b);
    printf("The result of clearing bits is %u\n", b);
}

int main( int argc, char *argv[] )
{
    if( argc < 2 )
   	{
        printf("Expecting at least one argument. Please try again\n");
   	}
    else if(argc==2)
    {
        if(atoi(argv[1])==1)
        {
            p1();
        }
        else if(atoi(argv[1])==2)
        {
            p2();
        }
        else if(atoi(argv[1])==3)
        {
            p3();
        }
        else
        {
            printf("Incorrect argument supplied.\n");
        }
    }
    else
    {
        printf("Expecting one argument. Please try again.\n");
    }
}
