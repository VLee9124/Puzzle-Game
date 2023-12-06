cmake_minimum_required(VERSION 3.2)
project(puzzleGame)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")

add_subdirectory(googletest)

# For each new feature branch, add a new executable with the appropriate directories. 

# add_executable(TEST_EXECUTABLE_NAME
#     <DIRECTORIES>
# )

add_executable(runObjectTests
    test/testObjects.cpp 
    src/gameObject.cpp
)

add_executable(runInventoryTests
    test/testInventory.cpp
    src/gameObject.cpp
    src/inventoryObject.cpp
    src/inventory.cpp
)

add_executable(runRoomTests
    test/testRoom.cpp
    src/room.cpp
    src/gameObject.cpp
    src/door.cpp
)

add_executable(runDoorTests
    test/testDoor.cpp
    src/door.cpp
    src/gameObject.cpp
    src/room.cpp
)

# add_executable(runTerminalTests
#     test/testGameTerminal.cpp
#     src/gameObject.cpp
#     src/door.cpp
#     src/inventoryObject.cpp
#     src/inventory.cpp
#     src/room.cpp
#     src/Player.cpp
#     src/gameTerminal.cpp
# )

add_executable(runPlayerClassTest
    test/testPlayer.cpp
    src/player.cpp
    src/room.cpp
    src/inventory.cpp
    src/door.cpp
    src/inventoryObject.cpp
    src/gameObject.cpp
)

add_executable(runPuzzleTests
    test/testPuzzle.cpp
    src/puzzle.cpp
)

add_executable(runKeyPadTests
    test/testKeyPad.cpp
    src/keyPadpuzzle.cpp
    src/puzzle.cpp
    src/gameObject.cpp
)

TARGET_LINK_LIBRARIES(runKeyPadTests gtest)
TARGET_COMPILE_DEFINITIONS(runKeyPadTests PRIVATE gtest_disable_pthreads=ON)

TARGET_LINK_LIBRARIES(runPuzzleTests gtest)
TARGET_COMPILE_DEFINITIONS(runPuzzleTests PRIVATE gtest_disable_pthreads=ON)

TARGET_LINK_LIBRARIES(runPlayerClassTest gtest)
TARGET_COMPILE_DEFINITIONS(runPlayerClassTest PRIVATE gtest_disable_pthreads=ON)

TARGET_LINK_LIBRARIES(runObjectTests gtest)
TARGET_COMPILE_DEFINITIONS(runObjectTests PRIVATE gtest_disable_pthreads=ON)

TARGET_LINK_LIBRARIES(runInventoryTests gtest)
TARGET_COMPILE_DEFINITIONS(runInventoryTests PRIVATE gtest_disable_pthreads=ON)

TARGET_LINK_LIBRARIES(runRoomTests gtest)
TARGET_COMPILE_DEFINITIONS(runRoomTests PRIVATE gtest_disable_pthreads=ON)

TARGET_LINK_LIBRARIES(runDoorTests gtest)
TARGET_COMPILE_DEFINITIONS(runDoorTests PRIVATE gtest_disable_pthreads=ON)

# TARGET_LINK_LIBRARIES(runTerminalTests gtest)
# TARGET_COMPILE_DEFINITIONS(runTerminalTests PRIVATE gtest_disable_pthreads=ON)