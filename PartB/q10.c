#include <stdio.h>
#include <mpi.h>
int main() 
{
    int world_rank, world_size;
    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    // send_data - Data to be scattered from root process to all processes
    int send_data[4] = {32, 21, 12, 23};  
    int recv_data; // Variable to store data recieved by each process
    // distribute data from root process to all other processes
    MPI_Scatter(send_data, 1, MPI_INT, &recv_data, 1, MPI_INT, 0, MPI_COMM_WORLD);
    // Print the received data at each process
    printf("Process %d received data %d\n" , world_rank , recv_data); 
    recv_data += 10;
    // Synchronise all processes before proceeding
    MPI_Barrier(MPI_COMM_WORLD);
    // Gather the modified data from all processes to the root process
    int gathered_data[4];
    MPI_Gather(&recv_data, 1, MPI_INT, gathered_data, 1, MPI_INT, 0, MPI_COMM_WORLD);
    // Root process prints the gathered data
    if (world_rank == 0)
    {
        printf("Gathering data after increasing the value by 10\n");
        printf("Gathered data at root: ");
        for (int i = 0; i < world_size; i++,printf("\n"))
            {
                printf("%d ", gathered_data[i]);
            }
    }
    MPI_Finalize();
    return 0;
}
