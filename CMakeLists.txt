cmake_minimum_required(VERSION 3.5)

project(rvizplugin VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets LinguistTools REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets LinguistTools Network REQUIRED)
find_package(VTK 7 REQUIRED  COMPONENTS
        vtkCommonCore
        vtkFiltersSources
        vtkGUISupportQt
        vtkIOImage
        vtkInteractionImage
        vtkFiltersCore
        vtkInfovisCore
        vtkInteractionStyle
        #vtkViewsQt
)
include(${VTK_USE_FILE})
find_package(PCL 1.10 REQUIRED)


# message(${PCL_INCLUDE_DIRS})
#message("hello")
include_directories(include ${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})

set(TS_FILES rvizplugin_zh_CN.ts)

set(PROJECT_SOURCES
        src/main.cpp
        src/mywidget.cpp
        src/udpserver/MyUdpServer.cpp        
        src/handleserver/HandleFunctionFactory.cpp
        src/handleserver/functionimpl/ImageShow.cpp
        include/handleserver/HandleFunctionInterface.hpp
        src/udpserver/UdpMessage.cpp
        src/handleserver/functionimpl/PointCloudShow.cpp

        include/mywidget.h
        resource/rqt_push_button.ui
        #${TS_FILES}
        src/handleserver/MyPoint.cpp

)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(rvizplugin
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET rvizplugin APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(rvizplugin SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(rvizplugin
            ${PROJECT_SOURCES}
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

target_link_libraries(rvizplugin PRIVATE
        Qt${QT_VERSION_MAJOR}::Widgets
        Qt${QT_VERSION_MAJOR}::Network
        ${VTK_LIBRARIES}
        ${PCL_LIBRARIES}
        #vtkFiltersParallelDIY2
        vtkGUISupportQt
        #${PCL_APPS_LIBRARY}
)

set_target_properties(rvizplugin PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(rvizplugin)
endif()
