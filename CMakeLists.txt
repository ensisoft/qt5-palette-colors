cmake_minimum_required(VERSION 3.0)

project(qt-palette-colors)

set(CMAKE_CXX_STANDARD 17)

# supposedly least crappy way to try to encourage
# cmake to play ball with Qt
set(CMAKE_PREFIX_PATH "C:/Qt/5.15.2/msvc2019_64")

find_package(Qt5Widgets)
find_package(Qt5Core)
find_package(Qt5Svg)
if (NOT Qt5Widgets_FOUND)
    message("
Qt5 was not found. Please edit the path in this file.
")
endif()


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# this tells cmake to include our *current* directory which is our build directory
# in which the Qt tools (moc and uic) will spit out their generated files.
# so for example when you have "include ui_foobar.h" in your code the
# ui_foobar.h is generated by UIC and will be placed in the current dir.
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(qt-palette-colors
  main.cpp
  widget.cpp
  widget.h
  widget.ui)
target_link_libraries(Test Qt5::Widgets Qt5::Core)
target_include_directories(Test PRIVATE "${CMAKE_CURRENT_LIST_DIR}/src")
