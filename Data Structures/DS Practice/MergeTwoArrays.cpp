#include<iostream>
using namespace std;
void BubbleSort(int*arr,int size){
     for(int i =0;i<size-1;i++){
        for(int j =0;j<size-i-1;j++){
             if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
             }
        }
     }
}

void MergeArray(int arr1[], int arr2[], int size1, int size2,int result[]){
    int i =0;
    int j =0;
    int k=0;
    while(i<size1 && j <size2){
        if(arr1[i] < arr2[j]){
            result[k++] = arr1[i++];
        }else{
            result[k++] = arr2[j++];
        }
    }
        while(i<size1){
            result[k++] = arr1[i++];
        }

        while(j<size2){
            result[k++] = arr2[j++];
        }
}
int main(){
    int n,m;
    cout<<"Enter the number of elements of Array1: "<<endl;
    cin>>n;
    cout<<"Enter the number of elements of Array2: "<<endl;
    cin>>m;
      int *arr1 = new int[n];
      int *arr2 = new int[m];
    cout<<"Enter the elements of Array1: "<<endl;
    for(int i =0;i<n;i++){
     cin>>arr1[i];
    }

    cout<<"Enter the elements of Array2: "<<endl;
    for(int i =0;i<m;i++){
        cin>>arr2[i];
    }

     BubbleSort(arr1,n);
     cout<<"Array 1 after sorting : "<<endl;
     for(int i =0;i<n;i++){
        cout<<arr1[i]<<" ";
     }
     BubbleSort(arr2,m);
     cout<<"Array 2 after sorting is :"<<endl;
     for(int i =0;i<m;i++){
        cout<<arr2[i]<<" ";
     }


     int result = n+m;
     int* resultant = new int[result];
     MergeArray(arr1,arr2,n,m,resultant);
    cout<<"The resultant array is: "<<endl;
    for(int i=0;i<result;i++){
        cout<<resultant[i]<<" ";
    }
    return 0;
}