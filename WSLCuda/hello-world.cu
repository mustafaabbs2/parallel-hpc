#include <iostream>

__global__ void helloFromGPU(void) { printf("Hello World from GPU! \n"); }

int main()
{
    printf("Hello World from GPU! \n");
    helloFromGPU<<<1, 10>>>();
    cudaDeviceReset();
    return 0;
}