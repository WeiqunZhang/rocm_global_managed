#include "par.H"
#include <hip/hip_runtime.h>
#include <iostream>

template <class F> __global__ void launch_global (F f) { f(); }

void work ()
{
    int* dp = nullptr;
    hipMalloc((void**)&(dp), sizeof(int)*3);

    launch_global<<<1,1>>>([=] __device__ ()
    {
        dp[0] = d_a;
        dp[1] = d_b[0];
        dp[2] = d_b[1];
    });

    int hp[3] = {6, 6, 6};
    hipMemcpyDtoH(hp, dp, sizeof(int)*3);

    hipDeviceSynchronize();
    hipFree(dp);

    if (hp[0] == 1 && hp[1] == 2 && hp[2] == 3) {
        std::cout << "Pass." << std::endl;
    } else {
        std::cout << "Fail. It should print 1, 2, 3. Instead it prints "
              << hp[0] << ", " << hp[1] << ", " << hp[2] << std::endl;
    }
}
