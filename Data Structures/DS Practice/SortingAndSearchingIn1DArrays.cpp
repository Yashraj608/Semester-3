#include<iostream>
using namespace std;
int InterpolationSearch(int *arr, int size, int target){
    int low = 0;
    int high = size-1;
    while(low <= high && arr[low]<=target && arr[high]>=target){
        int pos = low + ((target - arr[low])*(high - low))/ (arr[high]-arr[low]);

        if(pos==0){
            return pos;
        }else if(arr[pos] < target){
           low = pos +1;
        }else{
            high = pos-1;
        }
    }
}
bool BinarySearch(int *arr, int size,int key){
    int start = 0;
    int end = size-1;
    while(start <= end){
        int mid = start + (end -start)/2;
        if(arr[mid]==key){
            return true;
        }else if(arr[mid] >key){
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    return false;
}
bool LinearSearch(int *arr, int size, int target){
    for(int i =0;i<size;i++){
        if(arr[i]==target){
            return true;
        }
    }
    return false;
}
void BubbleSort(int *arr, int size){
    int  n =size;
       for(int i =0;i<n-1;i++){
        for(int j =0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
       }
}

void SelectionSort(int *arr, int size){
    int n = size;
    for(int i =0;i<n-1;i++){
       int minIndex = i;
        for(int j =i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }
        if(minIndex != i){
            swap(arr[i],arr[minIndex]);
        }
    }
}

void InsertionSort(int*arr, int size ){
  int n = size;
  for(int i =0;i<n;i++){
    int key = arr[i];
    int j = i-1;
    while(j>=0 && arr[j]>key){
        arr[j+1] = arr[j];
        j--;
    }
     arr[j+1] = key;
  }
}

void CombSort(int *arr, int size){
    int gap  = size;
    const double shrink = 1.3;
    bool swapped = true;
    while(gap >1 ||swapped){
        gap = int(gap/shrink);
        if(gap<1){
            gap = 1;
        }
        swapped = false;

        for(int i =0;i+gap <size;i++){
            if(arr[i]>arr[i+gap]){
                swap(arr[i],arr[i+gap]);
                swapped = true;
            }
        }
    }
}
int main(){
    int n;
    cout<<"Enter the size of Array: "<<endl;
    cin>>n;
    int*arr = new int[n];
    cout<<"Enter the elements of array: "<<endl;
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"The Elements of Array are: "<<endl;
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
  

    CombSort(arr,n);
    // InsertionSort(arr,n);
    // SelectionSort(arr,n);
    // BubbleSort(arr,n);
    cout<<endl;
    cout<<"After Sorting: "<<endl;
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }


    int target;
    cout<<"Enter the target: "<<endl;
    cin>>target;
    
    int foundByLinearSearch = InterpolationSearch(arr,n,target);
    if(foundByLinearSearch){
        cout<<"Target found ! "<<endl;
    }else{
        cout<<"Not Found !"<<endl;
    }



    return 0;
}