CMAKE_MINIMUM_REQUIRED(VERSION 3.8)

project(exec LANGUAGES CXX CUDA)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(exec src/main.cpp
  src/kernel_file.cu
  src/function_file.cpp
  )

