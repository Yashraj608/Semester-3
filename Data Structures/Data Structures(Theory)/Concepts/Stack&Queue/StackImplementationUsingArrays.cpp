#include<iostream>
using namespace std;
class Stack{
public:
int st[10];
int top;

Stack(){
    top = -1;
}

void push(int value){
    if(top >= 9){
        cout<<"Stack is full !"<<endl;
    }else{
        top = top +1;
        st[top] = value;
    }
}


void pop(){
    if(top == -1){
        cout<<"Stack is empty !"<<endl;
    }else{
        top = top -1;
    }
}

int size(){
    if(top == -1){
        cout<<"Stack is empty !"<<endl;
        return -1;
    }else{
        return top+1;
    }
}

int peek(){
    if(top== -1){
        cout<<"Stack is empty !"<<endl;
        return -1;
    }
    return st[top];
}


void print(){
    if(top == -1){
        cout<<"Stack is empty !"<<endl;
    }else{
        for(int i = top ; i >=0;i--){
            cout<<st[i]<<" ";
        }
    }
}
};

int main(){
Stack ss;
ss.push(3);
ss.push(6);
ss.push(2);
ss.push(9);
ss.print();
ss.pop();
cout<<endl;
ss.print();
cout<<endl;
cout<<"Peek Element is: "<<ss.peek()<<endl;
cout<<"Size of stack is : "<<ss.size()<<endl;
    return 0;
}