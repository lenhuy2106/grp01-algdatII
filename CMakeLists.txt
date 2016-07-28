cmake_minimum_required(VERSION 2.8)
project(SearchIt)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        SuchenStatischenTexten/SufTree.h
        SuchenStatischenTexten/SufTree.cpp
        SuchenStatischenTexten/TextWord.h
        SuchenStatischenTexten/TextWord.cpp
        )

set(TEST_LANCHER testMain.cpp)

set(NORMAL_LANCHER SuchenStatischenTexten/SearchIt.cpp)


add_executable(SearchItTest ${TEST_LANCHER} ${SOURCE_FILES})

add_executable(SearchIt ${NORMAL_LANCHER} ${SOURCE_FILES})