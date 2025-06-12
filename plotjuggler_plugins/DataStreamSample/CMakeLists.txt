
include_directories( ../ )

add_definitions(${QT_DEFINITIONS})
add_definitions(-DQT_PLUGIN)

SET( SRC datastream_sample.cpp)

add_library(DataStreamSample SHARED ${SRC} ${UI_SRC}  )

target_link_libraries(DataStreamSample
    ${Qt6Widgets_LIBRARIES}
    ${Qt6Xml_LIBRARIES}
    plotjuggler_base)

install(TARGETS DataStreamSample DESTINATION ${PJ_PLUGIN_INSTALL_DIRECTORY}  )
