CMAKE_MININUM_REQUIRED( version 2.8 )

# Version
set( lattice_VERSION_MAJOR 0 )
set( lattice_VERSION_MINOR 1 )

# Default build config 
if (NOT CMAKE_BUILD_TYPE)
  message(STATUS "No build type selected, default to Release")
  set(CMAKE_BUILD_TYPE "Release")
endif()

# Some compiler flags
set( CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} -std=c11" )
set( CMAKE_C_FLAGS_DEBUG "-O2 -Wall -Wextra -pedantic -g" )
set( CMAKE_C_FLAGS_RELEASE "-O2 -Wall -fomit-frame-pointer -DNDEBUG" )
set( CMAKE_C_FLAGS_RELWITHDEBINFO "${CMAKE_C_FLAGS_RELEASE} -g" )

# The distclean target
IF (UNIX)
  ADD_CUSTOM_TARGET (distclean @echo cleaning for source distribution)
  SET(distcleaned
   cmake.depends
   cmake.check_depends
   CMakeCache.txt
   cmake.check_cache
   *.cmake
   Makefile
   core core.*
   gmon.out
   *~
  )
  
  ADD_CUSTOM_COMMAND(
    DEPENDS clean
    COMMENT "distribution clean"
    COMMAND rm
    ARGS    -Rf CMakeFiles CMakeTmp ${DISTCLEANED}
    TARGET  distclean
  )
ENDIF(UNIX)
