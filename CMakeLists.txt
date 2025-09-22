cmake_minimum_required(VERSION 3.15)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(
  Pro-Log
  VERSION 1.0
  DESCRIPTION "cli programing toolkit"
  LANGUAGES CXX
)

# Global settings
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable folders in IDEs
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory(src)
