#pragma once
#include <iostream>
#include <vector>
#include "Board.hpp"
#include "Dice.hpp"
#include "Player.hpp"
using namespace std;

class Game{
    private:
        Board* board;
        Dice* dice;
        vector<Player*> players;
        int currentIndex;
    
    public:
        Game(vector<string> playersName){
            board = new Board();
            dice = new Dice();
            players = vector<Player*>();
            currentIndex = 0;
            for(auto player : playersName){
                players.emplace_back(new Player(player));
            }
        }

        void play(){
            while(!isGameOver()){
                Player* player = players[currentIndex % players.size()];
                int diceRoll = dice->roll();
                int newPosition = player->getPosition() + diceRoll;
                int boardSize = board->getBoardSize();

                if(newPosition < boardSize){
                    int position = board->getPositionAfterSnakeOrLadder(newPosition);
                    player->setPosition(position);
                    cout<<player->getName()<<" Rolled "<<diceRoll<<" and moved to the position "<<newPosition<<endl;
                }

                if(newPosition >= board->getBoardSize()){
                    cout<<player->getName()<<" Rolled "<<diceRoll<<" and Wins!!"<<endl;
                    break;
                }

                currentIndex++;
            }
        }

        bool isGameOver(){
            for(auto player : players){
                if(player->getPosition() >= board->getBoardSize()){
                    return true;
                }
            }
            return false;
        }
};