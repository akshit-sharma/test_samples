#include <stdio.h>

#include "kernel_file.hpp"

__global__ void kernel_function() {
  printf("sizeof size_t from gpu : %ld\n", sizeof(size_t));
  printf("sizeof int from gpu : %ld\n", sizeof(int));
}

void run_kernel_function() {
  kernel_function<<<1, 1>>>();
  CUDA_ERROR;
  cudaDeviceSynchronize();
  CUDA_ERROR;
}
