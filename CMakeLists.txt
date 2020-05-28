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

add_compile_definitions(LIBMUEB_AS_DLL)

find_package(
  Qt5
  COMPONENTS Widgets
  REQUIRED)

if(NOT DEFINED MATRIX_SIMPLE)
  find_package(libmueb 2.0 REQUIRED)
endif()

add_executable(
  ${PROJECT_NAME}
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

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets
                                              libmueb::muebtransmitter)

set(CPACK_PACKAGE_VENDOR "PROJECT_HOMEPAGE_URL")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY ${PROJECT_DESCRIPTION})
set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${PROJECT_VERSION_PATCH})
# set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENCE")
# set(CPACK_RESOURCE_FILE_README "${CMAKE_CURRENT_SOURCE_DIR}/README.md")
include(CPack)
