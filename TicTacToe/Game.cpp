#include "Game.hpp"

void Game::switchPlayer(){
    currentPlayer=  (currentPlayer == player1) ? player2 : player1;
}

void Game::play() {
    board->printBoard();
    while(!board->isFull() && !board->hasWinner()){
        cout<<"Currentplayer "<<currentPlayer->getName()<<"'s turn"<<'\n';
        int rows= getValidInput("Enter rows (0-2): ");
        int cols= getValidInput("Enter Columns (0-2): ");

        board->makeMoves(rows, cols, currentPlayer->getSymbol());
        board->printBoard();
        switchPlayer();
    }

    if (board->hasWinner()) {
        cout << currentPlayer->getName() << " wins!\n";
    } else {
        cout << "It's a draw!\n";
    }
}


int Game::getValidInput(string message){
    int input;
    while (true) {
        cout << message << '\n';
        cin >> input;

        if(input >= 0 && input <= 2){
            return input;
        }else{
            cout << "Invalid input, try again.\n";
        }
    }
}
