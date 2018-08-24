
cmake_minimum_required(VERSION 3.5.1)

project(bomberman)

include_directories(include/)
# include_directories(/usr/include/)

set(CMAKE_CXX_FLAGS "-std=c++14 -Wall -Wextra -Wno-reorder")
set(DIRC ./src)

set(SOURCE_FILES	${DIRC}/main.cpp
			${DIRC}/MainMenu.cpp
			${DIRC}/MenuGame.cpp
			${DIRC}/libirrlicht.cpp
			${DIRC}/core.cpp
			${DIRC}/MovePlayer.cpp
			${DIRC}/Bomberman.cpp)

message(STATUS "This is BINARY dir " ${PROJECT_BINARY_DIR})
message(STATUS "This is SOURCE dir " ${PROJECT_SOURCE_DIR})

add_executable(bomberman ${SOURCE_FILES})

target_link_libraries(bomberman Irrlicht)
target_link_libraries(bomberman GL)
target_link_libraries(bomberman GLU)
target_link_libraries(bomberman sfml-audio)
