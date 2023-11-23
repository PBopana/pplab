// Deadlock Avoidance Non blocking calls
#include <stdio.h>
#include <mpi.h>
int main()
{
    int world_rank,world_size;
    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    // MPI_Request for handling non-blocking calls
    MPI_Request request;
    MPI_Status status;
    // Check if there are at least 2 processes for communication
    if (world_size < 2)
    {
        printf("World size must be greater than 1\n");
        MPI_Finalize();
        return 0;
    }
    int number = 77;
    if (world_rank == 0)
    {
        // Non-blocking send from process 0 to 1, wait for its completion and then do non-blocking receive from process 1
        MPI_Isend(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, &request);
        MPI_Wait(&request, &status);
        MPI_Irecv(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, &request);
        MPI_Wait(&request, &status);
        printf("Process 0 received number %d from process 1\n", number);
    }
    else if (world_rank == 1)
    {
        // Non-blocking recieve from process 0, wait for its completion and then do non-blocking send from process 1 to 0
        MPI_Irecv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &request);
        MPI_Wait(&request, &status);
        MPI_Isend(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &request);
        MPI_Wait(&request, &status);
        printf("Process 1 sent number %d to process 0\n", number);
    }
    MPI_Finalize();
    return 0;
}
