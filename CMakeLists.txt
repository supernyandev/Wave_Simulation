cmake_minimum_required(VERSION 3.24)
project(Wave_Simulation)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(Wave_Simulation main.cpp Simulations/simulation.cpp Simulations/simulation.h)

target_link_libraries(Wave_Simulation sfml-graphics sfml-audio)