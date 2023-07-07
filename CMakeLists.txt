cmake_minimum_required(VERSION 3.25)
project(myToDoList)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(test)
set(SOURCE_FILES Date.cpp Date.h ToDo.h ToDoList.cpp ToDoList.h)
add_executable(myToDoList main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(myToDoList core)
