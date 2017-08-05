## Requirements
Ubuntu 16.04, ROS kinetic

## Settings
- Set cuda architecture version (sm_xx according to your GPU) and cudnn path in `CMakeLists.txt`:
```
set(CUDA_NVCC_FLAGS "-gencode arch=compute_50,code=[sm_50,sm_50]" CACHE STRING "nvcc flags" FORCE)
...cmake
link_directories(
  /usr/local/cuda-8.0/lib64
  /usr/local/lib
  /home/siyuan/drivers/cuda/lib64 # Change this line to your cudnn path
)
```
- Set your catkin workspace path in `scripts/run.sh`:
```sh
catkin_ws_path="/home/siyuan/old_catkin_ws/"
```
- Set your yolo_object_detection package path in `src/image.c`:
```cpp
// Change this path to your yolo_object_detection project path
sprintf(buff, "/home/siyuan/old_catkin_ws/src/yolo_object_detection/data/labels/%d_%d.png", i, j);
```
- Set image resolution and topic name in `src/demo_ros.cpp`
```cpp
static int frame_width = 640;
static int frame_height = 480;
...
const char* image_topic_name = "/image";
```

## Example usage
rosrun yolo_object_detection run.sh
