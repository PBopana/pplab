#include <stdio.h>
#include <mpi.h>
int main() {
    int world_rank,world_size;
    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    int number;
    // Root process is the one that broadcasts, so only it can initialise data
    if (world_rank == 0) {
        number = 42;
        printf("Process 0 broadcasting number %d to all processes\n", number);
    }
    // Broadcast the number from the root process to all processes
    MPI_Bcast(&number, 1, MPI_INT, 0, MPI_COMM_WORLD);
    // Print the received data at each process
    printf("Process %d received number %d\n", world_rank, number);
    MPI_Finalize();
    return 0;
}
