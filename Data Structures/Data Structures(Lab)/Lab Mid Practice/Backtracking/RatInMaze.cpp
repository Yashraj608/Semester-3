#include<iostream>
using namespace std;
#define N 4

bool isSafe(int maze[N][N], int rows,int cols){
    if(rows>=0 && rows <N && cols >=0 && cols<N && maze[rows][cols]==1){
        return true;
    }
    return false;
}

bool solveMazeUtil(int maze[N][N], int rows , int cols, int sol[N][N]){
    if(rows == N-1 && cols == N-1){
        sol[rows][cols] = 1;
        return true;
    }

    if(isSafe(maze, rows,cols)){
        sol[rows][cols] = 1;
    


    if(solveMazeUtil(maze,rows,cols+1,sol))
    return true;

    if(solveMazeUtil(maze,rows+1,cols,sol))
    return true;

    sol[rows][cols] = 0;
    return false;
    }

    return false;
}

void SolveMaze(int maze[N][N]){
       int sol[N][N] = {0};

       if(solveMazeUtil(maze,0,0,sol)){
        cout<<"Solution path: "<<endl;
        for(int i =0;i<N;i++){
            for(int j =0;j<N;j++){
                cout<<sol[i][j]<<" ";
            }
            cout<<endl;
        }
       }else{
        cout<<"No Solution Exists"<<endl;
       }
}
int main(){
    int Maze[N][N] = {
        {1,0,0,0},
        {1,1,0,1}, 
        {0,1,0,0}, 
        {1,1,1,1},
    };

    SolveMaze(Maze);
    return 0;
}