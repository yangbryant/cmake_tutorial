# CMake 最低版本号要求
cmake_minimum_required(VERSION 2.8)

# 项目信息
PROJECT(Demo7)

set (Demo_VERSION_MAJOR 1)
set (Demo_VERSION_MINOR 0)

# 检查系统是否支持 pow 函数
include (${CMAKE_ROOT}/Modules/CheckFunctionExists.cmake)
check_function_exists (pow HAVE_POW)

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
add_executable(Demo7 ${PROGRAM_SOURCE})

# 添加链接库
target_link_libraries(Demo7 ${EXTRA_LIBS})

# 指定安装路径
install (TARGETS Demo7 DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/config.h"
         DESTINATION include)

# 启用测试
enable_testing()

# 测试程序是否成功运行
add_test (test_run Demo7 5 2)

# 测试帮助信息是否可以正常提示
add_test (test_usage Demo7)
set_tests_properties (test_usage
	PROPERTIES PASS_REGULAR_EXPRESSION "Usage: .* base exponent")
  
# 测试 5 的平方
# add_test (test_5_2 Demo7 5 2)
# set_tests_properties (test_5_2
# 	PROPERTIES PASS_REGULAR_EXPRESSION "is 25")
 
# # 测试 10 的 5 次方
# add_test (test_10_5 Demo7 10 5)
# set_tests_properties (test_10_5
# 	PROPERTIES PASS_REGULAR_EXPRESSION "is 100000")
 
# # 测试 2 的 10 次方
# add_test (test_2_10 Demo7 2 10)
# set_tests_properties (test_2_10
# 	PROPERTIES PASS_REGULAR_EXPRESSION "is 1024")

# 定义一个宏，用来简化测试工作
macro (do_test arg1 arg2 result)
  add_test (test_${arg1}_${arg2} Demo7 ${arg1} ${arg2})
  set_tests_properties (test_${arg1}_${arg2}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro (do_test)
 
# 使用该宏进行一系列的数据测试
do_test (5 2 "is 25")
do_test (10 5 "is 100000")
do_test (2 10 "is 1024")