cmake_minimum_required(VERSION 3.10)
project(CPP-OOP-LABS VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(src/include)

add_executable(lab
    src/main.cpp
    src/core/battle_visitor.cpp
    src/core/squirrel.cpp
    src/core/dungeon.cpp
    src/core/npc_factory.cpp
    src/core/npc.cpp
    src/core/observer_console.cpp
    src/core/observer_file.cpp
    src/core/point.cpp
    src/core/elf.cpp
    src/core/rogue.cpp
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.0
  TLS_VERIFY false
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(tests
    src/tests/unit.cpp
    src/tests/battle_visitor.cpp
    src/tests/squirrel.cpp
    src/tests/dungeon.cpp
    src/tests/npc_factory.cpp
    src/tests/observer_console.cpp
    src/tests/observer_file.cpp
    src/tests/point.cpp
    src/tests/rogue.cpp
    src/tests/elf.cpp
    src/core/battle_visitor.cpp
    src/core/squirrel.cpp
    src/core/dungeon.cpp
    src/core/npc_factory.cpp
    src/core/npc.cpp
    src/core/observer_console.cpp
    src/core/observer_file.cpp
    src/core/point.cpp
    src/core/rogue.cpp
    src/core/elf.cpp
)

target_link_libraries(tests GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)