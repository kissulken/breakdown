# CMakeList.txt: проект CMake для Breakdown; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (BreakdownUnitTest ${sources} test.cpp)
link_libraries(gtest gtest_main gmock)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Breakdown PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
