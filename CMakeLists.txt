cmake_minimum_required(VERSION 3.10)
project(spdlog_test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_FILES src/main.cpp
                 src/spdlog_test.cpp)
set(SOURCE_INCLUDE src/include)
set(app spdlog_test)

#是否使用spdlog的header only版本，默认使用库版本
option(SPDLOG_HEAD_ONLY "Use header only version of spdlog" OFF)

add_executable(${app} ${SOURCE_FILES})
target_include_directories(${app} PRIVATE ${SOURCE_INCLUDE})

#链接spdlog库
target_include_directories(${app} PRIVATE ${CMAKE_SOURCE_DIR}/libs/include)
if (NOT SPDLOG_HEAD_ONLY)
    #仅在使用预编译库版本时，定义宏并链接静态库
    target_compile_definitions(${app} PRIVATE SPDLOG_COMPILED_LIB)
    target_link_libraries(${app} PRIVATE ${CMAKE_SOURCE_DIR}/libs/libspdlog.a pthread)
endif()