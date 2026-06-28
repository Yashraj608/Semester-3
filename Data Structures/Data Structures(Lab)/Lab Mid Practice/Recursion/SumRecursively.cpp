#include<iostream>
using namespace std;

int SumRecursively(int n){
       if(n <=0){
        return 0;
       }

       return n +SumRecursively(n-1);
}
int main(){
    cout<<"Enter the number to find the sum : "<<endl;
    int n;
    cin>>n;

    int result = SumRecursively(n);
    cout<<"Sum is :"<<result<<endl;
}