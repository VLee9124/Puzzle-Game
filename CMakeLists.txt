cmake_minimum_required(VERSION 3.2)
project(puzzleGame)

add_subdirectory(googletest)

# For each new feature branch, add a new executable with the appropriate directories. 

# add_executable(TEST_EXECUTABLE_NAME
#     <DIRECTORIES>
# )

add_executable(runObjectTests
    test/testObjects.cpp 
    src/gameObject.cpp
)

add_executable(runInventoryClassObjects
    test/testInventory.cpp
    src/gameObject.cpp
    src/inventoryObject.cpp
    src/inventory.cpp
)

TARGET_LINK_LIBRARIES(runObjectTests gtest)
TARGET_COMPILE_DEFINITIONS(runObjectTests PRIVATE gtest_disable_pthreads=ON)

TARGET_LINK_LIBRARIES(runInventoryClassObjects gtest)
TARGET_COMPILE_DEFINITIONS(runInventoryClassObjects PRIVATE gtest_disable_pthreads=ON)