#pragma once
#include <iostream>
#include <vector>
#include "Board.hpp"
#include "Colour.hpp"
#include "Move.hpp"
#include "Piece.hpp"
#include "Player.hpp"
using namespace std;

class Game{
    private:
        Board* board;
        vector<Player*> players;
        int currentPlayer;
    public:
        Game(){
            players = {new Player("Nithish", Colour::WHITE), new Player("Balaji",Colour::BLACK)};
            board = new Board(8,8);
            currentPlayer = 0;
        }

        void execute(){
            while(!board->checkMate()){
                printBoard();

                Player* player = players[currentPlayer];
                cout<<endl;
                cout<<player->getName()<<"'s Turn : " << endl;

                Move* move = getMove(player);
                player->makeMove(board, move);

                currentPlayer = (currentPlayer + 1) % 2;                
            }
        }

        Move* getMove(Player* player){
            int sourceRow, sourceCol, dRow, dCol;

            cout<<"Enter Source Row and Source Column: ";
            cin>>sourceRow>>sourceCol;

            Piece* piece = board->getPiece(sourceRow, sourceCol);

            cout<<"Enter Destination Row and Destination Column: ";
            cin>>dRow>>dCol;
            cout<<endl;
            
            if(piece == nullptr || piece->getColour() != player->getColour()){
                cout<<"You have choosed wrong piece Choose again carefully !!"<<endl;
                return nullptr;
            }

            return new Move(piece, dRow, dCol);
        }

        void printBoard(){
            board->printBoard();
        }
};