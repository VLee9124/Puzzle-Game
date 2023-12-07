#include <gtest/gtest.h>
#include "../include/keypadPuzzle.hpp"
#include <sstream>
using namespace std;

TEST(KeypadPuzzleTests, DefaultConstructor) {
  Puzzle* myPuzzle = new KeypadPuzzle("Enter a four digit number.", 1234);
  ASSERT_NO_THROW(myPuzzle);
  delete myPuzzle;
}

TEST(KeypadPuzzleTests, CorrectInput) {
  ostringstream oss;
  istringstream iss("1234");
  Puzzle* myPuzzle = new KeypadPuzzle("Enter a four digit number.", 1234);

  myPuzzle->solvePuzzle(oss, iss);

  EXPECT_TRUE(myPuzzle->getSolved());
  EXPECT_EQ(oss.str(), "Enter a four digit number.\n\n> \n\nCORRECT. The puzzle is now solved.\n\n");
  
  delete myPuzzle;
}

TEST(KeypadPuzzleTests, CorrectNegativeInput) {
  ostringstream oss;
  istringstream iss("-1234");
  Puzzle* myPuzzle = new KeypadPuzzle("Enter a four digit number.", -1234);

  myPuzzle->solvePuzzle(oss, iss);

  EXPECT_TRUE(myPuzzle->getSolved());
  EXPECT_EQ(oss.str(), "Enter a four digit number.\n\n> \n\nCORRECT. The puzzle is now solved.\n\n");
  
  delete myPuzzle;
}

TEST(KeypadPuzzleTests, LargeCorrectInput) {
  ostringstream oss;
  istringstream iss("2147483647");
  Puzzle* myPuzzle = new KeypadPuzzle("Enter a ten digit number.", 2147483647);

  myPuzzle->solvePuzzle(oss, iss);

  EXPECT_TRUE(myPuzzle->getSolved());
  EXPECT_EQ(oss.str(), "Enter a ten digit number.\n\n> \n\nCORRECT. The puzzle is now solved.\n\n");
  
  delete myPuzzle;
}

TEST(KeypadPuzzleTests, IncorrectInput) {
  ostringstream oss;
  istringstream iss("310248");
  Puzzle* myPuzzle = new KeypadPuzzle("Enter a six digit number.", 391729);

  myPuzzle->solvePuzzle(oss, iss);

  EXPECT_FALSE(myPuzzle->getSolved());
  EXPECT_EQ(oss.str(), "Enter a six digit number.\n\n> \n\nINCORRECT. The puzzle remains unsolved.\n\n");
  
  delete myPuzzle;
}

TEST(KeypadPuzzleTests, BadInput) {
  ostringstream oss;
  istringstream iss("abcd");
  Puzzle* myPuzzle = new KeypadPuzzle("Enter a four digit number.", 1234);

  EXPECT_THROW(myPuzzle->solvePuzzle(oss, iss), runtime_error);

  delete myPuzzle;
}

TEST(KeypadPuzzleTests, OverflowInput) {
  ostringstream oss;
  istringstream iss("9876543210");
  Puzzle* myPuzzle = new KeypadPuzzle("Enter a ten digit number.", 9876543210);

  EXPECT_THROW(myPuzzle->solvePuzzle(oss, iss), runtime_error);

  delete myPuzzle;
}