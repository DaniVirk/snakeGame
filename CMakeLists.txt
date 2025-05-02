cmake_minimum_required(VERSION 3.20)
project(snakeGame)

# Force 64-bit build
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m64")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -m64 -static-libgcc -static-libstdc++")

# SFML path
set(SFML_DIR "C:/cpp-lib/SFML-3.0.0/lib/cmake/SFML")

find_package(SFML 3.0 COMPONENTS Graphics Window System REQUIRED)

add_executable(snakeGame main.cpp
        src/game_engine/Snake.cpp
        src/headers/Snake.h
        src/game_engine/game_settings.cpp
        src/headers/game_settings.h
        src/game_engine/Game.cpp
        src/headers/Game.h)

target_link_libraries(snakeGame
        PRIVATE
        SFML::Graphics
        SFML::Window
        SFML::System
)

# DLL handling
if(WIN32)
    add_custom_command(TARGET snakeGame POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy
            "C:/cpp-lib/SFML-3.0.0/bin/sfml-graphics-3.dll"
            "C:/cpp-lib/SFML-3.0.0/bin/sfml-window-3.dll"
            "C:/cpp-lib/SFML-3.0.0/bin/sfml-system-3.dll"
            "C:/cpp-lib/SFML-3.0.0/bin/sfml-graphics-d-3.dll"
            "C:/cpp-lib/SFML-3.0.0/bin/sfml-window-d-3.dll"
            "C:/cpp-lib/SFML-3.0.0/bin/sfml-system-d-3.dll"
            $<TARGET_FILE_DIR:snakeGame>  # Copies the DLLs to the build output directory
    )
endif()
