

find_package(Qt6 QUIET COMPONENTS WebSockets)

if( NOT Qt6WebSockets_FOUND)
    message(STATUS "Can't find Qt6WebSockets in your system. Have you tried [sudo apt-get install libQt6websockets5-dev] ?")
else()

    include_directories( ../ )

    add_definitions(${QT_DEFINITIONS})
    add_definitions(-DQT_PLUGIN)

    Qt6_WRAP_UI ( UI_SRC  websocket_server.ui  )

    SET( SRC websocket_server.cpp )

    add_library(DataStreamWebSocket SHARED ${SRC} ${UI_SRC}  )

    target_link_libraries(DataStreamWebSocket
        ${Qt6Widgets_LIBRARIES}
        Qt6::WebSockets
        plotjuggler_base )

    install(TARGETS DataStreamWebSocket DESTINATION ${PJ_PLUGIN_INSTALL_DIRECTORY}  )

endif()
