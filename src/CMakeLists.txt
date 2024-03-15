cmake_minimum_required(VERSION 3.21)

set( PROJECT_NAME "rocket-league" )
project( ${PROJECT_NAME} LANGUAGES C CXX )
set( TARGET ${PROJECT_NAME} )

set( CMAKE_CXX_STANDARD 17 )

add_executable( ${TARGET} 
    menu.cpp
    rocket.cpp
    )

target_include_directories( ${TARGET} 
    PUBLIC src/menu.hpp
    )

set_target_properties(${TARGET} PROPERTIES LINKER_LANGUAGE CXX)