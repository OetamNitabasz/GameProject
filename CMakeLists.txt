cmake_minimum_required(VERSION 3.28)
project(GameProject)

set(CMAKE_CXX_STANDARD 20)

set(BUILD_SHARED_LIBS FALSE)

include(FetchContent)

FetchContent_Declare(
        SFML
        GIT_REPOSITORY  https://github.com/SFML/SFML
        GIT_TAG         2.6.1
)

FetchContent_MakeAvailable(SFML)

add_executable(GameProject main.cpp
        Player.cpp
        Player.h
        TileMap.cpp
        TileMap.h
        Napisy.cpp
        Napisy.h
        Napis.h
        Napis.cpp)
target_link_libraries(GameProject sfml-graphics)
