cmake_minimum_required(VERSION 3.0)

# General informations about the project
project(programmation_avancee_tp4
        VERSION 1.0
        DESCRIPTION "Fourth series of exercices of the Programmation Avancee course (M1 University of Strasbourg)"
        LANGUAGES CXX)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/ex1/")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/ex2/")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/ex3/")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/ex4/")