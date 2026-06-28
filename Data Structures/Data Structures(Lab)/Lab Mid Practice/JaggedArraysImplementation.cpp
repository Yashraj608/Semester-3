#include<iostream>
using namespace std;
int main(){
    int rows;
    cout<<"Enter the number of rows: "<<endl;
    cin>>rows;

    int**arr = new int*[rows];
    int*cols = new int[rows];

    for(int i =0;i<rows;i++){
        cout<<"Enter the number of cols for "<<i+1<<" row :"<<endl;
        cin>>cols[i];
        arr[i] = new int[cols[i]];
    }

 
    for(int i =0;i<rows;i++){
           cout<<"Enter the elements of " <<i+1<< " row: "<<endl;
        for(int j =0;j<cols[i];j++){
            cin>>arr[i][j];
        }
    }


    cout<<"The jagged array is: "<<endl;
    for(int i =0;i<rows;i++){
        for(int j =0;j<cols[i];j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

 for(int i =0;i<rows;i++){
    delete[]arr[i];
    
 }
 delete[]arr;
 delete[]cols;
    
    return 0;
}