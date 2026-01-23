#include<iostream>
using namespace std;

void Merge(int arr[], int start , int mid , int end){
    int n1 = mid -start +1;
    int n2 = end - mid;

    int *L = new int[n1];
    int *R = new int[n2];

    for(int i =0;i<n1;i++){
        L[i] = arr[start +i];
    }

    for(int j =0;j<n2;j++){
        R[j] = arr[mid +1 +j];
    }


    int i =0;
    int j =0;
    int k= start;
    while(i <n1 && j <n2){
    if(L[i]<=R[j]){
        arr[k++] = L[i++];
    }else{
        arr[k++] = R[j++];
    }
}



while(i <n1){
    arr[k++] =L[i++];
}

while(j <n2){
    arr[k++] = R[j++];
}


delete[]L;
delete[]R;
}

void MergeSort(int arr[], int start , int end){
    if(start < end){
    int mid = start + (end - start )/2;

    MergeSort(arr,start,mid);
    MergeSort(arr,mid+1,end);

    Merge(arr,start,mid,end);
    }
}
int main(){
    int n ;
    cout<<"Enter the size of array:"<<endl;
    cin>>n;
    int *arr = new int[n];
    
    cout<<"Enter the elements of array: "<<endl;
    for(int i =0;i<n ;i++){
        cin>>arr[i];
    }


    cout<<"The elements of array are: "<<endl;
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    MergeSort(arr,0,n-1);
cout<<endl;
    cout<<"After merging : "<<endl;
    for(int i =0;i <n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}