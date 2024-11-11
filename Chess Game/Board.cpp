#include "Board.hpp"
#include "Piece.hpp"

Board::Board(int row, int col){
    this->row = row;
    this->col = col;
    board = vector<vector<Piece *>>(col, vector<Piece *>(row));
    intializeBoard();
}

void Board::intializeBoard(){

    board[0][0] = new Rook('R', Colour::WHITE, 0, 0);
    board[0][1] = new Knight('K', Colour::WHITE, 0, 1);
    board[0][2] = new Bisop('B', Colour::WHITE, 0, 2);
    board[0][3] = new Queen('Q', Colour::WHITE, 0, 3);
    board[0][4] = new King('K', Colour::WHITE, 0, 4);
    board[0][5] = new Bisop('B', Colour::WHITE, 0, 2);
    board[0][6] = new Knight('K', Colour::WHITE, 0, 1);
    board[0][7] = new Rook('R', Colour::WHITE, 0, 0);

    for (int i = 0; i < 8; i++){
        board[1][i] = new Pawn('P', Colour::WHITE, 1, i);
    }

    board[7][0] = new Rook('R', Colour::BLACK, 7, 0);
    board[7][1] = new Knight('K', Colour::BLACK, 7, 1);
    board[7][2] = new Bisop('B', Colour::BLACK, 7, 2);
    board[7][3] = new Queen('Q', Colour::BLACK, 7, 3);
    board[7][4] = new King('K', Colour::BLACK, 7, 4);
    board[7][5] = new Bisop('B', Colour::BLACK, 7, 2);
    board[7][6] = new Knight('K', Colour::BLACK, 7, 1);
    board[7][7] = new Rook('R', Colour::BLACK, 7, 0);

    for (int i = 0; i < 8; i++){
        board[6][i] = new Pawn('P', Colour::BLACK, 1, i);
    }
}

Piece* Board::getPiece(int row, int col){
    return board[row][col];
}

void Board::setPiece(Piece *piece, int row, int col){
    board[row][col] = piece;
}

bool Board::isValidMove(Piece *piece, int destRow, int destCol){
    if (destRow < 0 || destRow > 7 || destCol < 0 || destCol > 7)
        return false;

    Piece* destPiece = board[destRow][destCol];
    return (destPiece == nullptr || destPiece->getColour() != piece->getColour() && piece->canMove(this, destRow, destCol));
}

bool Board::checkMate(){
    // Need to implement
    return false;
}

void Board::printBoard(){
    cout<<"  0 1 2 3 4 5 6 7"<<endl;
    for (int i = 0; i < row; i++){
        cout<<i<<" ";
        for (int j = 0; j < col; j++){
            Piece* piece = board[i][j];
            if (piece == nullptr)
                cout<<" ";
            else
                cout<<piece->getPieceName()<<" ";
        }
        cout<<endl;
    }
}