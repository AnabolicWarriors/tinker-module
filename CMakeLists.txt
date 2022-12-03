cmake_minimum_required(VERSION 3.14.1)
SET(PROJECT_NAME chacha)

project(${PROJECT_NAME})

# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
# set(CXX_STANDARD 14)
# Serial Port Linrary
include_directories(${CMAKE_SOURCE_DIR}/3rdparty/Serial/lib/)

add_executable(${PROJECT_NAME}
    3rdparty/Serial/lib/serialib.cpp

    main.cpp
)

# install target and libraries
set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/bin)

