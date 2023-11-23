#include <stdio.h>
#include <mpi.h>
int main()
{
    int world_rank, world_size;
    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    // Array to hold data to be scattered
    int data[world_size];
    // Root process(rank 0) initialises the array
    if (world_rank == 0)
    {
        for (int i = 0; i < world_size; i++) 
            data[i] = i; 
    }
    int recv_data; 
    // Scatter the data from the root process to all processes
    MPI_Scatter(data, 1, MPI_INT, &recv_data, 1, MPI_INT, 0, MPI_COMM_WORLD);
    // Print recieved data at each process
    printf("Process %d received data %d\n", world_rank, recv_data);
    MPI_Finalize();
    return 0;
}
