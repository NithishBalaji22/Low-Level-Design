#include <bits/stdc++.h>
using namespace std;

class SnakeGame{
    private:
        int rows;
        int cols;
        queue<pair<int,int>> snake; // Row Col
        queue<pair<int,int>> foods; // Row Col
        vector<vector<string>> snakeBoard;

    public:
        SnakeGame(int rows, int cols){
            this->rows = rows;
            this->cols = cols;
            snakeBoard = vector<vector<string>>(rows, vector<string>(cols, " "));
            snake = queue<pair<int,int>>();
            foods = queue<pair<int,int>>();
            snake.push({0,0});

            //Position of foods to display
            foods.push({1,0});
            foods.push({2,2});
            foods.push({3,4});
            foods.push({5,2});
            foods.push({4,5});
            displayFood(foods.front().first, foods.front().second);
            foods.pop();
        }

        void intializeSnake(){
            int row = 0, col = 0;
            snakeBoard[row][col] = ".";
            printBoard();
            while(true){
                char direction;
                cout<<"Enter the direction (U, D, R, L): ";
                cin>>direction;

                if(direction == 'U') snakeMove(--row, col);
                else if(direction == 'D') snakeMove(++row, col);
                else if (direction == 'R') snakeMove(row, ++col);
                else if(direction == 'L') snakeMove(row, --col);
                else cout<<"Wrong Direction!!!"<<endl;
            }
        }

        void snakeMove(int row, int col){
            if(row >= 0 && row < rows && col >= 0 && col < cols){
                snake.push({row, col});

                if(snakeBoard[row][col] != "X"){
                    int r = snake.front().first;
                    int c = snake.front().second;
                    snake.pop(); // Popping the tail
                    snakeBoard[r][c] = " ";
                }else if(snakeBoard[row][col] == "X"){
                    if(foods.empty()){
                        moveForwardAndPrint(row, col);
                        cout<<"Game Over !!" << endl;
                        exit(0);
                    }
                    int r = foods.front().first;
                    int c = foods.front().second;
                    foods.pop();
                    displayFood(r, c);
                }else{  
                    cout<<"Snake has bite itself so Game Over !!!"<<endl;
                    exit(0);                                      
                }

                moveForwardAndPrint(row, col);
            }else{
                cout<<"Invalid Choice"<<endl;
                return;
            }
        }

        void moveForwardAndPrint(int row, int col){
            snakeBoard[row][col] = ".";
            printBoard();
        }

        void displayFood(int row, int col){
            snakeBoard[row][col] = "X";
        }

        void printBoard(){
            int rows = snakeBoard.size();
            int cols = snakeBoard[0].size();

            for(int i=0; i<rows; i++){
                for(int j=0; j<cols; j++){
                    cout<<snakeBoard[i][j]<<" ";
                }
                cout<<endl;
            }
        }
};