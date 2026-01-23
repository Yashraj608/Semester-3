#include<iostream>
using namespace std;
class Marks{
public:
int marks[5];

Marks(){
    for(int i =0;i<5;i++){
        marks[i] = 0;
    }
}

void TakeInput(){
    cout<<"Enter the marks of student: "<<endl;
    for(int i =0;i<5;i++){
        cin>>marks[i];
    }
}


void display(){
    for(int i =0;i<5;i++){
        cout<<marks[i]<<" ";
    }
}

float average(){
    int sum= 0;
    for(int i =0;i<5;i++){
        sum = sum + marks[i];
    }
    return float(sum)/5;
}
};

int main(){

    Marks m;
    m.TakeInput();
    m.display();
    cout<<endl;
    cout<<"Average marks are: "<<m.average()<<endl;
    return 0;
}