#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main(int argc, char const *argv[])
{
    int n=100000;
    double pi=0;
    int i;

    double start=omp_get_wtime();
    
    // OpenMP parallelized loop for computing pi
    #pragma omp parallel for private(i)
    for(int i=0;i<n;i++)
    {
        // Calculate alternating series term
        double num = i%2==0?1:-1;
        // Update pi using the Leibniz formula
        pi+=(num/(2*i+1));
    }
    
    // Multiply pi by 4 to get the final approximation
    pi*=4;
    double stop=omp_get_wtime();

    printf("Time is %lf",(double)(stop-start));
    fflush(stdout);
    printf("\nPi =%lf",pi);
    fflush(stdout);

}
