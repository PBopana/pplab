#include <stdio.h>
#include <mpi.h>
int main()
{
    MPI_Init(NULL, NULL);
    int world_rank, world_size;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    // Print information about the current phase(1)
    printf("Phase 1, Process %d of %d\n", world_rank, world_size);
    // Ensures that all processes reach the same point in their execution - Sync
    MPI_Barrier(MPI_COMM_WORLD); 
    // Print information about the next phase(2)
    printf("Phase 2, Process %d of %d\n", world_rank, world_size);
    MPI_Finalize();
    return 0;
}
