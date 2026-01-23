#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>v;
    v.push_back(3);
    v.push_back(4);
    v.push_back(12);

    cout<<"Size: "<<v.size()<<endl;
    cout<<"Capacity: "<<v.capacity()<<endl;
    cout<<"Element at index 0: "<<v[0]<<endl;
    cout<<"Last Element: "<<v.back()<<endl;
    cout<<"First Element: "<<v.front()<<endl;

    for(auto v:v){
cout<<v<<endl;
    }

    v.pop_back();
    cout<<"Size After pushing back the element: "<<v.size()<<endl;

    return 0;
}