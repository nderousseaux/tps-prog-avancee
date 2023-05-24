cmake_minimum_required(VERSION 3.0)

# General informations about the project
project(tp4_ex2
        VERSION 1.0
        DESCRIPTION "Second exercice of the 4th series of exercices of the Progammation Avance course (M1 University of Strasbourg)"
        LANGUAGES CXX)

add_executable(${PROJECT_NAME})

find_package( Threads )

target_sources(${PROJECT_NAME}
               PRIVATE
               baseclass.h
               derivedclass1.h
               derivedclass2.h
               main.cpp
               tests.cpp
               tests.h)

target_include_directories(${PROJECT_NAME}
                           PRIVATE
                           ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} PUBLIC ${CMAKE_THREAD_LIBS_INIT})