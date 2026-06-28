#include<iostream>
using namespace std;
#define n 4

bool isSafe(int board[],int row, int cols){
    for(int i =0;i<row;i++){
     if(board[i]==cols || abs(board[i]-cols)==row-i)
        return false;
    }
    return true;
}

void solveNQueens(int board[], int row){
    if(row==n){

        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                if(board[i]==j){
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
        for(int col= 0;col<n;col++){
            if(isSafe(board,row,col)){
                board[row] = col;
                solveNQueens(board,row+1);
            }
        }
    }


int main(){

    int board[n];
    solveNQueens(board,0);
  return 0;  
}
