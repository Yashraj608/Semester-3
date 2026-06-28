#include<iostream>
using namespace std;
int*mergeSortedArrays(int *arr1, int*arr2, int n , int n1){
     int*merged = new int[n +n1];
     int i=0,j=0,k=0;
     while(i<=n && j <=n1){
        if(arr1[i]<=arr2[j]){
            merged[k++] = arr1[i++];
        }else{
            merged[k++] = arr2[j++];
        }
     }

     while(i <n){
        merged[k++] = arr1[i++];
     }

     while(j <n1){
        merged[k++] = arr2[j++];
     }

     return merged;

}
int main(){
    int arr1[] = {2,3,4,6};
    int arr2[] ={1,7,11,15,20};
    int n = 4;
    int n1 = 5;
    int *merged = mergeSortedArrays(arr1,arr2,n,n1);
    for(int i =0;i<n+n1;i++){
        cout<<merged[i]<<" ";
    }
    return 0;
}