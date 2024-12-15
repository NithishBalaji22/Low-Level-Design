#include "SnakeGame.hpp"
#include <iostream>
using namespace std;

int main(){
    SnakeGame* game = new SnakeGame(6,6);
    game->startGame();
}