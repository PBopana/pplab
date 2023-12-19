#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int fib(int n)
{
    int first, second;
    if(n<2)
        return n;
    else
    {
        #pragma omp task shared(first) firstprivate(n)
        first=fib(n-1);

        #pragma omp task shared(second) firstprivate(n)
        second=fib(n-2);

        #pragma omp taskwait
        return first+second;

    }
}

void main(){
    int n = 10;
    double start = omp_get_wtime();
    #pragma omp parallel for
    for(int i=0;i<n;i++){
        int t = omp_get_thread_num();
        printf("thread: %d fib(%d) = %d\n",t,i,fib(i));
        fflush(stdout);
    }
    double end = omp_get_wtime();
    printf("using schedule time is : %f\n",end-start);
    fflush(stdout);
    return;
}
