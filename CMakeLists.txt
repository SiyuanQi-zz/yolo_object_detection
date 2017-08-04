cmake_minimum_required(VERSION 2.8.3)
project(YoloObjDetection)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  cmake_modules
  cv_bridge
  sensor_msgs
  image_transport
  message_generation
)

find_package(CUDA REQUIRED)

################################################
## Declare ROS messages, services and actions ##
################################################
generate_messages(
 DEPENDENCIES
 sensor_msgs
)


###################################
## catkin specific configuration ##
###################################
catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS
    message_runtime
    cv_bridge
)

###########
## Build ##
###########

set(CMAKE_CXX_FLAGS "-Wall -Wfatal-errors -Ofast -DGPU -DCUDNN -DOPENCV${CMAKE_CXX_FLAGS}")
set(CMAKE_C_FLAGS "-Wall -Wfatal-errors -Ofast -DGPU -DCUDNN -DOPENCV${CMAKE_C_FLAGS}")
set(CUDA_NVCC_FLAGS "-gencode arch=compute_50,code=[sm_50,sm_50]" CACHE STRING "nvcc flags" FORCE)
set(CUDA_VERBOSE_BUILD ON CACHE BOOL "nvcc verbose" FORCE)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

link_directories(
  /usr/local/cuda-8.0/lib64
  /usr/local/lib
  /home/siyuan/drivers/cuda/lib64
)

list(APPEND LINK_LIBS
  ${catkin_LIBRARIES}
  cuda
  cudart
  cublas
  curand
  cudnn
)

file(GLOB CUDA_SOURCE_FILES src/*.cu)
CUDA_ADD_LIBRARY(YoloCUDA ${CUDA_SOURCE_FILES})

file(GLOB LIB_SOURCE_FILES src/*.c src/examples/*.c)
add_library(YoloLibs ${LIB_SOURCE_FILES})

add_executable(YoloObjDetect src/darknet.cpp)

target_link_libraries(YoloCUDA ${LINK_LIBS})
target_link_libraries(YoloLibs YoloCUDA ${LINK_LIBS})

# file(GLOB EXAMPLE_FILES src/examples/*.c)
# add_executable(YoloObjDetect src/darknet.cpp ${EXAMPLE_FILES})


target_link_libraries(YoloObjDetect YoloLibs YoloCUDA ${LINK_LIBS})
add_dependencies(YoloObjDetect YoloObjDetect_generate_messages_cpp)
