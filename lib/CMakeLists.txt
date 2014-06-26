# Notice name prefix of this variable, set by CMake according
# to value given with "project()" in the root CMakeLists.txt.
include_directories(${lattic_SOURCE_DIR}/include)
add_library(lattice lattice.c)
