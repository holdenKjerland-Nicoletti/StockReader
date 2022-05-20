cmake_minimum_required(VERSION 3.22)
project(QuantlabStocks)

set(CMAKE_CXX_STANDARD 20)


add_subdirectory(dependencies)

# https://www.youtube.com/watch?v=w2CzYK5ZJys&ab_channel=JetBrainsTV
enable_testing()
add_subdirectory(tests)

set(PROJ_SOURCES libs/TradesInputter.cpp libs/TradesInputter.h)
add_library(StoreLib ${PROJ_SOURCES})
target_include_directories(StoreLib
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
#target_link_libraries(StoreLib PUBLIC qhc_filesystem)

add_executable(QuantlabStocks main.cpp)
target_link_libraries(QuantlabStocks StoreLib)