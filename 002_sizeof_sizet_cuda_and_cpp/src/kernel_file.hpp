
#define CUDA_ERROR                                                             \
  {                                                                            \
    cudaError_t err;                                                           \
    err = cudaGetLastError();                                                  \
    if (err != cudaSuccess) {                                                  \
      printf("Cuda Error: %d : %s : %s, line %d \n", err,                      \
             cudaGetErrorString(err), __FILE__, __LINE__);                     \
      exit(1);                                                                 \
    }                                                                          \
  }

void run_kernel_function();
