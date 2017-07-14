# CMake 最低版本号要求
cmake_minimum_required(VERSION 2.8)

# 项目信息
PROJECT(Demo3)

# 将当前目录所有文件添加到变量 PROGRAM_SOURCE 中
aux_source_directory(. PROGRAM_SOURCE)

# 添加 math 子目录
add_subdirectory(math)

# 指定生成目标
add_executable(Demo3 ${PROGRAM_SOURCE})

# 添加链接库
target_link_libraries(Demo3 MathFunctions)