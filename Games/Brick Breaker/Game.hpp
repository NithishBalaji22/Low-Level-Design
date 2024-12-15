#pragma once
#include <bits/stdc++.h>
#include <thread>
using namespace std;

class BrickBreaker{
    private:
        int rows;
        int cols;
        int ballLife = 5;
        string wall = "W";
        string ground = "G";
        string ball = "O";
        string brick = "1";
        vector<vector<string>> brickBoard;
        unordered_map<int, int> brickLife;
        vector<int> ballPos;
    
    public:
        BrickBreaker(int rows, int cols){
            this->rows = rows;
            this->cols = cols;
            brickLife = unordered_map<int, int>();
            brickBoard = vector<vector<string>>(rows, vector<string>(cols, ""));
            intializeBoard();
            initializeBrick();
            brickBoard[rows-1][(cols/2)] = ball;
            ballPos = {rows-1, cols/2};            
        }

        void intializeBoard(){
            for(int row= 0; row < rows; row++){
                for(int col= 0; col < cols; col++){
                    if(row == 0 || col == 0 || col == cols-1){
                        brickBoard[row][col] = wall;
                    }else if(row == rows-1){
                        brickBoard[row][col] = ground;
                    }else{
                        brickBoard[row][col] = " ";
                    }
                }
            }
        }

        void initializeBrick(){
            placeBrick(2,2,2);
            placeBrick(2,3,2);
            placeBrick(2,4,2);
            placeBrick(3,2,2);
            placeBrick(3,3,2);
            placeBrick(3,4,2);
        }

        void placeBrick(int brickRow, int brickCol, int life){
            brickBoard[brickRow][brickCol] = brick;
            int brickPos = getBrickExactPosition(brickRow, brickCol);
            brickLife[brickPos] = life;
        }

        void initialBall(int ballRow, int ballCol, int rowDirection, int colDirection){
            moveDirection(ballRow, ballCol, rowDirection, colDirection);
            if(brickBoard[ballRow][ballCol] != ball){
                brickBoard[ballRow][ballCol] = ground;
            }
        }

        void moveDirection(int ballRow, int ballCol, int rowDirection, int colDirection){
            while(brickBoard[ballRow][ballCol] != wall){
                if(brickBoard[ballRow][ballCol] == brick){
                    movingDownSide(ballRow, ballCol);
                    return;
                }

                movingIllusion(ballRow,ballCol);
                ballRow += rowDirection;
                ballCol += colDirection;
            }

            wallHit(ballRow, ballCol);
            rowDirection = 0;
            colDirection *= -1;

            if(colDirection == 0){
                movingDownSide(ballRow+1, ballCol);
            }else{
                moveDirection(ballRow, ballCol + colDirection, rowDirection, colDirection);
            }
        }

        void movingDownSide(int row, int col){
            while(row != brickBoard.size()){
                movingIllusion(row, col);
                row++;        
            }
            ballPos[0] = row-1;
            ballPos[1] = col;
            brickBoard[ballPos[0]][ballPos[1]] = ball;
        }

        void movingIllusion(int row, int col){
            if(brickBoard[row][col] != brick){
                brickBoard[row][col] = ball;
                printBoard();
                brickBoard[row][col] = " ";
                sleepForASec();
            }else{
                reduceBrickAndBallLife(row, col);
            }
        }

        void wallHit(int row, int col){
            brickBoard[row][col] = ball;
            printBoard();
            sleepForASec();
            brickBoard[row][col] = wall;
        }

        void reduceBrickAndBallLife(int row, int col){
            int brickPosition = getBrickExactPosition(row, col);
            ballLife--;
            if(ballLife > 0){
                brickLife[brickPosition] -= 1;
                if(brickLife[brickPosition] == 0){
                    brickBoard[row][col] = " ";
                }
            }            
        }

        int getBrickExactPosition(int row, int col){
            return (row * brickBoard[0].size()) + col + 1;
        }

        void sleepForASec(){
            this_thread::sleep_for(chrono::seconds(1));
        }

        vector<int> getBallPos(){
            return ballPos;
        }

        int getBallLife(){
            return ballLife;
        }

        void printBoard(){
            for(int row= 0; row < rows; row++){
                for(int col= 0; col < cols; col++){
                    cout<<brickBoard[row][col]<<" ";
                }
                cout<<endl;
            }
        }
};