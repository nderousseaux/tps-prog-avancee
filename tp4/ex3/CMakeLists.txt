cmake_minimum_required(VERSION 3.0)

# General informations about the project
project(tp4_ex3
        VERSION 1.0
        DESCRIPTION "Third exercice of the 4th series of exercices of the Progammation Avance course (M1 University of Strasbourg)"
        LANGUAGES CXX)

find_package( Threads )

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
               PRIVATE
               main.cpp
               tests.cpp
               tests.h)

target_include_directories(${PROJECT_NAME}
                           PRIVATE
                           ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} PUBLIC ${CMAKE_THREAD_LIBS_INIT})