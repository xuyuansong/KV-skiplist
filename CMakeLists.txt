cmake_minimum_required(VERSION 2.8)

project(Skiplist-App)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

add_executable(../main main.cpp ./src/Node.h)

#target_link_libraries(../main -pthread)