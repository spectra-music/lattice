cmake_minimum_required( VERSION 2.8.8 )
project( lattice )


# Version
set( lattice_VERSION_MAJOR 0 )
set( lattice_VERSION_MINOR 1 )

# Default build config 
if (NOT CMAKE_BUILD_TYPE)
  message(STATUS "No build type selected, default to Release")
  set(CMAKE_BUILD_TYPE "Release")
endif()

# Some compiler flags
set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11" )
set( CMAKE_C_FLAGS_DEBUG "-Wall -Wextra -pedantic -g" )
set( CMAKE_C_FLAGS_RELEASE "-O2 -Wall -fomit-frame-pointer -DNDEBUG" )
set( CMAKE_C_FLAGS_RELWITHDEBINFO "${CMAKE_C_FLAGS_RELEASE} -g" )

# Add more CMake Module scripts
set( CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules )


#######################
# LMDB
#######################
find_package( LMDB )

if( NOT LMDB_FOUND )
	message(FATAL_ERROR "LMDB can't be found. Set CMAKE_PREFIX_PATH variable to LMDB's installation prefix.")
endif( NOT LMDB_FOUND )

include_directories( ${LMDB_INCLUDE_DIRS} )
link_directories( ${LMDB_LIBRARY_DIRS} )


################################
# Normal Libraries & Executables
################################

add_subdirectory(lib)


################################
# Unit Tests
################################
# This has to be before any add_subdirectory,
# so we can pick up the add_test inside of them.

if(TEST)
  enable_testing()
  
  # This adds another subdirectory, which has 'project(gtest)'.
  add_subdirectory( spec )
endif(TEST)

