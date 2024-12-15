#include "Board.hpp"

void Board::initializeBoard(){
    for(int rows=0; rows<3; rows++){
        for(int cols=0; cols<3; cols++){
            grid[rows][cols] = '-';
        }
    }

    moveCount = 0;
}

bool Board::hasWinner(){
    //Checking Rows
    for(int rows=0; rows<3; rows++){
        if(grid[rows][0] != '-' && grid[rows][0] == grid[rows][1] && grid[rows][1] == grid[rows][2]){
            return true;
        }
    }

    //Checking Columns
    for(int cols= 0; cols<3; cols++){
        if(grid[0][cols] != '-' && grid[0][cols] == grid[1][cols] && grid[1][cols] == grid[2][cols]){
            return true;
        }        
    }

    //Checking Diagonals
    if(grid[0][0] != '-' && grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]){
        return true;
    }

    return grid[0][2] != '-' && grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0];
}

void Board::makeMoves(int rows, int cols, char symbols){
    if(rows < 0 || rows >= 3 || cols < 0 || cols >= 3 || grid[rows][cols] != '-'){
        cout<<"Invalid Move"<<'\n';
        return;
    }

    grid[rows][cols] = symbols;
    moveCount++;
}

bool Board::isFull(){
    return moveCount == 9;
}

void Board::printBoard(){
    for(int rows = 0; rows < 3; rows++){
        for(int cols = 0; cols < 3; cols++){
            cout << grid[rows][cols] << ' ';
        }
        cout << '\n';
    }
}



