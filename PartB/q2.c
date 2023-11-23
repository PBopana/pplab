#include <mpi.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
    MPI_Init(&argc, &argv);
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    int number;
    if (world_rank == 0)
    {
        number = 0;
        // Process 0 sends a message to process 1 and waits for process 1 to receive it.
        MPI_Ssend(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        MPI_Recv(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }
    else if (world_rank == 1)
    {
        number = 1;
        // Process 1 sends a message to process 0 and waits for process 0 to receive it.
        MPI_Ssend(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
        MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }
    MPI_Finalize();
    return 0;
 }
