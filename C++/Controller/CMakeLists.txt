cmake_minimum_required(VERSION 2.8)

project ( Controller CXX )
file ( GLOB_RECURSE SRC *.?pp )
add_library(Controller SHARED ${SRC})
#target_link_libraries(Controller Qt5::Core)
#target_link_libraries(Controller Qt5::Gui)
