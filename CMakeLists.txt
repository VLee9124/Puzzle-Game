cmake_minimum_required(VERSION 3.2)
project(puzzleGame)

add_subdirectory(googletest)

set(SOURCE_FILES
    src/gameObject.cpp
    src/inventoryObject.cpp
    src/door.cpp
    src/inventory.cpp
    src/Player.cpp
    src/room.cpp
    src/gameTerminal.cpp
)

set(TEST_FILES
    test/testObjects.cpp
    test/testInventory.cpp
    test/testRoom.cpp
    # test/testGameTerminal.cpp
)

add_executable(runAllTests
    ${TEST_FILES}
    ${SOURCE_FILES}
)

target_link_libraries(runAllTests gtest gtest_main)