#include<iostream>
using namespace std;

void TowerOfHanoi(int n, char source , char destination,char auxiliary){
    if(n ==1){
        cout<<"Disk is on its place !"<<endl;
        return;
    }
    TowerOfHanoi(n-1,source, auxiliary,destination);
     cout << "Move disk " << n << " from " << source << " to " << destination << endl;
    TowerOfHanoi(n-1,auxiliary,destination,source);
}
int main(){
    int n ;
    cout<<"Enter the number of disk"<<endl;
    cin>>n;

    TowerOfHanoi(n,'A','B','C');
    return 0;
}