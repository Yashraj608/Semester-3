#include<iostream>
using namespace std;
#define N 4

bool isSafe(int board[][N], int rows , int cols){
    for(int i =0;i<rows;i++){
        if(board[i][cols]==1){
            return false;
        }
    }


    for(int i = rows-1,j= cols+1; i >=0,j<N;i--,j++){
        if(board[i][j] == 1){
            return false;
        }
    }


    
    for(int i = rows-1,j= cols-1; i >=0,j>=0;i--,j--){
        if(board[i][j] == 1){
            return false;
        }
    }
    return true;
}

void SolveCameras(int board[][N], int rows){
    if(rows == N){
        for(int i =0;i<N;i++){
            for(int j =0;j<N;j++){
                if(board[i][j]== -1){
                    cout<<"X";
                }else if(board[i][j]==1){
                    cout<<"C";
                }else{
                    cout<<".";
                }
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }

    for(int cols = 0;cols<N;cols++){
         if(board[rows][cols]== -1) continue;

         if(isSafe(board,rows,cols)){
            board[rows][cols] =1;
            SolveCameras(board,rows+1);
            board[rows][cols] =0;
         }
    }
}
int main(){
int Cameras[N][N]={0};
Cameras[1][2] = -1;
SolveCameras(Cameras,0);
    return 0;
}