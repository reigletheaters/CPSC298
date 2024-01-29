
#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToeGame {
public:
  // Constructor and Destructor
  TicTacToeGame();
  ~TicTacToeGame();

  // Public function to play the game
  void play();

private:
  char **pp_cGrid; // Pointer to a pointer to character

  void initializeGrid();
  void displayGrid();
  bool isMoveValid(int row, int col);
  bool isGridFull();
  bool checkWin(char player);

  // AI function for computer's move
  void computerMove();

  // Function to deallocate memory for the grid
  void deallocateGrid();
};

#endif // TICTACTOE_H
