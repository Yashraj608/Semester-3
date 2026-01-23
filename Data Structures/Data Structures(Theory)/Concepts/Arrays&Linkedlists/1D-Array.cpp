#include<iostream>
using namespace std;
int main(){
    int size ;
    cout<<"Enter the size of array: "<<endl;
    cin>>size;
    int arr[size];
    cout<<"Enter the elements of an array: "<<endl;
    for(int i =0;i<size;i++){
        cin>>arr[i];
    }

    cout<<"The elements of an array are: "<<endl;
    for(int i =0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    
    
    return 0; 
}