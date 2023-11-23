// Deadlock avoidance by chnaging call sequence
#include <stdio.h>
#include <mpi.h>
int main() 
{
    int world_size,world_rank;
    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    if (world_size < 2) {
        printf("World size must be greater than 1\n");
        MPI_Finalize();
        return 0;
    }
    int number;
    if (world_rank == 0) {
        number = 0;
        // Process 0 sends a synchronous message to Process 1
        MPI_Ssend(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        // Blocking receive from process 1
        MPI_Recv(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Process 0 received number %d from process 1\n", number);
    }
    else if (world_rank == 1)
    {
        number = 1;
        // Blocking receive from process 0
        MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        // Process 1 sends a synchronous message to Process 0
        MPI_Ssend(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
        printf("Process 1 sent number %d to process 0\n", number);
    }
    MPI_Finalize();
    return 0;
}
