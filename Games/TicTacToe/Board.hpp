#pragma once
#include<bits/stdc++.h>
using namespace std;

class Board{
    private:
        int moveCount;
        vector<vector<char>>grid;

    public:
        Board(){
            grid = vector<vector<char>>(3, vector<char>(3));
            initializeBoard();
        }


        void initializeBoard();
        bool hasWinner();
        void makeMoves(int rows, int cols, char symbol);
        bool isFull();
        void printBoard();
};