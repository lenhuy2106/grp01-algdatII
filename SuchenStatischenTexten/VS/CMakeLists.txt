cmake_minimum_required(VERSION 2.8)
project(SuchenStatischenTexten)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        SuchenStatischenTexten/SufTree.h
        SuchenStatischenTexten/SufTree.cpp
        SuchenStatischenTexten/TextWord.h
        SuchenStatischenTexten/TextWord.cpp
        SuchenStatischenTexten/TheText.h
        SuchenStatischenTexten/TheText.cpp
        SuchenStatischenTexten/SuchenStatischenTexten/IOParser.h
        )

set(LANCHER_FILE )

add_executable(SuchenStatischenTexten ${LANCHER_FILE} ${SOURCE_FILES})