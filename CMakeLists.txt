cmake_minimum_required(VERSION 3.25)
project(myToDoList)

set(CMAKE_CXX_STANDARD 17)

add_executable(myToDoList main.cpp Date.cpp Date.h ToDo.h ToDoList.cpp ToDoList.h)
