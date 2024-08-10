cmake_minimum_required( VERSION 2.8 )
project( randAvatar )

# 添加c++ 11标准支持
# set( CMAKE_CXX_FLAGS "-std=c++11" )
set(CMAKE_CXX_STANDARD 11)
add_compile_options(/utf-8)

# 寻找OpenCV库
find_package( OpenCV REQUIRED )
# 添加头文件
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable( randAvatar main.cpp )
# 链接OpenCV库
target_link_libraries( randAvatar ${OpenCV_LIBS} )
