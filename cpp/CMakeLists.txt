cmake_minimum_required(VERSION 3.14)
project(event_sourcing_kata LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Fetch Catch2 for testing
include(FetchContent)
FetchContent_Declare(
  catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.4.0 # or latest tag you prefer
)
FetchContent_MakeAvailable(catch2)

add_library(event_core INTERFACE)
target_include_directories(event_core INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/src)

#add_executable(counter_example
#  src/examples/CounterAggregate.cpp
#)
#target_link_libraries(counter_example PRIVATE event_core)

add_executable(tests
  tests/CounterAggregate.test.cpp
  src/examples/CounterAggregate.cpp
)
target_link_libraries(tests PRIVATE event_core Catch2::Catch2WithMain)
target_include_directories(tests PRIVATE src)

# enable testing
include(CTest)
add_test(NAME unit_tests COMMAND tests)
