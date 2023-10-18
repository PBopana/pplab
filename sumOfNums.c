//sum of numbers from 1 to 100 using critical directive
#include<stdlib.h>
#include<stdio.h>
#include<omp.h>

void main()
{
    int n=100, sum=0;

    #pragma omp parallel for
    for(int i=1;i<=n;i++)
    {
        #pragma omp critical
        sum+=i;
    }

    printf("\nSum of numbers from 1 to 100 is: %d",sum);
    fflush(stdout);
}
