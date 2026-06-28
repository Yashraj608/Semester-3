#include<iostream>
using namespace std;

string checkPalindrome(string &s, int i , int j){
    if(i>=j){
        return s;
    }

    if(s[i] != s[j]){
        return "Not a palindrome";
    }
   return checkPalindrome(s,i+1,j-1);
     
}

int main(){
string line;
cout<<"Enter the string to check the palindrome"<<endl;
getline(cin,line);

string result = checkPalindrome(line, 0,line.size()-1);
cout<<result<<endl;
    return 0;
}