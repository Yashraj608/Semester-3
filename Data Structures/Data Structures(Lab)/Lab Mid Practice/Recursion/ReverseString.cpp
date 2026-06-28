#include<iostream>
using namespace std;

string ReverseString(string &S, int i , int j){
          if(i >= j){return S;}
        swap(S[i], S[j]);
        return ReverseString(S, i+1,j-1);
}
int main(){
    string line;
    cout<<"Enter the string to reverse"<<endl;
    getline(cin,line);
   string result=  ReverseString(line,0,line.size()-1);
    cout<<"Reversed String is: "<<result<<endl;
}