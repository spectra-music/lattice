include_directories(${lattice_SOURCE_DIR}/include)
# add_library( test_runner STATIC test_runner.c )

add_executable( lattice_desc lattice_desc.c )
target_link_libraries( lattice_desc lattice cspec )
add_test( test_string_prepend lattice_desc )