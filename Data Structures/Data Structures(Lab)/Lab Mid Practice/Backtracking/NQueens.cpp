#include<iostream>
using namespace std;
#define N 6

bool isSafe(int board[][N], int rows, int cols){
      //Horizontal Check//
    for(int i =0;i<rows;i++){
        if(board[i][cols]==1){
            return false;
        }
    }

//upper left//
    for(int i =rows-1, j = cols-1; i >=0 &&j>=0 ; i--,j--){
             if(board[i][j]==1){
                return false;
             }
    }

//upper right//
for(int i =rows-1,j = cols+1;i>=0 && j <N;i--,j++){
    if(board[i][j]==1){
        return false;
    }
}

return true;
}

void solveNQueens(int board[][N], int row){
    if(row == N){
        for(int i =0;i<N;i++){
            for(int j =0;j<N;j++){
                if(board[i][j]==1){
                    cout<<"Q";
                }else{
                    cout<<".";
                }
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }

    for(int col =0;col<N;col++){
        if(isSafe(board,row,col)){
            board[row][col] =1;
            solveNQueens(board,row+1);
            board[row][col] =0;
        }
    }
}
int main(){
    int board[N][N];
    solveNQueens(board,0);
}