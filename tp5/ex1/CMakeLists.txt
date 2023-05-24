cmake_minimum_required(VERSION 3.0)

# General informations about the project
project(tp5_ex1
        VERSION 1.0
        DESCRIPTION "First exercice of the 5th series of exercices of the Progammation Avance course (M1 University of Strasbourg)"
        LANGUAGES CXX)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
               PRIVATE
               customprint.h
               customprint.hpp
               isb.h
               main.cpp
               tests.cpp
               tests.h)

target_include_directories(${PROJECT_NAME}
                           PRIVATE
                           ${CMAKE_CURRENT_SOURCE_DIR})
