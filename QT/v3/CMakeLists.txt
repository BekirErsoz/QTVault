cmake_minimum_required(VERSION 3.14)

project(untitled1fgfghfghfhfhf LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_library(untitled1fgfghfghfhfhf SHARED
  untitled1fgfghfghfhfhf_global.h
  untitled1fgfghfghfhfhf.cpp
  untitled1fgfghfghfhfhf.h
)

target_link_libraries(untitled1fgfghfghfhfhf PRIVATE Qt${QT_VERSION_MAJOR}::Core)

target_compile_definitions(untitled1fgfghfghfhfhf PRIVATE UNTITLED1FGFGHFGHFHFHF_LIBRARY)
