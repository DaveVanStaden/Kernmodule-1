cmake_minimum_required(VERSION 3.19)
project(SFML)

set(CMAKE_CXX_STANDARD 14)

add_executable(SFML main.cpp Vector2.cpp Vector2.h main.h Circle.cpp Circle.h Player.cpp Player.h Enemy.cpp Enemy.h)
#include_directories(headers /usr/include c:/SFML/include)

# Detect and add SFML
set(SFML_ROOT c:/SFML)
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
message(${CMAKE_MODULE_PATH})

find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
    message("SFML found")
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
    message(${SFML_LIBRARIES})
endif()
if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
    file(GLOB MINGW_DEP_DLLS "C:/Program Files/mingw-w64/bin/*.dll")
    file(COPY ${MINGW_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()