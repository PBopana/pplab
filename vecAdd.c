#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<omp.h>

void addSerially(int a[], int b[], int c[], int n)
{
    for(int i=0;i<n;i++)
    {
        c[i]=a[i]+b[i];
    }
}

void ParallelAdd(int a[], int b[], int c[], int n)
{
    #pragma omp parallel for
    for(int i=0;i<n;i++)
    {
        c[i]=a[i]+b[i];
    }
}

int main(int argc, const char *argv[])
{
    int n;
    printf("\nEnter number of terms:\t");
    fflush(stdout);
    scanf("%d",&n);
    int a[n], b[n], c[n];

    for(int i=0;i<n;i++)
    {
        a[i]=rand()%1000;
        b[i]=rand()%1000;
    }

    double start = clock();
    ParallelAdd(a,b,c,n);
    double end= clock();
    printf("\nTime taken serially is= %lf\n",(double)(end-start));


    start = omp_get_wtime();
    ParallelAdd(a,b,c,n);
    end = omp_get_wtime();
    printf("\nTime taken parallely is= %f\n",(double)(end-start));

    for(int i=0;i<n;i++)
    {
        printf("%d\n",c[i]);
        fflush(stdout);
    }
    return 0;
}
