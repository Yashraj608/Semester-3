#include<iostream>
using namespace std;
void printRecursively(int n){
    if(n <0){
        return;
    }
    cout<<n<<endl;
    printRecursively(n-1);
}
int main(){
    int n ;
    cout<<"Enter the number to print the series"<<endl;
    cin>>n;
cout<<"The series is: "<<endl;
    printRecursively(n);
}