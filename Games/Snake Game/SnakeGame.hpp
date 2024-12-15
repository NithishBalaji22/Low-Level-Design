#pragma once
#include <bits/stdc++.h>
using namespace std;

class SnakeGame{
    private:
        int rows;
        int cols;
        queue<pair<int,int>> snake;
        queue<pair<int,int>> foods;
        vector<vector<string>> board;
    
    public:
        SnakeGame(int rows, int cols){
            this->rows = rows;
            this->cols = cols;
            snake = queue<pair<int,int>>();
            foods = queue<pair<int,int>>();
            board = vector<vector<string>>(rows, vector<string>(cols, " "));
            initializeBoard();
        }

        void initializeBoard(){
            // Initializing the Snake at (0,0)
            snake.push({0,0});

            //Placing Foods
            foods.push({1,0});
            foods.push({2,2});
            foods.push({3,4});
            foods.push({5,2});
            foods.push({4,5});

            //Display food
            placeFood(foods.front().first, foods.front().second);
            foods.pop();
        }

        void startGame(){
            int row = 0, col = 0;
            board[row][col] = ".";
            printBoard();

            while(true){
                char direction;
                cout<<"Enter a direction (U,D,L,R): ";
                cin>>direction;

                if(direction == 'U') moveSnake(--row, col);
                else if(direction == 'D') moveSnake(++row, col);
                else if(direction == 'R') moveSnake(row, ++col);
                else moveSnake(row, --col);            
            }
        }

        void moveSnake(int row, int col){
            if(row >= 0 && row < rows && col >= 0 && col < cols){
                snake.push({row, col});
                if(board[row][col] != "X"){
                    int r = snake.front().first;
                    int c = snake.front().second;
                    snake.pop();
                    board[r][c] = " ";
                }else if(board[row][col] == "X"){
                    if(foods.empty()){
                        cout<<"No Foods Available Game Over!"<<endl;
                        exit(0);
                    }

                    board[row][col] = " ";
                    int r = foods.front().first;
                    int c = foods.front().second;
                    foods.pop();
                    placeFood(r, c);
                }
                
                if(board[row][col] == "."){
                    cout<<"Snake Bites itself Game Over !!"<<endl;
                    exit(0);
                }

                moveForwardAndPrintBoard(row, col);
            }else{
                cout<<"Out of bound!!"<<endl;
                exit(0);
            }
        }

        void moveForwardAndPrintBoard(int row, int col){
            board[row][col] = ".";
            printBoard();
        }

        void placeFood(int row, int col){
            board[row][col] = "X";
        }

        void printBoard(){
            for(int row = 0; row < rows; row++){
                for(int col = 0; col < cols; col++){
                    cout<<board[row][col]<<" ";
                }
                cout<<endl;
            }
        }
};