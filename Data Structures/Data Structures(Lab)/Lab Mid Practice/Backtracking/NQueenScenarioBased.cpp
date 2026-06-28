#include<iostream>
using namespace std;
#define N 4

bool isSafe(int board[][N], int rows , int cols){
    //Horizontal check
    for(int i =0;i<rows;i++){
        if(board[i][cols]==1){
        return false;
    }
    }


    //upper left check//
    for(int i = rows-1,j = cols-1;i>=0 && j >=0 ; i--,j--){
        if(board[i][j]==1){
            return false;
        }
    }
//upper right check
    for(int i = rows-1,j = cols+1;i>=0 && j <N;i--,j++){
        if(board[i][j]==1){
            return false;
        }
    }

    return true;
}


void SolveOffice(int office[][N], int rows){
    if (rows == N){
        for(int i =0;i<N;i++){
            for(int j =0;j<N;j++){
                 if(office[i][j]==1){
                    cout<<"M";
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
        if(isSafe(office, rows,cols)){
            office[rows][cols]=1;
            SolveOffice(office,rows+1);
            office[rows][cols] =0;
        }
    }
}
int main(){
    int office[N][N];
    SolveOffice(office, 0);
    return 0;
}