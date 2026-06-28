#include<iostream>
using namespace std;

void BubbleSort(int arr[],int n ){
    for(int i =0;i<n-1;i++){
        for(int j =0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
int*mergedArray(int arr1[], int arr2[], int n , int n1 ){
    int *merged = new int[n+n1];
    for(int i =0;i<n;i++){
        merged[i] = arr1[i];
    }
    for(int i =0;i<n1;i++){
        merged[n +i] = arr2[i];
    }

    return merged;
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
    
    int *merged = mergedArray(arr1,arr2,n,n1);

    cout<<"Merged Array is: "<<endl;
    for(int i =0;i<n+n1;i++){
        cout<<merged[i]<<" ";
    }

    int size = n+n1;
     BubbleSort(merged,size);

     cout<<"Merge Array after Sorting: "<<endl;
     for(int i =0;i<size;i++){
        cout<<merged[i]<<" ";
     }
    return 0;
}