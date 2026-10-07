cmake_minimum_required(VERSION 3.10)
project(spdlog_test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_FILES src/main.cpp
                 src/spdlog_test.cpp)
set(SOURCE_INCLUDE src/include)
set(app spdlog_test)

# ==========================================
# 1. 封装本地 spdlog 为 IMPORTED Target
# ==========================================
add_library(spdlog STATIC IMPORTED)

set_target_properties(spdlog PROPERTIES
    # 静态库直接位于 libs/ 根目录
    IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/libs/libspdlog.a"
    # 头文件根目录是 libs/include (因为代码里写的是 #include <spdlog/xxx.h>)
    INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/libs/include"
)

# spdlog 在 Linux 下依赖 pthread，必须显式链接，否则报 undefined reference
find_package(Threads REQUIRED)
set_target_properties(spdlog PROPERTIES
    INTERFACE_LINK_LIBRARIES Threads::Threads
)

# ==========================================
# 2. 构建你的可执行文件并链接
# ==========================================
add_executable(${app} ${SOURCE_FILES})
target_include_directories(${app} PRIVATE ${SOURCE_INCLUDE})

target_link_libraries(${app} PRIVATE spdlog)