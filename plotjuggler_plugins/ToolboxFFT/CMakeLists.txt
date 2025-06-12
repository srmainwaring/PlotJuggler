
include_directories( ../ )

add_definitions(${QT_DEFINITIONS})
add_definitions(-DQT_PLUGIN)

add_subdirectory(3rdparty/KissFFT)

Qt6_WRAP_UI ( UI_SRC
    toolbox_FFT.ui
    )

add_library(ToolboxFFT SHARED
    toolbox_FFT.cpp
    toolbox_FFT.h
    ${UI_SRC}  )

target_include_directories(ToolboxFFT PRIVATE 3rdparty)

target_link_libraries(ToolboxFFT
    ${Qt6Widgets_LIBRARIES}
    ${Qt6Xml_LIBRARIES}
    ${Qt6OpenGLWidgets_LIBRARIES}
    kissfft
    plotjuggler_base
    plotjuggler_qwt)

install(TARGETS ToolboxFFT DESTINATION ${PJ_PLUGIN_INSTALL_DIRECTORY}  )
