#include<iostream>
using namespace std;

bool LinearSearch(int arr[], int size, int target){
    for(int i =0;i<size;i++){
        if(arr[i]==target){
            return true;
        }
    }
    return false;
}

bool BinarySearch(int arr[], int n , int target){
    int start = 0;
    int end = n-1;
    while(start <= end){
        int mid = start +(end - start)/2;
        if(arr[mid] == target){
            return true;
        }

        if(arr[mid]<target){
            start = mid +1;
        }else{
            end = mid -1;
        }
    }
    return false;
}

bool InterpolationSearch(int arr[], int n ,int key){
  int low = 0;
  int high = n-1;
  while(low <= high && key >= arr[low]&& key <= arr[high]){
    if(low==high){
        if(arr[low]==key){
              return true;
        }
    }

    int pos = low + ((key - arr[low])*(high - low)) / (arr[high]-arr[low]);

    if(arr[pos]==key){
        return true;
    }

    if(arr[pos]<key){
        low = pos+1;
    }else{
        high = pos-1;
    }
    
  }
  return false;
}

int main(){
    int n ;
    cout<<"Enter the size of arrays: "<<endl;
    cin>>n;
    int  *arr = new int[n];
    cout<<"Enter the elements of arrays: "<<endl;
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"The Elements of array are: "<<endl;
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }


    int target;
    cout<<"Enter the target: "<<endl;
    cin>>target;

    bool result  = LinearSearch(arr,n,target);
    if(result){
        cout<<"Taregt found !"<<endl;
    } else{
        cout<<"Target Not Found !"<<endl;
    }


    bool result1 = BinarySearch(arr, n , target);
     if(result1){
        cout<<"Taregt found !"<<endl;
    } else{
        cout<<"Target Not Found !"<<endl;
    }

    bool result2 = InterpolationSearch(arr, n , target);
     if(result2){
        cout<<"Taregt found !"<<endl;
    } else{
        cout<<"Target Not Found !"<<endl;
    }
    return 0;
}