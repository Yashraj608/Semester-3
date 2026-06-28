#include<iostream>
using namespace std;

int N_factorial(int n ){
    if(n ==0 || n==1 ){
        return 1;
    }

    return n *N_factorial(n-1);
}
int main(){
    int n;
    cout<<"Enter the number to find the factorial !"<<endl;
    cin>>n;
   int result =  N_factorial(n);
   cout<<"Factorial of "<<n<<" is: "<<result<<endl;

    return 0;
}