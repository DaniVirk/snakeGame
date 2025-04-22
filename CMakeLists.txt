cmake_minimum_required(VERSION 3.20)
project(snakeGame)

set(CMAKE_CXX_STANDARD 20)

# 32-bit specific flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m32")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -m32 -static-libgcc -static-libstdc++")

# SFML configuration
set(SFML_DIR "C:/cpp-lib/SFML-3.0.0/lib/cmake/SFML")
find_package(SFML 3.0 COMPONENTS Graphics Window System REQUIRED)

add_executable(snakeGame main.cpp)

target_link_libraries(snakeGame
        PRIVATE
        SFML::Graphics
        SFML::Window
        SFML::System
)

# Improved DLL copy command
if(WIN32)
    add_custom_command(TARGET snakeGame POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E make_directory $<TARGET_FILE_DIR:snakeGame>
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${SFML_DIR}/../../bin/sfml-graphics-3.dll"
            $<TARGET_FILE_DIR:snakeGame>
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${SFML_DIR}/../../bin/sfml-window-3.dll"
            $<TARGET_FILE_DIR:snakeGame>
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${SFML_DIR}/../../bin/sfml-system-3.dll"
            $<TARGET_FILE_DIR:snakeGame>
            COMMENT "Copying SFML DLLs"
    )
endif()