cmake_minimum_required(VERSION 3.25)
project(ClinicManagementSystem)

set(CMAKE_CXX_STANDARD 14)

add_executable(ClinicManagementSystem
        src/main.cpp src/Admin/Admin.cpp src/LinkedList/LinkedList.cpp)
