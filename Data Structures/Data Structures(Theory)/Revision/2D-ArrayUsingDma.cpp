#include<iostream>
using namespace std;
int main(){
    int rows,cols;
    cout<<"Enter the number of rows: "<<endl;
    cin>>rows;
    cout<<"Enter the number of cols: "<<endl;
    cin>>cols;
    int **arr = new int*[rows];
    for(int i =0;i<rows;i++){
        arr[i] = new int[cols];
    }

    cout<<"Enter the elements of array: "<<endl;
    for(int i =0;i<rows;i++){
        for(int j =0;j<cols;j++){
            cin>>arr[i][j];
        }
    }

    cout<<"Matrix is: "<<endl;
    for(int i =0;i<rows;i++){
        for(int j =0;j<cols;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

for(int i =0;i<rows;i++){
    delete[]arr[i];
}
delete[]arr;
    return 0;
}