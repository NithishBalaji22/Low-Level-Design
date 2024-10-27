#include<iostream>
#include "SnakeGame.hpp"
using namespace std;

int main(){
    SnakeGame* game = new SnakeGame(6, 6);
    game->intializeSnake();

}