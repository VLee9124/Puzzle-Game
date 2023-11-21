cmake_minimum_required(VERSION 3.2)
project(puzzleGame)

add_subdirectory(googletest)

# For each new feature branch, add a new executable with the appropriate directories. 

# add_executable(runAllTests
# )

# add_executable(TEST_EXECUTABLE_NAME
#     <DIRECTORIES>
# )

TARGET_LINK_LIBRARIES(runAllTests gtest)
TARGET_COMPILE_DEFINITIONS(runAllTests PRIVATE gtest_disable_pthreads=ON)