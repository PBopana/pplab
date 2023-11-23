#include <mpi.h>
#include <stdio.h>
int main()
{
	MPI_Init(NULL, NULL);
	int world_rank, world_size;
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    	// Check if there are at least two processes
	if (world_size < 2) 
	{
		printf("The number of processors should be at least 2\n");
		MPI_Finalize();
		return 0;
	}
	int number = 7;
	if (world_rank == 0)
	{
		// Process 0 sends the number to process 1
		MPI_Send(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
		printf("Process 0 sent number %d to process 1\n", number);
	}
	else 
	{
		// Process 1 receives the number from process 0
		MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		printf("Process 1 received number %d from process 0\n", number);
	}
	MPI_Finalize();
	return 0;
}
