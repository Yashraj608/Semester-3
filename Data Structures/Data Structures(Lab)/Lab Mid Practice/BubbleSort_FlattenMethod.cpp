#include<iostream>
using namespace std;
void BubbleSort(int**arr, int n){
    int size = n*n;
    int *flat = new int[n];

    int k =0;
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            flat[k++] = arr[i][j];
          }
    }

    for(int i =0;i<n-1;i++){
        for(int j =0;j<n-i-1;j++){
            if(arr[j]<arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }

    k =0;
    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j] = flat[k++];
        }
    }

    delete[]flat;
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
     return 0;
    }