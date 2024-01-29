#include "Tictactoe.h"

int main() {
    // Create an instance of game
    TicTacToeGame* p_game = new TicTacToeGame();


    p_game->play();


    delete p_game;

    return 0;
}

