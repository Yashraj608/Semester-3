#include<iostream>
using namespace std;
pair<int, int> InterpolationSearch(int **arr, int n , int target){
    int low = 0;
    int high = n*n-1;
    while(low <= high){
        int lowRow = low/n;
        int lowCol = low %n;
        int highRow = high/n;
        int highCol = high%n;

        int pos = low + ((target -arr[lowRow][lowCol])*(high - low))/(arr[highRow][highCol]-arr[lowRow][lowCol]);

        int row = pos/n;
        int col = pos%n;
        if(arr[row][col]==target){
            return {row,col};
        }else if(arr[row][col]<target){
            low = pos+1;
        }else{
            high = pos-1;
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

     pair<int,int>result = InterpolationSearch(arr,n,target);

     if(result.first != -1){
        cout<<"Target found at: "<<result.first<<","<<result.second<<endl;
     }else{
        cout<<"Target Not Found !"<<endl;
     }
    return 0;
}