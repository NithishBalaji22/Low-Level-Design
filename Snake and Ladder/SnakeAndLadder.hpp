#pragma once
#include"Board.hpp"
#include"Dice.hpp"
#include"Ladders.hpp"
#include"Players.hpp"
#include"Snake.hpp"
#include<bits/stdc++.h>
using namespace std;

class SnakeAndLadder{
    private:
        Board* board;
        Dice* dice;
        vector<Player*> players;
        int currentPlayerIndex;

    public:
        SnakeAndLadder(vector<string> player){
            board = new Board;
            dice = new Dice;
            
            for(string name : player){
                players.emplace_back(new Player(name));
            }

            currentPlayerIndex = 0;
        }

        void play(){
            while(!isGameOver()){
                Player* currPlayer = players[currentPlayerIndex];
                int diceRoll = dice->roll();
                int newPosition = currPlayer->getPosition() + diceRoll;

                if(newPosition < board->getBoardSize()){
                    currPlayer->setPosition(board->getNewPositionAfterSnakeOrLadder(newPosition));
                    cout<<currPlayer->getName()<<" rolled a "<<diceRoll<<" and got move to the position: "<<currPlayer->getPosition()<<'\n';
                }

                if(newPosition == board->getBoardSize()){
                    cout<<currPlayer->getName()<<" Wins!";
                    break;
                }

                currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
            }
        }

        bool isGameOver(){
            for(Player* p : players){
                if(p->getPosition() == board->getBoardSize()){
                    return true;
                }
            }
            return false;
        }
};