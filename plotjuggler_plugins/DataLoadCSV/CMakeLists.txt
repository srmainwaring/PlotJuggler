
include_directories(  ../ )

add_definitions(${QT_DEFINITIONS})
add_definitions(-DQT_PLUGIN)

Qt6_WRAP_UI ( UI_SRC
    dataload_csv.ui
    datetimehelp.ui
    )

SET( SRC
    dataload_csv.cpp
    datetimehelp.cpp
    )

add_library(DataLoadCSV SHARED ${SRC} ${UI_SRC}  )
target_link_libraries(DataLoadCSV
    ${Qt6Widgets_LIBRARIES}
    ${Qt6Xml_LIBRARIES}
    plotjuggler_base
    QCodeEditor)


install(TARGETS DataLoadCSV DESTINATION ${PJ_PLUGIN_INSTALL_DIRECTORY}  )
