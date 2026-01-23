#include<iostream>
using namespace std;
class student{
private:
string name;
int age;
public:
void setdata(int age, string name){
    this->age = age;
    this->name = name;
}
void display(){
    cout<<"Name: "<<name<<endl;
    cout<<"age: "<<age<<endl;
}
};

int main(){
 student s[3];
 s[0].setdata(22,"Yash Raj");
 s[1].setdata(12,"Akash Raj");
 s[2].setdata(13,"Akshay");

 for(int i=0;i<3;i++){
    s[i].display();
 }
    return 0;
}