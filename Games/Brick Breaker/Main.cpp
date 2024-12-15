#include <iostream>
#include <vector>
#include "Game.hpp"
using namespace std;

int main(){
    BrickBreaker* game = new BrickBreaker(7,7);
    
    while(true){
        game->printBoard();

        if(game->getBallLife() == 0){
            cout<<"Game Ends!!";
            break;
        }
        
        int direction;
        cout<<"Enter the direction: ";
        cin>>direction;

        vector<int>ballPos;
        switch(direction){
            case 8:
                ballPos = game->getBallPos();
                game->initialBall(ballPos[0], ballPos[1], -1, 0);
                break;

            case 6:
                ballPos  = game->getBallPos();
                game->initialBall(ballPos[0], ballPos[1], -1, 1);
                break;

            case 4:
                ballPos = game->getBallPos();
                game->initialBall(ballPos[0], ballPos[1], -1, -1);
                break;

            default:
                cout<<"Choose a valid direction"<<endl;
        }
    }
}