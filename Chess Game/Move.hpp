#pragma once
#include<iostream>
#include "Piece.hpp"
using namespace std;

class Move{
    private:
        Piece* piece;
        int destRow;
        int destCol;

    public:
        Move(Piece* piece, int destRow, int destCol){
            this->piece = piece;
            this->destRow = destRow;
            this->destCol = destCol;
        }

        Piece* getPiece(){
            return piece;
        }

        int getDestRow(){
            return destRow;
        }

        int getDestCol(){
            return destCol;
        }
};