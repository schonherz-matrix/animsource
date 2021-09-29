cmake_minimum_required(VERSION 3.16)

project(
        animsource
        DESCRIPTION "Widget for sending predefined animations"
        HOMEPAGE_URL "kszk.bme.hu"
        LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(
        Qt6
        COMPONENTS Widgets
        REQUIRED)

add_executable(
        ${PROJECT_NAME} WIN32
        src/abstractanimation.cpp
        src/abstractanimation.h
        src/animfactory.cpp
        src/animfactory.h
        src/animsender.cpp
        src/animsender.h
        src/animsender.ui
        src/chessanim.cpp
        src/chessanim.h
        src/columnanim.cpp
        src/columnanim.h
        src/main.cpp
        src/rowanim.cpp
        src/rowanim.h
        src/solidanim.cpp
        src/solidanim.h
        src/verticalanim.cpp
        src/verticalanim.h
        src/windowanim.cpp
        src/windowanim.h)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets
        muebtransmitter)
