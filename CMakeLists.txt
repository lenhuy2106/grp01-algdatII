cmake_minimum_required(VERSION 2.8)
project(SearchIt)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES testMain.cpp SuchenStatischenTexten/SufTree.cpp SuchenStatischenTexten/SufTree.h SuchenStatischenTexten/TextWord.cpp SuchenStatischenTexten/TextWord.h)
add_executable(SearchIt ${SOURCE_FILES})