MACRO( MACRO_ADD_SUBDIRECTORY SUBDIR)
  IF( EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${SUBDIR}/" AND IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/${SUBDIR}/")
    ADD_SUBDIRECTORY( ${CMAKE_CURRENT_SOURCE_DIR}/${SUBDIR})
  ELSE()
    MESSAGE( STATUS "Skipping non-existent directory: ${CMAKE_CURRENT_SOURCE_DIR}/${SUBDIR}")
  ENDIF()
ENDMACRO()
