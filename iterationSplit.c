#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

void main()
{
    int it, i,iteration[8];
    printf("\nEnter number of iterations:\t");
    fflush(stdout);
    scanf("%d", &it);

    #pragma omp parallel for schedule(static,2)
    for(int i=1;i<=it;i++)
    {
        int t=omp_get_thread_num();
        iteration[t]+=1;
        printf("\nThread %d itern %d is having value %d",t,iteration[t],i);
        fflush(stdout);
    }


}
