#include<iostream>
using namespace std;
int main(){
    cout<<"Enter the size of Array: "<<endl;
    int size;
    cin>>size;
    int *arr = new int[size];

    cout<<"Enter the elements of Array: "<<endl;
    for(int i =0;i<size;i++){
        cin>>arr[i];
    }

    cout<<"Elements of Array are: "<<endl;
    for(int i =0;i<size;i++){
        cout<<arr[i]<<" ";
    }

    delete[]arr;
    return 0;
}