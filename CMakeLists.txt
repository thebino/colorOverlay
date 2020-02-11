cmake_minimum_required(VERSION 3.1.0)

# Must be set before project() is called
set(CMAKE_OSX_DEPLOYMENT_TARGET "10.11")

project(colorOverlay VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")
set(CMAKE_CXX_FLAGS_COVERAGE "${CMAKE_CXX_FLAGS_RELEASE} -fprofile-arcs -ftest-coverage")

if (WIN32)
	if ((MSVC_VERSION GREATER_EQUAL "1920") AND (IS_DIRECTORY "${QT_VERSION}/msvc2019"))
	    set(QT_MSVC "2019")
	elseif ((MSVC_VERSION GREATER_EQUAL "1910") AND (IS_DIRECTORY "${QT_VERSION}/msvc2017"))
	    set(QT_MSVC "2017")
	elseif (MSVC_VERSION GREATER_EQUAL "1900")
	    set(QT_MSVC "2015")
	else ()
	    MATH(EXPR QT_MSVC "2000 + (${MSVC_VERSION} - 500) / 100")
	endif ()
endif()

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Core REQUIRED)
find_package(Qt5 COMPONENTS Gui REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(SOURE_FILES main.cpp)
add_executable(${PROJECT_NAME}
	main.cpp
	${SOURCE_FILES}
)

target_link_libraries(${PROJECT_NAME} Qt5::Core)
target_link_libraries(${PROJECT_NAME} Qt5::Gui)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
