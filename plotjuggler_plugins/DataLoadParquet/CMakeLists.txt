if(BUILDING_WITH_VCPKG)
    message(STATUS "Finding Parquet with vcpkg")
    set(PARQUET_LIBRARIES
        re2::re2
        arrow_shared
        parquet_shared
        arrow_bundled_dependencies)

    find_package(arrow CONFIG QUIET)

else()
    message(STATUS "Finding Parquet without package managers")
    list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")

    find_package(Arrow CONFIG QUIET)
    find_package(Parquet CONFIG QUIET)

    # message(STATUS "ARROW_FOUND: ${ARROW_FOUND}")
    # message(STATUS "ARROW_INCLUDE_DIR: ${ARROW_INCLUDE_DIR}")
    # message(STATUS "ARROW_LIB_DIR: ${ARROW_LIB_DIR}")

    # message(STATUS "PARQUET_FOUND: ${PARQUET_FOUND}")
    # message(STATUS "PARQUET_INCLUDE_DIR: ${PARQUET_INCLUDE_DIR}")
    # message(STATUS "PARQUET_LIB_DIR: ${PARQUET_LIB_DIR}")

endif()


if(Arrow_FOUND)
    message(STATUS "[Parquet] found")
    include_directories(  ../
        ${ARROW_INCLUDE_DIR}
        ${PARQUET_INCLUDE_DIR} )

    add_definitions(${QT_DEFINITIONS})
    add_definitions(-DQT_PLUGIN)

    Qt6_WRAP_UI ( UI_SRC  dataload_parquet.ui  )

    SET( SRC dataload_parquet.cpp )

    # Disable on macOS
    # add_library(DataLoadParquet SHARED ${SRC} ${UI_SRC}  )

    # target_link_libraries(DataLoadParquet
    #     ${Qt6Widgets_LIBRARIES}
    #     ${Qt6Xml_LIBRARIES}
    #     ${PARQUET_LIBRARIES}
    #     plotjuggler_base)


    # install(TARGETS DataLoadParquet DESTINATION ${PJ_PLUGIN_INSTALL_DIRECTORY}  )

else()
    message("[Parquet] not found. Skipping plugin DataLoadParquet.")
endif()
