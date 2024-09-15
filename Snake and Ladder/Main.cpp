#include"SnakeAndLadder.hpp"
#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<string> players = {"Nithish", "Balaji", "Sri Ganesh"};
    SnakeAndLadder* game = new SnakeAndLadder(players);
    game->play();
}