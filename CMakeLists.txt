cmake_minimum_required(VERSION 3.10)
project(CPU_Scheduling_Visualization)

set(CMAKE_CXX_STANDARD 17)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(cpu_scheduling
    main.cpp
    src/display.cpp
    src/process.cpp
    src/processGenerator.cpp
    src/helperFunctions.cpp
    src/fcfs.cpp
    src/sjf.cpp
)

target_link_libraries(cpu_scheduling ${CURSES_LIBRARIES})

target_include_directories(cpu_scheduling PUBLIC include)
