
// Program: TicTacToe.cpp
// Purpose: This program is a game of Tic Tac Toe.
// Author:  Andrew Reigle

#include "Tictactoe.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

// Constructor
TicTacToeGame::TicTacToeGame() {
  pp_cGrid = new char *[3]; // array of three pointers to char
  for (int i = 0; i < 3; ++i) {
    pp_cGrid[i] = new char[3]; // each pointer points to an array of three chars
  }

  initializeGrid(); // set all elements to '~'
}

// Destructor
TicTacToeGame::~TicTacToeGame() { deallocateGrid(); }

// Initialize the grid with '~'
void TicTacToeGame::initializeGrid() {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      pp_cGrid[i][j] = '~';
    }
  }
}

// Display the current state of the grid
void TicTacToeGame::displayGrid() {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      std::cout << pp_cGrid[i][j] << ' ';
    }
    std::cout << std::endl;
  }
}

// Check if a move is valid
bool TicTacToeGame::isMoveValid(int row, int col) {
  if (row < 0 || row >= 3 || col < 0 || col >= 3) {
    std::cout << "Invalid row or column. Please enter values between 0 and 2."
              << std::endl;
    return false;
  }

  if (pp_cGrid[row][col] != '~') {
    std::cout << "Grid square [" << row << "]"
              << "[" << col << "] already taken." << std::endl;
    return false;
  }

  return true;
}

// Check if the grid is full
bool TicTacToeGame::isGridFull() {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (pp_cGrid[i][j] == '~') {
        return false; // Grid is not full
      }
    }
  }
  return true; // Grid is full
}

// Check if a player has won
bool TicTacToeGame::checkWin(char player) {
  // Check rows and columns
  for (int i = 0; i < 3; ++i) {
    if ((pp_cGrid[i][0] == player && pp_cGrid[i][1] == player &&
         pp_cGrid[i][2] == player) ||
        (pp_cGrid[0][i] == player && pp_cGrid[1][i] == player &&
         pp_cGrid[2][i] == player)) {
      return true; // Player has won
    }
  }

  // Check diagonals
  if ((pp_cGrid[0][0] == player && pp_cGrid[1][1] == player &&
       pp_cGrid[2][2] == player) ||
      (pp_cGrid[0][2] == player && pp_cGrid[1][1] == player &&
       pp_cGrid[2][0] == player)) {
    return true; // Player has won
  }

  return false; // No win yet
}

void TicTacToeGame::computerMove() {
  // Iterate over the grid to find an available square
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        if (pp_cGrid[i][j] == '~') {
          pp_cGrid[i][j] = 'O';
          return;
        }
      }
    }
  }


// Deallocate memory for the grid
void TicTacToeGame::deallocateGrid() {
  for (int i = 0; i < 3; ++i) {
    delete[] pp_cGrid[i];
  }
  delete[] pp_cGrid;
}

// Play the Tic-tac-toe game
void TicTacToeGame::play() {
  // Game loop
  std::cout << "Tic Tac Toe " << std::endl;
  std::cout << "The top row is row number 0, the middle row is row number 1, "
               "and the bottom row is row number 2."
            << std::endl;
  std::cout << "The left column is column number 0, the middle column is "
               "column number 1, and the right."
            << std::endl;
  std::cout << "~ ~ ~" << std::endl;
  std::cout << "~ ~ ~" << std::endl;
  std::cout << "~ ~ ~" << std::endl;
  while (true) {
    // Human player's move
    int userRow, userCol;

    do {

      std::cout << "Enter grid row number: " << std::endl;
      std::cin >> userRow;
      std::cout << "Enter grid column number: " << std::endl;
      std::cin >> userCol;
    } while (!isMoveValid(userRow, userCol));

    pp_cGrid[userRow][userCol] = 'X';
    displayGrid();

    // Check for human player win
    if (checkWin('X')) {
      std::cout << "Congratulations! You win!" << std::endl;
      break;
    }

    // Check for a draw
    if (isGridFull()) {
      std::cout << "It's a draw!" << std::endl;
      break;
    }

    // Computer player's move
    std::cout << "Computer's move:" << std::endl;
    computerMove();
    displayGrid();

    // Check for computer player win
    if (checkWin('O')) {
      std::cout << "Computer wins! Better luck next time." << std::endl;
      break;
    }

    // Check for a draw
    if (isGridFull()) {
      std::cout << "It's a draw!" << std::endl;
      break;
    }
  }
}
