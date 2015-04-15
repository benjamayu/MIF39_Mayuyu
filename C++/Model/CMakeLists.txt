cmake_minimum_required(VERSION 2.8)

project ( Model CXX )
file ( GLOB_RECURSE SRC *.?pp )
add_library(Model SHARED ${SRC})
#target_link_libraries(Model Qt5::Core)
#target_link_libraries(Model Qt5::Gui)
