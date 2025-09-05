#include<iostream>
#include<cstring>
using namespace std;
class student{
public:
char*name;
int age;

student(){
    cout<<"Constructor called !"<<endl;
}
student(const char*n,int age){
     name = new char[strlen(n)+1];
     strcpy(name,n);
    this->age = age;
}

student(const student& other){
    this->age = other.age;
    name = new char[strlen(other.name)+1];
    strcpy(name,other.name);
}

student& operator = (const student &other){
    if(this != &other){
        delete[]name;
        name = new char[strlen(other.name)+1];
        strcpy(name,other.name);

        age = other.age;
    }
    return*this;
}

~student(){
    delete[]name;
}



void display(){
    cout<<"Name: "<<name<<endl;
    cout<<"Age: "<<age<<endl;
}
};
int main(){
    student s("yash raj",20);
    student s1;
    s1 = s;
    s.display();
    s1.display();
    cout<<"s address is : "<<&s<<endl;
    cout<<"S1 address is : "<<&s1<<endl;
    return 0;
}