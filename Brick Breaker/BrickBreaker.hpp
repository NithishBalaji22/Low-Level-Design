#include<bits/stdc++.h>
#include <thread>
#include <chrono>
using namespace std;

class BrickBreaker{
    private:
        int ballLife = 5;
        string Wall = "W";
        string Ground = "G";
        string Ball = "O";
        string Brick = "1";
        vector<int> ballPos;
        vector<vector<string>> gameBoard;
        unordered_map<int, int> bricksLife; // BrickPosition, Life

    public:
        BrickBreaker(int rows, int cols){
            gameBoard = vector<vector<string>>(rows, vector<string>(cols, ""));
            prePareBoard();
            gameBoard[rows-1][(cols/2)] = Ball;
            ballPos = {rows-1, cols/2};
        }

        void placeBricks(int row, int col, int life){
            gameBoard[row][col] = Brick;
            int brickPosition = getBrickExactPosition(row, col);
            bricksLife[brickPosition] = life;
        }

        void initialBall(int ballRow, int ballCol, int rowDirection, int colDirection){
            moveDirection(ballRow, ballCol, rowDirection, colDirection);
            if(gameBoard[ballRow][ballCol] != Ball){
                gameBoard[ballRow][ballCol] = Ground;
            }
        }

        void moveDirection(int ballRow, int ballCol, int rowDirection, int colDirection){
            while(gameBoard[ballRow][ballCol] != Wall){
                if(gameBoard[ballRow][ballCol] == Brick){
                    ballGoesDown(ballRow, ballCol);
                    return;
                }                
                movingIllusion(ballRow, ballCol);
                ballRow += rowDirection;
                ballCol += colDirection;
            }

            wallHit(ballRow, ballCol);

            rowDirection = 0;
            colDirection *= -1;

            if(colDirection == 0){
                ballGoesDown(ballRow+1, ballCol);
            }else{
                moveDirection(ballRow, ballCol + colDirection, rowDirection, colDirection);
            }
        }

        int getBrickExactPosition(int row, int col){
            return (row * gameBoard[0].size()) + col + 1;
        }

        void wallHit(int ballRow, int ballCol){
            gameBoard[ballRow][ballCol] = Ball;
            printGameBoard();
            sleepForASecond();
            gameBoard[ballRow][ballCol] = Wall;
        }

        void ballGoesDown(int ballRow, int ballCol){
            while(ballRow != gameBoard.size()){
                movingIllusion(ballRow, ballCol);
                ballRow++;
            }

            ballPos[0] = ballRow-1;
            ballPos[1] = ballCol;
            gameBoard[ballPos[0]][ballPos[1]] = Ball;
        }

        void movingIllusion(int ballRow, int ballCol){
            if(gameBoard[ballRow][ballCol] != Brick){
                gameBoard[ballRow][ballCol] = Ball;
                printGameBoard();
                gameBoard[ballRow][ballCol] = " ";
                sleepForASecond();
            }else{
                reduceBrickAndBallLife(ballRow, ballCol);
                if(bricksLife[getBrickExactPosition(ballRow, ballCol)] == 0){
                    gameBoard[ballRow][ballCol] = " ";
                }               
            }
        }

        void reduceBrickAndBallLife(int ballRow, int ballCol){
            int brickPosition = getBrickExactPosition(ballRow, ballCol);
            ballLife--;

            if(ballLife > 0){
                bricksLife[brickPosition] -= 1;
            }
        }

        void printGameBoard(){
            int rows = gameBoard.size();
            int cols = gameBoard[0].size();

            for(int row=0; row<rows; row++){
                for(int col= 0; col<cols; col++){
                    cout<<gameBoard[row][col]<<" ";
                }
                cout<<endl;
            }
        }

        void prePareBoard(){
            int rows = gameBoard.size();
            int cols = gameBoard[0].size();
            for(int row=0; row<rows; row++){
                for(int col=0; col<cols; col++){
                    if(row == 0 || col == 0 || col == cols-1){
                        gameBoard[row][col] = Wall;
                    }else if(row == rows-1){
                        gameBoard[row][col] = Ground;
                    }else{
                        gameBoard[row][col] = " ";
                    }
                }
            }
        }

        void sleepForASecond(){
            this_thread::sleep_for(chrono::seconds(1));
        }

        vector<int> getBallPos(){
            return ballPos;
        }

        int getBallLife(){
            return ballLife;
        }
};