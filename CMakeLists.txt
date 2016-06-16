cmake_minimum_required(VERSION 3.3)
project(StudentFacultyDB)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Faculty.cpp
    Faculty.h
    listNode.h
    main.cpp
    Simulation.cpp
    Simulation.h
    stack.h
    Student.cpp
    Student.h
    Tree.h)

add_executable(StudentFacultyDB ${SOURCE_FILES})