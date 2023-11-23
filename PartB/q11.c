#include <stdio.h>
#include <mpi.h>
int main()
{
    int world_rank;
    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    // Each process will use its rank as the data
    int data = world_rank;
    int max_val, min_val, sum, prod;
    // Reduce to find the maximum value
    MPI_Reduce(&data, &max_val, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);
    // Reduce to find the minimum value
    MPI_Reduce(&data, &min_val, 1, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD);
    // Reduce to find the sum of all values
    MPI_Reduce(&data, &sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    // Reduce to find the product of all values
    MPI_Reduce(&data, &prod, 1, MPI_INT, MPI_PROD, 0, MPI_COMM_WORLD);
    // The root process prints the results
    if (world_rank == 0)
    {
        printf("Max value: %d\n", max_val);
        printf("Min value: %d\n", min_val);
        printf("Sum of all ranks: %d\n", sum);
        printf("Product of all ranks: %d\n", prod);
    }
    MPI_Finalize();
    return 0;
}
/* MPI_Reduce() - 
    &data: Address of the data to be reduced.
    &max_val: Address the result of the reduction will be stored
    1: The number of elements in the send buffer.
    MPI_INT: Data type of the elements in the send buffer (in this case, integers).
    MPI_MAX: Specifies the operation to be applied during the reduction
    0: Root, the rank of the root process that will receive the result. Only the root process needs the receive buffer
    MPI_COMM_WORLD: Communicator, a group of processes that can communicate with each other.
*/
