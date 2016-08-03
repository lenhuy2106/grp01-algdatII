cmake_minimum_required(VERSION 2.8)
project(SearchIt)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        SuchenStatischenTexten/SuchenStatischenTexten/SufTree.h
        SuchenStatischenTexten/SuchenStatischenTexten/IOParser.h
        SuchenStatischenTexten/SuchenStatischenTexten/TextWord.h
        SuchenStatischenTexten/SuchenStatischenTexten/TheText.h
        SuchenStatischenTexten/SuchenStatischenTexten/SufTree.cpp
        SuchenStatischenTexten/SuchenStatischenTexten/TextWord.cpp
        SuchenStatischenTexten/SuchenStatischenTexten/TheText.cpp
        SuchenStatischenTexten/SuchenStatischenTexten/DirFileSearch.h
        SuchenStatischenTexten/SuchenStatischenTexten/DirFileSearch.cpp
        )

set(TEST_LANCHER SuchenStatischenTexten/SuchenStatischenTexten/testMain.cpp)

set(NORMAL_LANCHER SuchenStatischenTexten/SuchenStatischenTexten/SearchIt.cpp)


add_executable(SearchItTest ${TEST_LANCHER} ${SOURCE_FILES})

add_executable(SearchIt ${NORMAL_LANCHER} ${SOURCE_FILES})