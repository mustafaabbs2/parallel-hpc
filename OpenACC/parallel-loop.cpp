#include <iostream>

const int N = 100000;

int main()
{
    float a[N], b[N], c[N];

    // Initialize arrays
    for (int i = 0; i < N; i++)
    {
        a[i] = i;
        b[i] = 2 * i;
    }

// Parallelize loop
#pragma acc parallel loop
    for (int i = 0; i < N; i++)
    {
        c[i] = a[i] + b[i];
    }

    // Print result
    std::cout << c[0] << " " << c[N - 1] << std::endl;

    return 0;
}

// g++ -fopenacc -o parallel-loop parallel-loop.cpp


