#include <stdio.h>
#include <mpi.h>
int main()
{
    MPI_Init(NULL, NULL);
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    // Each process uses its rank as the data
    int data = world_rank;
    int max_val, min_val, sum, prod;
    // Allreduce to find the maximum value
    MPI_Allreduce(&data, &max_val, 1, MPI_INT, MPI_MAX, MPI_COMM_WORLD);
    // Allreduce to find the minimum value
    MPI_Allreduce(&data, &min_val, 1, MPI_INT, MPI_MIN, MPI_COMM_WORLD);
    // Allreduce to find the sum of all values
    MPI_Allreduce(&data, &sum, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
    // Allreduce to find the product of all values
    MPI_Allreduce(&data, &prod, 1, MPI_INT, MPI_PROD, MPI_COMM_WORLD);
    // Each process prints the results
    printf("Process %d - Max: %d, Min: %d, Sum: %d, Product: %d\n", world_rank, max_val, min_val, sum, prod);
    MPI_Finalize();
    return 0;
}

/* MPI_Allreduce -
    &data: Address of the data to be reduced.
    &max_val: Address where the result of the reduction
    1: The number of elements in the send buffer.
    MPI_INT: Data type of the elements in the send buffer (in this case, integers).
    MPI_MAX: Specifies the operation to be applied during the reduction
    MPI_COMM_WORLD: Communicator, a group of processes that can communicate with each other.
*/
