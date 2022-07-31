# CMakeList.txt: проект CMake для Breakdown; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
file(GLOB_RECURSE sources      src/*.cpp src/*.h)
add_executable (Breakdown main.cpp ${sources})
#add_subdirectory (unitTest)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Breakdown PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
