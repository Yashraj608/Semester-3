#include<iostream>
using namespace std;
#define n 6

bool isSafe(int maze[n][n], int rows , int col){
    if(rows >= 0 && rows < n && col >= 0 && col < n && maze[rows][col] == 1){
        return true;
    }
    return false;
}

bool SolveMazeUtil(int maze[n][n], int rows , int cols, int sol[n][n]){
    if(rows == n-1 && cols == n-1 && maze[rows][cols] == 1){
        sol[rows][cols] = 1;   // ✅ mark destination
        return true;
    }

    if(isSafe(maze, rows, cols)){
        sol[rows][cols] = 1;   // ✅ mark current cell

        if(SolveMazeUtil(maze, rows+1, cols, sol)) return true;  // move down
        if(SolveMazeUtil(maze, rows, cols+1, sol)) return true;  // move right

        sol[rows][cols] = 0;   // backtrack
        return false;
    }

    return false;
}

void SolveMaze(int maze[n][n]){
    int sol[n][n] = {0};

    if(SolveMazeUtil(maze, 0, 0, sol)){
        cout << "Solution exists:" << endl;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << sol[i][j] << " ";
            }
            cout << endl;
        }
    }
    else {
        cout << "No Safe Path Found" << endl;
    }
}

int main(){
    int maze[n][n] = {
        {1,0,1,1,1,1},
        {1,-1,1,0,1,0},
        {1,1,1,1,-1,1},
        {0,1,0,1,1,1},
        {1,1,1,-1,0,1},
        {1,0,1,1,1,1}
    };

    SolveMaze(maze);
    return 0;
}
