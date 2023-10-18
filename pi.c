#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main(int argc, char const *argv[])
{
    int n=100000;
    double pi=0;
    int i;

    double start=omp_get_wtime();
    #pragma omp parallel for private(i)
    for(int i=0;i<n;i++)
    {
        double num = i%2==0?1:-1;
        pi+=(num/(2*i+1));
    }

    pi*=4;
    double stop=omp_get_wtime();

    printf("Time is %lf",(double)(stop-start));
    fflush(stdout);
    printf("\nPi =%lf",pi);
    fflush(stdout);

}
