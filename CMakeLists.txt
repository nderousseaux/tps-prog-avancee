cmake_minimum_required(VERSION 3.0)

# General informations about the top level project
project(programmation_avancee_tps
        VERSION 1.0
        DESCRIPTION "Practical work of the Programmation Avancee course (M1 University of Strasbourg)"
        LANGUAGES CXX)

# Use c++20 features
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/tp1/")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/tp2/")