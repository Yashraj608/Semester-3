#include<iostream>
using namespace std;
int main(){
    int rows,cols;
    cout<<"Enter the number of rows: "<<endl;
    cin>>rows;
    cout<<"Enter the number of cols: "<<endl;
    cin>>cols;
    int arr[rows][cols];
    cout<<"Enter the elements of matrices: "<<endl;
    for(int i =0;i<rows;i++){
        for(int j =0;j<cols;j++){
            cin>>arr[i][j];
        }
    }

    cout<<"The 2D matrix is: "<<endl;
    for(int i =0;i<rows;i++){
        for(int j =0;j<cols;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}