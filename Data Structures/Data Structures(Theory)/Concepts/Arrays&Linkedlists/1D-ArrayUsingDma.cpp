#include<iostream>
using namespace std;
int main(){
int size;
cout<<"Enter the size of array: "<<endl;
cin>>size;

int *arr = new int[size];
cout<<"Enter the elements of array: "<<endl;
for(int i =0;i<size;i++){
    cin>>arr[i];
}

cout<<"The elements of array are: "<<endl;
for(int i =0;i<size;i++){
    cout<<arr[i]<<" ";
}

for(int i =0;i<size;i++){   //releasing the occupied memory//
    delete[]arr;
}
cout<<endl;
cout<<"The elements of array are: "<<endl;   //After releasing the memory this will give the garbage values//
for(int i =0;i<size;i++){
    cout<<arr[i]<<" ";
}
    return 0;

}