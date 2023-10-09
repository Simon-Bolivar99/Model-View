cmake_minimum_required(VERSION 3.5)

project(Model_View VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Widgets Gui REQUIRED)
find_package(nlohmann_json 3.10.5 REQUIRED)

set(PROJECT_SOURCES
        src/MainWindow.cpp
        src/main.cpp
        src/Model.cpp
        src/AddDialog.cpp
        include/Model.h
        include/AddDialog.h
        include/MainWindow.h
        libs/utils.h
        libs/utils.cpp
        res/icons.qrc

        src/PenColor.cpp
        src/CustomDelegate.cpp
        src/ComboLineBox.cpp
        include/MainWindow.h
        include/ComboLineBox.h
        include/PenColor.h
        include/CustomDelegate.h
        libs/ColorToolButton.cpp
        libs/ColorToolButton.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Model_View
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES} ${PROJECT_MAIN}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Model_View APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Model_View SHARED
            ${PROJECT_SOURCES} ${PROJECT_MAIN}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Model_View
            ${PROJECT_SOURCES} ${PROJECT_MAIN}
        )
    endif()
endif()

target_link_libraries(Model_View PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Core
    #Qt${QT_VERSION_MAJOR}::Gui
)

set_target_properties(Model_View PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Model_View)
endif()
