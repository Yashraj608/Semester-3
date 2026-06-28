#include<iostream>
using namespace std;
//Row Wise Sorting//
void BubbleSort(int **arr , int n ){
    for(int i =0;i<n;i++){
        for(int pass =0;pass<n-1;pass++){
            for(int j =0;j<n-pass-1;j++){
                if(arr[i][j]>arr[i][j+1]){
                    swap(arr[i][j],arr[i][j+1]);
                }
            }
        }
    }
}
int main(){
      int n; 
     cout<<"Enter the size of 2D-Array: "<<endl;
     cin>>n;

     int **arr = new int*[n];
     for(int i =0;i<n;i++){
        arr[i] = new int[n];
     }

     cout<<"Enter the elements of 2D-Array: "<<endl;
     for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            cin>>arr[i][j];
        }
     }


     cout<<"The 2D-Matrix is: "<<endl;
     for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
     }
     
     BubbleSort(arr,n);
cout<<"After Sorting: "<<endl;
      for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
     }
     
}