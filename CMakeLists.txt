cmake_minimum_required(VERSION 3.24)
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
        Napisy.cpp
        Napisy.h
        Napis.cpp
        Napis.h
        Konsola.cpp
        Konsola.cpp
        Konsola.h
        Konsola.h
        Czcionki.cpp
        Czcionki.cpp
        Czcionki.h
        Czcionki.h
)
target_link_libraries(GameProject sfml-graphics)
