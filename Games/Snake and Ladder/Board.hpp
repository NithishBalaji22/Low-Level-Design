#pragma once
#include <iostream>
#include <vector>
#include "Snake.hpp"
#include "Ladder.hpp"
using namespace std;

class Board{
    private:
        vector<Snake*> snakes;
        vector<Ladder*> ladders;
        int BOARD_SIZE;
    
    public:
        Board(){
            BOARD_SIZE = 100;
            snakes = vector<Snake*>();
            ladders = vector<Ladder*>();
            initializeBoard();
        }

        void initializeBoard(){
            // Initializing Snakes
            snakes.emplace_back(new Snake(16, 6));
            snakes.emplace_back(new Snake(48, 26));
            snakes.emplace_back(new Snake(64, 60));
            snakes.emplace_back(new Snake(93, 73));

            // Initializing ladders
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

        int getPositionAfterSnakeOrLadder(int position){
            for(auto snake : snakes){
                if(snake->getStart() == position){
                    return snake->getEnd();
                }
            }

            for(auto ladder : ladders){
                if(ladder->getStart() == position){
                    return ladder->getEnd();
                }
            }

            return position;
        }
};