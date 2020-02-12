cmake_minimum_required(VERSION 3.1.0)

# Must be set before project() is called
set(CMAKE_OSX_DEPLOYMENT_TARGET "10.11")

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

include(QtCommon)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")
set(CMAKE_CXX_FLAGS_COVERAGE "${CMAKE_CXX_FLAGS_RELEASE} -fprofile-arcs -ftest-coverage")


project(colorOverlay VERSION 0.0.1)
set(COMPANY "Stürmer")
set(COPYRIGHT "Copyright (c) 2020 Benjamin Stürmer. All rights reserved.")
set(IDENTIFIER "de.stuermerbenjamin.qt.colorOverlay")

set(SOURCE_FILES
    src/main.cpp
    src/mainwindow.cpp
)

add_project_meta(META_FILES_TO_INCLUDE)

set(RESOURCE_FILES project.qrc)

find_package(Qt5 COMPONENTS Core REQUIRED)
find_package(Qt5 COMPONENTS Gui REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)


if (APPLE)
    set(OS_BUNDLE MACOSX_BUNDLE)
elseif (WIN32)
    set(OS_BUNDLE WIN32)
endif()

add_executable(${PROJECT_NAME} ${OS_BUNDLE}
	${SOURCE_FILES}
	${META_FILES_TO_INCLUDE}
	${RESOURCE_FILES}
)

target_link_libraries(${PROJECT_NAME} Qt5::Core)
target_link_libraries(${PROJECT_NAME} Qt5::Gui)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)

