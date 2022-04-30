cmake_minimum_required(VERSION 3.22)
project(IMC)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(main source/main.cpp)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)
add_executable(unit_tests test/unit_tests.cpp)
target_link_libraries(unit_tests ${Boost_LIBRARIES})

enable_testing()
add_test(NAME UnitTests COMMAND unit_tests)