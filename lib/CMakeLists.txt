# Notice name prefix of this variable, set by CMake according
# to value given with "project()" in the root CMakeLists.txt.
include_directories(${lattice_SOURCE_DIR}/include)
add_library( lattice
  ltc_env.c
)

add_executable( lattice_demo lattice.c )
target_link_libraries( lattice_demo lattice ${LMDB_LIBRARIES} )
