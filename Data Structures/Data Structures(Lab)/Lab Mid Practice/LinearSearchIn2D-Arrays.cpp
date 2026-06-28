#include<iostream>
using namespace std;

pair<int,int> LinearSearch(int**arr ,int n ,int target ){
         for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                if(arr[i][j]==target){
                    return {i,j};
                }
            }
         }
         return {-1,-1};
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


    int target;
    cout<<"Enter the target: "<<endl;
    cin>>target;

     pair<int,int>result = LinearSearch(arr,n,target);

     if(result.first != -1){
        cout<<"Target found at: "<<result.first<<","<<result.second<<endl;
     }else{
        cout<<"Target Not Found !"<<endl;
     }
    return 0;
}