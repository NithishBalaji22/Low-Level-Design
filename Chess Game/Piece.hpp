#pragma once
#include <iostream>
#include "Colour.hpp"
#include "Board.hpp"
using namespace std;

class Piece{
    protected:
        char pieceName;
        Colour colour;
        int row;
        int col;

    public:
        Piece(char pieceName, Colour colour, int row, int col){
            this->pieceName = pieceName;
            this->colour = colour;
            this->row = row;
            this->col = col;
        }

        Colour getColour(){
            return colour;
        }

        char getPieceName(){
            return pieceName;
        }
        
        void setRow(int row){
            this->row = row;
        }

        void setCol(int col){
            this->col = col;
        }

        int getRow(){
            return row;
        }

        int getCol(){
            return col;
        }

        virtual bool canMove(Board* board, int destRow, int destCol) = 0;
};

class Pawn : public Piece{
    public:
        Pawn(char pieceName, Colour colour, int row, int col) : Piece (pieceName, colour, row, col) {}

        bool canMove(Board* board, int destRow, int destCol) override{
            int rowDiff = destRow - row;
            int colDiff = abs(destCol - col);

            if(colour == Colour::WHITE){
                return (rowDiff == 1 && colDiff == 0) || 
                       (row == 1 && rowDiff == 2 && colDiff == 0) || 
                       (rowDiff == 1 && colDiff == 1 && board->getPiece(destRow, destCol) != nullptr);
            }else{
                return (rowDiff == -1 && colDiff == 0) || 
                       (row == 6 && rowDiff == -2 && colDiff == 0) || 
                       (rowDiff == -1 && colDiff == 1 && board->getPiece(destRow, destCol) != nullptr);
            }
        }
};

class Rook : public Piece{
    public:
        Rook(char pieceName, Colour colour, int row, int col) : Piece (pieceName, colour, row, col) {}

        bool canMove(Board* board, int destRow, int destCol) override{
            return (row == destRow || col == destCol);
        }
};

class Knight : public Piece{
    public:
        Knight(char pieceName, Colour colour, int row, int col) : Piece (pieceName, colour, row, col) {}

        bool canMove(Board* board, int destRow, int destCol) override{
            int rowDiff = abs(destRow - row);
            int colDiff = abs(destCol - col);

            return (rowDiff == 2 && colDiff == 1 || rowDiff == 1 && colDiff == 2);
        }
};

class Bisop : public Piece{
    public:
        Bisop(char pieceName, Colour colour, int row, int col) : Piece (pieceName, colour, row, col) {}

        bool canMove(Board* board, int destRow, int destCol) override{
            int rowDiff = abs(destRow - row);
            int colDiff = abs(destCol - col);

            return (rowDiff == colDiff);
        }
};

class King : public Piece{
    public:
        King(char pieceName, Colour colour, int row, int col) : Piece (pieceName, colour, row, col) {}

        bool canMove(Board* board, int destRow, int destCol) override{
            int rowDiff = abs(destRow - row);
            int colDiff = abs(destCol - col);

            return (rowDiff <= 1 && colDiff <= 1);
        }
};

class Queen : public Piece{
    public:
        Queen(char pieceName, Colour colour, int row, int col) : Piece (pieceName, colour, row, col) {}

        bool canMove(Board* board, int destRow, int destCol) override{
            int rowDiff = abs(destRow - row);
            int colDiff = abs(destCol - col);

            return (row == rowDiff || col == colDiff) || (rowDiff == colDiff) || (rowDiff <= 1 && colDiff <= 1);
        }
};
