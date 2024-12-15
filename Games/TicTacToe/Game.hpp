#pragma once
#include "Board.hpp"
#include "Players.hpp"
#include "bits/stdc++.h"
using namespace std;

class Players;
class Board;

class Game{
    private:
        Players* player1;
        Players* player2;
        Board* board;
        Players* currentPlayer;

    public:
        Game(Players* player1, Players* players2){
            this->player1 = player1;
            this->player2 = player2;
            board = new Board();
            currentPlayer = player1;
        }    

        void switchPlayer();
        int getValidInput(string message);
        void play();
};