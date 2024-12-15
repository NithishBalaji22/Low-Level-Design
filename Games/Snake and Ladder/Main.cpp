#include <iostream>
#include <vector>
#include "Game.hpp"
using namespace std;

int main(){
    vector<string> players = {"Nithish", "Balaji"};
    Game* game = new Game(players);
    game->play();
}