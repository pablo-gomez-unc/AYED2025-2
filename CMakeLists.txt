cmake_minimum_required(VERSION 3.30)
project(ayed)

set(CMAKE_CXX_STANDARD 20)

file(GLOB CHILDREN RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*)
foreach(child ${CHILDREN})
    if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${child})
        if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${child}/CMakeLists.txt")
            message(STATUS "Adding subdirectory: ${child}")
            add_subdirectory(${child})
        endif()
    endif()
endforeach()
