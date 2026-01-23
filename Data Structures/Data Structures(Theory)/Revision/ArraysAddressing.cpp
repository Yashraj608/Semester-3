#include<iostream>
using namespace std;
void display(int *arr, int size){
    for(int i =0;i<size;i++){
        cout<<arr+i<<"  "<<*(arr+i)<<endl;
    }
}
int main(){
    int arr[] = {2,6,4,7,4,9};
    display(arr,6);
}