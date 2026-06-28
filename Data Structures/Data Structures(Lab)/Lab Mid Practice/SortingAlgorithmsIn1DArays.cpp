#include<iostream>
using namespace std;

void bubbleSort(int *arr , int n ){
    for(int i =0;i<n-1;i++){
        for(int j =0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        } 
    }
}


void SelectionSort(int *arr, int n ){
    for(int i =1;i<n-1;i++){
        int minIndex =i;
        for(int j =i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i],arr[minIndex]);
    }
}

void InsertionSort(int arr[], int n){
    for(int i =1;i<n;i++){
        int key = arr[i];
         int j = i-1;
         while(j <=0  && key <arr[j]){
         
           arr[j+1] = arr[j];
           j--;
        } 
     arr[j+1] = key;  
    }
}


void CombSort(int arr[], int size){
   int gap = size;
   const float shrink = 1.3;
   bool swapped = true;

   while(gap != 1 || swapped){
     gap = int(gap/shrink);
     if(gap <1){
        gap = 1;
     }

     swapped = false;
     for(int i=0;i+gap <size;i++){
        if(arr[i]>arr[i+gap]){
            swap(arr[i],arr[i+gap]);
            swapped = true;
        }
     }
   }
}
void Display(int arr[], int n){
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int n;
    cout<<"Enter the size of array: "<<endl;
    cin>>n;

    int *arr = new int[n];
    cout<<"Enter the elements of array: "<<endl;
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

  

    bubbleSort(arr, n );
    cout<<"Agter bubble Sort: "<<endl;
    Display(arr,n);
    cout<<endl;
    SelectionSort(arr, n);
    cout<<"After Selection Sort : "<<endl;
    Display(arr,n);
cout<<endl;
    InsertionSort(arr,n);
    cout<<"After InsertionSort: "<<endl;
    Display(arr,n);

    cout<<endl;
    CombSort(arr,n);
    cout<<"After comb Sort: "<<endl;
    Display(arr,n);


}