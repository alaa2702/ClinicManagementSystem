cmake_minimum_required(VERSION 3.25)
project(ClinicManagementSystem)

set(CMAKE_CXX_STANDARD 14)

add_executable(ClinicManagementSystem
        src/main.cpp src/Admin/Admin.cpp src/Admin/Admin.h src/LinkedList/LinkedList.cpp src/LinkedList/LinkedList.h src/PatientDataList/PatientDataList.cpp src/handelingInputs/HandelingInputs.cpp src/handelingInputs/HandelingInputs.h src/user/user.cpp src/user/user.h src/user/user.h)
