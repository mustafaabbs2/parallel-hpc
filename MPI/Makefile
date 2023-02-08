EXECS=mpi_hello_world mpi_hello_handshake
MPICC?=mpicc

all: ${EXECS}

mpi_hello_world: mpi_hello_world.c
	${MPICC} -o mpi_hello_world -ggdb mpi_hello_world.c

mpi_hello_handshake: mpi_hello_handshake.c
	${MPICC} -o mpi_hello_handshake -ggdb mpi_hello_handshake.c


clean:
	rm ${EXECS}