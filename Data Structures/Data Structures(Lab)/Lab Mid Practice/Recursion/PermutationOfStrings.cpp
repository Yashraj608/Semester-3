#include<iostream>
using namespace std;
void permute(string &s,int l , int r){
    if(l==r){
        cout<<s<<" ";
        return;
    }

    for(int i =1;i<=r;i++){
        swap(s[l],s[i]);
        permute(s,l+1,r);
        swap(s[l],s[i]);
    }
}

int main(){
int n ;
cout<<"Enter the number between 1 and 26"<<endl;
cin>>n;

if(n <1 ||n>26){
cout<<"Invalid Input"<<endl;
}

string letters = "";
for(int i =0;i<n;i++){
    letters += char('a'+i);
}

permute(letters,0,n-1);

    return 0;
}