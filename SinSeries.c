#include<stdio.h>
#include<math.h>

#define pi 22/7

long int fact(long int x);
double sine(double xrad, long int NT, long int (*funcptr)());

void main()
{
    long int NT;
    double sinx, xdeg, xrad;
    
    printf("\nEnter value of X in degree: ");
    scanf("%lf", &xdeg);
    
    xrad = xdeg * pi/180;
    
    printf("xrad = %lf\n", xrad);
    
    printf("\nEnter the number of terms: ");
    scanf("%ld", &NT);
    
    sinx = sine(xrad, NT, fact);
    
    printf("\nSin(%lf) = %lf\n\n", xdeg, sinx);
}

double sine(double xrad, long int NT, long int (*funcptr)())
{
    int i, sign = 1;
    double sinx = 0;
    
    for(i=1; i<=NT; i+=2)
    {
        sinx = sinx + sign * pow(xrad, i)/(*funcptr)(i);
        sign = -sign;
    }
    return sinx;
}

long int fact(long int x)
{
    if(x == 0 || x == 1)
        return 1;
    else
        return (x * fact(x - 1));
}