add_library(typerighter_core dtk.c stream_utils.c)

set(SOURCES_LIST tpr_write.c)

foreach(SOURCE_FILE ${SOURCES_LIST})
  get_filename_component(TARGET_NAME ${SOURCE_FILE} NAME_WE)
  add_executable(${TARGET_NAME} ${SOURCE_FILE})
  target_link_libraries(${TARGET_NAME} PRIVATE typerighter_core)
endforeach()
