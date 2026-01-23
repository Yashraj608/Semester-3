#include<iostream>
using namespace std;
class Matrix{
public:
int matrix[3][3];
Matrix(){
    for(int i =0;i<3;i++){
      for(int j =0;j<3;j++){
        matrix[i][j]= 0;
      }
    }
}


void TakeInput(){
    cout<<"Enter the elements of the matrices: "<<endl;
    for(int i =0;i<3;i++){
        for(int j =0;j<3;j++){
            cin>>matrix[i][j];
        }
    }
}


void display(){
    cout<<"Matrix is: "<<endl;
    for(int i =0;i<3;i++){
        for(int j =0;j<3;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

void  Rowsum(){
    for(int i = 0;i<3;i++){
       int rowsum = 0;
       for(int j =0;j<3;j++){
        rowsum += matrix[i][j];
       }
       cout<<"Sum of : "<<i+1<<" Row is: "<<rowsum<<endl;
    }
}

void colsSum(){
    for(int j =0;j<3;j++){
        int colsSum = 0;
        for(int i = 0;i<3;i++){
            colsSum += matrix[i][j];
        }
        cout<<"Sum of "<<j+1<<" cols: "<<colsSum<<endl;
    }
}
};
int main(){
    Matrix m;
    m.TakeInput();
    m.display();
   m.Rowsum();
   m.colsSum();
    return 0;
}