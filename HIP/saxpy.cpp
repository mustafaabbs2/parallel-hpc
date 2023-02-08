#include <cuda_runtime.h>
#include <iostream>

__global__ void saxpy(int n, float a, float* x, float* y)
{
    int i = blockDim.x * blockIdx.x + threadIdx.x;
    if (i < n)
    {
        y[i] = a * x[i] + y[i];
    }
}

int main()
{
    int n = 100;
    float a = 2.0;
    float *x, *y;
    cudaMalloc((void**)&x, n * sizeof(float));
    cudaMalloc((void**)&y, n * sizeof(float));
    // saxpy << 32, 32 >> (n, a, x, y);
    cudaFree(x);
    cudaFree(y);
    return 0;
}