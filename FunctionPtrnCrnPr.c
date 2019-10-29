//C program to find nPr and nCr using function pointer and recursion.

#include<stdio.h>

int fact(int n)
{
    if(n>1)
        return n*fact(n-1);
    else
        return 1;
}

float npr(int (*fun_ptr)(), int n, int r)
{
    return (*fun_ptr)(n)/(*fun_ptr)(n-r);
}

float ncr(int (*fun_ptr)(), int n, int r)
{
    return (*fun_ptr)(n)/((*fun_ptr)(n-r)*(*fun_ptr)(r));
}

int main()
{
    int n, r, res;
    printf("Enter positive integers(n & r): ");
    scanf("%d%d", &n, &r);
    printf("nPr = %.4f\n", npr(fact, n, r));
    printf("nCr = %.4f\n", ncr(fact, n, r));
    return 0;
}