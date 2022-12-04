cmake_minimum_required(VERSION 3.14.1)
SET(PROJECT_NAME chacha)

project(${PROJECT_NAME})

add_compile_options(-std=c++17)

OPTION(LOG "use spdlog" ON)

if (LOG) 
    add_compile_definitions(LOG_SYSTEM)
endif()
# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
# set(CXX_STANDARD 14)
# Serial Port Linrary
include_directories(${CMAKE_SOURCE_DIR}/3rdparty/Serial/lib/)
include_directories(${CMAKE_SOURCE_DIR}/3rdparty/args/)
include_directories(${CMAKE_SOURCE_DIR}/3rdparty/spdlog/include)
include_directories(${CMAKE_SOURCE_DIR}/3rdparty/process/)
include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(${CMAKE_SOURCE_DIR}/3rdparty/process/)

add_executable(${PROJECT_NAME}
    3rdparty/Serial/lib/serialib.cpp

    src/argument/parser.cpp
    src/serial/serial.cpp
    main.cpp
)

target_link_libraries(${PROJECT_NAME} tiny-process-library)

# install target and libraries
set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/bin)

