#include<iostream>
#include "BrickBreaker.hpp"
using namespace std;

int main(){
    BrickBreaker* game = new BrickBreaker(7, 7);
    game->placeBricks(2,2,2);
    game->placeBricks(2,3,2);
    game->placeBricks(2,4,2);
    game->placeBricks(3,2,2);
    game->placeBricks(3,3,2);
    game->placeBricks(3,4,2);

    while(true){
        game->printGameBoard();

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