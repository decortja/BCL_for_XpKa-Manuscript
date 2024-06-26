CMAKE_MINIMUM_REQUIRED( VERSION 2.8.8)

SET( LIBRARY_NAME bclexampleapps)
SET( LIBRARY_OBJECTS ${LIBRARY_NAME}-objects)
PROJECT( lib${LIBRARY_NAME})

SET(
  BCL_EXAMPLE_APP_LIBRARY_GROUPS
  descriptor
  internal/biology
  internal/chemistry
  internal/util
  model
  molecule
  restraint
  sequence
  release
)

SET(
  LIBRARY_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/example_apps.cpp
)
MACRO_CHECK_CMAKE_DIRECTORY_LIST( ${CMAKE_CURRENT_SOURCE_DIR} "${LIBRARY_SOURCES}")

FOREACH( GROUP ${BCL_EXAMPLE_APP_LIBRARY_GROUPS})
  unset( SUBDIRECTORY_LIBRARY_SOURCES)
  MACRO_ADD_SUBDIRECTORY( ${GROUP})
  IF( SUBDIRECTORY_LIBRARY_SOURCES)
    LIST( APPEND LIBRARY_SOURCES ${SUBDIRECTORY_LIBRARY_SOURCES})
  ENDIF()
ENDFOREACH()

ADD_LIBRARY( ${LIBRARY_OBJECTS} OBJECT ${LIBRARY_SOURCES})

IF( LINK_NAMESPACE_ARCHIVES)
  ADD_LIBRARY( ${LIBRARY_NAME} STATIC $<TARGET_OBJECTS:${LIBRARY_OBJECTS}>)
ENDIF()

SET( SUBDIRECTORY_LIBRARY_NAME ${LIBRARY_NAME} PARENT_SCOPE)
SET( SUBDIRECTORY_LIBRARY_OBJECTS ${LIBRARY_OBJECTS} PARENT_SCOPE)
