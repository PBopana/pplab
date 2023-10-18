#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<time.h>

int isPrime(int n)
{
    if(n==0||n==1)
        return 0;
    for(int i=2;i<=n/2;i++)
    {
        if(n%i==0)
        {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    int n;
    printf("\nEnter number upto which primes be generated:\t");
    fflush(stdout);
    scanf("%d",&n);

    printf("\nSerially");
    fflush(stdout);
    double start=clock();
    for(int i=1;i<=n;i++)
    {
        if(isPrime(i))
        {
            printf("\n%d",i);
            fflush(stdout);
        }
    }
    double end= clock();

    printf("\nTime taken serially is %lf",(double)(end-start));
    fflush(stdout);

     printf("\nParallely");
    fflush(stdout);

    start=omp_get_wtime();
    #pragma omp parallel for
    for(int i=1;i<=n;i++)
    {
        if(isPrime(i))
        {
            printf("\n%d",i);
            fflush(stdout);
        }
    }
    end=omp_get_wtime();

    printf("\nTime taken parallely is %f",(end-start));
    fflush(stdout);

}
