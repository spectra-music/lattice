# -*- cmake -*-
#  from:
#  http://code.google.com/p/emeraldviewer/source/browse/indra/cmake/FindBerkeleyDB.cmake?spec=svn2d5b87bf61c915011530469add736301acccfd32&r=2d5b87bf61c915011530469add736301acccfd32
#
# modified:
#  * changed paths to suit BerkeleyDB.5.0 installation
# * reversed order for searching /usr/local and /usr

# - Find BerkeleyDB
# Find the BerkeleyDB includes and library
# This module defines
#  DB_INCLUDE_DIR, where to find db.h, etc.
#  DB_LIBRARIES, the libraries needed to use BerkeleyDB.
#  DB_FOUND, If false, do not try to use BerkeleyDB.
# also defined, but not for general use are
#  DB_LIBRARY, where to find the BerkeleyDB library.

#  Look for header in paths:
FIND_PATH( CSPEC_INCLUDE_DIR  cspec.h
                              /usr/local/include
                              /usr/include
)


#  Look for lib in paths:
SET( CSPEC_NAMES ${CSPEC_NAMES} cspec )
FIND_LIBRARY(CSPEC_LIBRARY
  NAMES ${CSPEC_NAMES}
  PATHS /usr/local/lib /usr/lib
)

#  set whether we found both headers and lib
IF (CSPEC_LIBRARY AND CSPEC_INCLUDE_DIR)
    SET(CSPEC_LIBRARIES ${CSPEC_LIBRARY})
    SET(CSPEC_FOUND "YES")
ELSE (CSPEC_LIBRARY AND CSPEC_INCLUDE_DIR)
  SET(CSPEC_FOUND "NO")
ENDIF (CSPEC_LIBRARY AND CSPEC_INCLUDE_DIR)


IF (CSPEC_FOUND)
   IF (NOT CSPEC_FIND_QUIETLY)
      MESSAGE(STATUS "Found CSpec: ${CSPEC_LIBRARIES}")
   ENDIF (NOT CSPEC_FIND_QUIETLY)
ELSE (CSPEC_FOUND)
   IF (CSPEC_FIND_REQUIRED)
      MESSAGE(FATAL_ERROR "Could not find CSpec library")
   ENDIF (CSPEC_FIND_REQUIRED)
ENDIF (CSPEC_FOUND)

# Deprecated declarations.
SET (NATIVE_CSPEC_INCLUDE_PATH ${CSPEC_INCLUDE_DIR} )
GET_FILENAME_COMPONENT (NATIVE_CSPEC_LIB_PATH ${CSPEC_LIBRARY} PATH)

MARK_AS_ADVANCED(
  CSPEC_LIBRARY
  CSPEC_INCLUDE_DIR
)