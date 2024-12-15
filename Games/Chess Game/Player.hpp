#pragma once
#include<iostream>
#include "Colour.hpp"
#include "Board.hpp"
#include "Piece.hpp"
#include "Move.hpp"
using namespace std;

class Player{
    private:
        string name;
        Colour colour;

    public:
        Player(string name, Colour colour){
            this->name = name;
            this->colour = colour;
        }

        string getName(){
            return name;
        }

        Colour getColour(){
            return colour;
        }

        bool makeMove(Board* board, Move* move){
            Piece* piece = move->getPiece();
            int destRow = move->getDestRow();
            int destCol = move->getDestCol();

            if(board->isValidMove(piece, destRow, destCol)){
                int sourceRow = piece->getRow();
                int sourceCol = piece->getCol();
                board->setPiece(nullptr, sourceRow, sourceCol);
                board->setPiece(piece, destRow, destCol);
                piece->setRow(destRow);
                piece->setCol(destCol);
                return true;
            }
            cout<<"Invalid Move"<<'\n';
            return false;            
        }
};

