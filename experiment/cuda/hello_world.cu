#include <cuda_runtime.h>
#include <iostream>
#include <chrono>
#include <cmath>

#define SIZE 8192      // Matrix size: SIZE x SIZE
#define ITER 20        // Repeats for compute test
#define MEM_ITER 50    // Repeats for memory test

// Kernel: Matrix multiplication (compute heavy)
__global__ void matMulKernel(float* A, float* B, float* C, int n) {
    int row = blockIdx.y * blockDim.y + threadIdx.y;
    int col = blockIdx.x * blockDim.x + threadIdx.x;
    if(row >= n || col >= n) return;

    float sum = 0.0f;
    for(int k = 0; k < n; k++)
        sum += A[row*n + k] * B[k*n + col];
    C[row*n + col] = sum;
}

// Kernel: Memory copy test (bandwidth heavy)
__global__ void memCopyKernel(float* src, float* dst, int n) {
    int idx = blockIdx.x * blockDim.x + threadIdx.x;
    if(idx >= n) return;
    dst[idx] = src[idx];
}

int main() {
    std::cout << "Starting GPU benchmark...\n";

    // Allocate memory
    size_t matrix_bytes = SIZE * SIZE * sizeof(float);
    float *A, *B, *C;
    cudaMallocManaged(&A, matrix_bytes);
    cudaMallocManaged(&B, matrix_bytes);
    cudaMallocManaged(&C, matrix_bytes);

    // Initialize matrices
    for(int i=0;i<SIZE*SIZE;i++){ A[i]=1.0f; B[i]=0.01f; }

    dim3 block(16,16);
    dim3 grid((SIZE+block.x-1)/block.x, (SIZE+block.y-1)/block.y);

    // ===== Compute Benchmark =====
    auto start_compute = std::chrono::high_resolution_clock::now();
    for(int iter=0; iter<ITER; iter++){
        matMulKernel<<<grid, block>>>(A,B,C,SIZE);
        cudaDeviceSynchronize();
    }
    auto end_compute = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_compute = end_compute - start_compute;

    double gflops = 2.0 * SIZE * SIZE * SIZE * ITER / (elapsed_compute.count() * 1e9);
    std::cout << "Compute benchmark done in " << elapsed_compute.count() << " s\n";
    std::cout << "Estimated GFLOPS: " << gflops << "\n";
    std::cout << "C[0] = " << C[0] << "\n";

    // ===== Memory Bandwidth Benchmark =====
    size_t mem_size = SIZE * SIZE;
    float *D, *E;
    cudaMallocManaged(&D, matrix_bytes);
    cudaMallocManaged(&E, matrix_bytes);
    for(int i=0;i<mem_size;i++) D[i]=1.0f;

    dim3 mem_block(256);
    dim3 mem_grid((mem_size + mem_block.x - 1)/mem_block.x);

    auto start_mem = std::chrono::high_resolution_clock::now();
    for(int iter=0; iter<MEM_ITER; iter++){
        memCopyKernel<<<mem_grid, mem_block>>>(D,E,mem_size);
        cudaDeviceSynchronize();
    }
    auto end_mem = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_mem = end_mem - start_mem;

    double gb_per_s = (double)(matrix_bytes*MEM_ITER)/1e9 / elapsed_mem.count();
    std::cout << "Memory benchmark done in " << elapsed_mem.count() << " s\n";
    std::cout << "Approx memory bandwidth: " << gb_per_s << " GB/s\n";

    // Free memory
    cudaFree(A); cudaFree(B); cudaFree(C);
    cudaFree(D); cudaFree(E);

    return 0;
}
