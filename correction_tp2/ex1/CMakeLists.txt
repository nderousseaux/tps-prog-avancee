cmake_minimum_required(VERSION 3.0)

# General informations about the project
project(tp2ex1_correction
        VERSION 1.0
        DESCRIPTION "First exercice of the second series of exercices of the Programmation Avancee course (M1 University of Strasbourg)"
        LANGUAGES CXX)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
               PRIVATE
               test_list.cpp
               test_list.h
               main.cpp)

target_include_directories(${PROJECT_NAME}
                           PRIVATE
                           ${CMAKE_CURRENT_SOURCE_DIR})