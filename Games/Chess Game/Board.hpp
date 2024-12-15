#pragma once
#include <iostream>
#include <vector>
#include <thread>
using namespace std;

class Piece;
class Board{
    private:
        int row;
        int col;
        vector<vector<Piece*>> board;

    public:
        Board(int row, int col);
        void intializeBoard();
        Piece* getPiece(int row, int col);
        void setPiece(Piece* piece, int row, int col);
        bool isValidMove(Piece* piece, int destRow, int destCol);
        bool checkMate();
        void printBoard();
};

