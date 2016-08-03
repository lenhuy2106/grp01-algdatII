cmake_minimum_required(VERSION 2.8)
project(UnitTestg)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        main.cpp
        unittest_IOParser.cpp
        unittest_SufTree.cpp
        unittest_TextWord.cpp
        unittest_TheText.cpp
        )

add_executable(UnitTests ${TEST_LANCHER} ${SOURCE_FILES})

target_link_libraries(UnitTests libgtest libgtest_main SearchItLib)