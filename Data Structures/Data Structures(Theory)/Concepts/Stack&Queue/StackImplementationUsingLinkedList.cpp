#include<iostream>
using namespace std;
class StackNode{
public:
int data;
StackNode*next;
StackNode(int value){
    this->data = value;
    next = nullptr;
}
};

class StackImp{
public:
StackNode*top;
int count=0;
StackImp(){
    top = nullptr;
} 


void push(int value){
    StackNode*newNode = new StackNode(value);
    newNode->next = top;
    top = newNode;
    count++;
}


void pop(){
    if(top == nullptr){
        delete top;
        return;
    }else{
        StackNode*temp = top;
        top = top->next;
        delete temp;
        count--;
    }
}



int peek(){
    if(top==nullptr){
        cout<<"No element exists as Stack is empty !"<<endl;
        return -1;
    }else{
        return top->data;
    }
}


void print(){
    if(top == nullptr){
        cout<<"Stack is empty !"<<endl;
    }else{
       StackNode*temp = top;
       while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
       } 
       cout<<endl;
    }
}


int getCount(){
    return count;
}
};
int main(){
StackImp s;
s.push(7);
s.push(5);
s.push(10);
s.push(2);
s.push(4);
s.print();
s.pop();
s.print();
cout<<"Count is :"<<s.getCount()<<endl;
return 0;
}