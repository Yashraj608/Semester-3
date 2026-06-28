#include<iostream>
using namespace std;
void MergeArrays(int arr1[], int arr2[], int n , int n1,int merged[]){
    for(int i =0;i<n;i++){
        merged[i] = arr1[i];
    }

    for(int j =0;j<n1;j++){
        merged[n+j] =arr2[j];
    }
}
int main(){
    int n,n1;
    cout<<"Enter the size of array1: "<<endl;
    cin>>n;
    int *arr1 = new int[n];
    cout<<"Enter the elements of array 1: "<<endl;
    for(int i =0;i<n;i++){
         cin>>arr1[i];
    }
    cout<<"Enter the size of array2:"<<endl;
    cin>>n1;
    int*arr2 = new int[n1];
      for(int i =0;i<n1;i++){
         cin>>arr2[i];
    }
    
    int merged[n+n1];
    MergeArrays(arr1,arr2,n,n1,merged);

    cout<<"Merged Array is: "<<endl;
    for(int i =0;i<n+n1;i++){
        cout<<merged[i]<<" ";
    }
}