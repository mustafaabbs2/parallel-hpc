#include <mpi.h>
#include <unistd.h>
#include <stdio.h>

int main(){

    {
        int i=0;
        while (0 == i)
            sleep(5);
    }

    MPI_Init(NULL, NULL);
    int rank,size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);


  // Print off a hello world message
  printf("Hello world, rank %d out of %d processors\n",
         rank, size);


    char data = 'A';
    
    if (rank==0) {
        data = 'B';
        MPI_Send( &data , 1 , MPI_INT , 1 , 0 , MPI_COMM_WORLD);
    }
    else if (rank==1){
        MPI_Recv( &data , 1 , MPI_INT , 0 , 0 , MPI_COMM_WORLD , MPI_STATUS_IGNORE);
    }

MPI_Finalize();

return 0;

} 