# CMake 最低版本号要求
cmake_minimum_required(VERSION 2.8)

# 项目信息
PROJECT(Demo4)

# 加入一个配置头文件，用于处理 CMake 对源码的设置
configure_file (
    "${PROJECT_SOURCE_DIR}/config.h.in"
    "${PROJECT_BINARY_DIR}/config.h"
)

# 是否使用自己的 MathFunctions 库
option (USE_MYMATH
    "Use provided math implementation" ON)

# 是否加入 MathFunctions 库
if (USE_MYMATH)
    include_directories ("${PROJECT_SOURCE_DIR}/math")
    add_subdirectory(math)
    set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (USE_MYMATH)

# 将当前目录所有文件添加到变量 PROGRAM_SOURCE 中
aux_source_directory(. PROGRAM_SOURCE)

# 指定生成目标
add_executable(Demo4 ${PROGRAM_SOURCE})

# 添加链接库
target_link_libraries(Demo4 ${EXTRA_LIBS})