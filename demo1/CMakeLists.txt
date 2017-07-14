# CMake 最低版本号要求
cmake_minimum_required(VERSION 2.8)

# 项目信息
PROJECT(Demo1)

# 将当前目录所有文件添加到变量 PROGRAM_SOURCE 中
aux_source_directory(. PROGRAM_SOURCE)

# 指定目标可执行文件 Demo1 的源代码文件为 PROGRAM_SOURCE
add_executable(Demo1 ${PROGRAM_SOURCE})