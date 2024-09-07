#include "Board.hpp"
#include "Game.hpp"
#include "Players.hpp"
#include <bits/stdc++.h>
using namespace std;

int main(){
    Players* player1= new Players("Nithish", 'X');
    Players* player2= new Players("Balaji", 'O');

    Game* game = new Game(player1, player2);
    game->play();
}