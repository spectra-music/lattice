add_subdirectory( cppspec )

set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror" )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Werror")

include_directories(${c++spec_SOURCE_DIR}/include)
include_directories(${lattice_SOURCE_DIR}/include)

add_executable( util_spec util_spec.cpp ${lattice_SOURCE_DIR}/lib/util.c)

add_test( eutil "util_spec" )