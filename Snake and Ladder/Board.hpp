#pragma once
#include<iostream>
#include<vector>
#include "Snake.hpp"
#include "Ladders.hpp"

using namespace std;

class Board{
    private:
        static const int BOARD_SIZE = 100;
        vector<Ladder*> ladders;
        vector<Snake*> snakes;

    public:
        Board(){
            ladders = vector<Ladder*>();
            snakes = vector<Snake*>();
            initializeBoard();
        }

        void initializeBoard(){
            //Initializing snakes
            snakes.emplace_back(new Snake(16, 6));
            snakes.emplace_back(new Snake(48, 26));
            snakes.emplace_back(new Snake(64, 60));
            snakes.emplace_back(new Snake(93, 73));

            //Initializing ladders
            ladders.emplace_back(new Ladder(1, 38));
            ladders.emplace_back(new Ladder(4, 14));
            ladders.emplace_back(new Ladder(9, 31));
            ladders.emplace_back(new Ladder(21, 42));
            ladders.emplace_back(new Ladder(28, 84));
            ladders.emplace_back(new Ladder(51, 67));
            ladders.emplace_back(new Ladder(80, 99));
        }

        int getBoardSize(){
            return BOARD_SIZE;
        }

        int getNewPositionAfterSnakeOrLadder(int position){
            for(Snake* s : snakes){
                if(s->getStart() == position){
                    return s->getEnd();
                }
            }

            for(Ladder* l : ladders){
                if(l->getStart() == position){
                    return l->getEnd();
                }
            }

            return position;
        }
};

const int Board :: BOARD_SIZE;
