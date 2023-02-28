cmake_minimum_required(VERSION 3.15)
project("2_vilage_data_model" VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)

add_executable(2_vilage_data_model include/dwellinghouse.h include/Floor.h include/functions.h include/House.h include/plot.h include/room.h src/dwellinghouse.cpp src/functions.cpp src/House.cpp src/main.cpp)
target_include_directories(2_vilage_data_model PUBLIC include)