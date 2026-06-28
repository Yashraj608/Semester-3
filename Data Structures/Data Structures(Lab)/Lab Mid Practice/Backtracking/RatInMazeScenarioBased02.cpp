#include<iostream>
using namespace std;
#define n 6

bool isSafe(int maze[n][n],int rows , int cols){
    return(rows>=0&&rows<n&&cols>=0&&cols<n&&maze[rows][cols]==1);
}

void printSolution(int sol[n][n]){
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            cout<<sol[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool SolveMazeUtil(int maze[n][n], int rows, int cols, int sol[n][n],int &count){
    if(rows == n-1 && cols ==n-1 && maze[rows][cols]==1){
        sol[rows][cols] =1;
        count++;
        printSolution(sol);
        sol[rows][cols] = 0;
        return true;
    }

    if(isSafe(maze,rows,cols)){
        sol[rows][cols] =1;


        SolveMazeUtil(maze,rows+1,cols,sol,count);

        SolveMazeUtil(maze,rows,cols+1,sol,count);

        sol[rows][cols] = 0;

        return false;
    }


return false;

}

void SolveMaze(int maze[n][n]){
    int solution[n][n] ={0};

    int count=0;
    cout<<"All possible paths: "<<endl;
    SolveMazeUtil(maze,0,0,solution,count);
       if(count ==0){
        cout<<"No path exists !"<<endl;
       }else{
        cout<<"Total possible paths are: "<<count<<endl;
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