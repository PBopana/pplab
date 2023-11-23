1. MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_rank: This is the MPI function to get the rank of the calling process within the specified communicator.
    MPI_COMM_WORLD: This is a predefined communicator that essentially represents the entire group of MPI processes.
    &world_rank: This is the variable that will store the rank of the calling process. 

2. MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    MPI_Comm_size: This is the MPI function to get the total number of processes in the specified communicator.
    &world_size: This is the variable that will store the total number of processes. 

3. MPI_Finalize(): 
    MPI_Finalize: It marks the end of the MPI operations.

4. MPI_Send(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
    MPI_Send: This function sends a message from the calling process to a specified process. The parameters are:
    &number: The address of the data to be sent.
    1: The number of data elements to be sent.
    MPI_INT: The data type of the elements.
    1: The rank of the the process to which the message will be sent.
    0: A tag or message identifier

//ly for MPI_Recv()
