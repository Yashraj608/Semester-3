#include<iostream>
using namespace std;
class Node{
public:
int data;
Node*next;
Node(int data){
    this->data = data;
    next = nullptr;
}
};

class Queue{
public:
Node*start,*end;
int count =0;
Queue(){
    start = end = nullptr;
}

void push(int value){
    Node*newNode = new Node(value);
    if(start == nullptr){
        start = end = newNode;
    }
    else{
        end->next = newNode;
        end = newNode;
    }
}
};
int main(){

    return 0;
}