cmake_minimum_required(VERSION 3.10)

set(GUI PCB_Traces_GUI)

project(${GUI})

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
#set(CMAKE_PREFIX_PATH $ENV{QTDIR})
#set(Qt5_DIR C:/Qt/5.13.2/msvc2017_64/lib/cmake/Qt5)

#include_directories(C:/Qt/5.13.2/msvc2017_64/include/QtCore)
#include_directories(C:/Qt/5.13.2/msvc2017_64/include/QtGui)
#include_directories(C:/Qt/5.13.2/msvc2017_64/include/QtWidgets)
#set(Qt5Core_DIR    "$ENV{QTDIR}/lib/cmake/Qt5Core" CACHE PATH "Qt5 Core directory")
#set(Qt5Widgets_DIR "$ENV{QTDIR}/lib/cmake/Qt5Widgets")

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS Core REQUIRED)
find_package(Qt5 COMPONENTS Gui REQUIRED)

set(HEADERS 
	"MainWindow.h"
	"PCB_scene.h"
)

set(SOURCES
	"MainWindow.cpp" 
	"main.cpp" 
	"PCB_scene.cpp")

add_executable(${GUI} ${SOURCES} ${HEADERS})
target_link_libraries(${GUI} Qt5::Widgets)
target_link_libraries(${GUI} Qt5::Core)
target_link_libraries(${GUI} Qt5::Gui)

target_link_libraries(${GUI} ${CMAKE_PROJECT_NAME}_lib)