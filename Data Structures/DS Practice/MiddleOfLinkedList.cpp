#include<iostream>
using namespace std;
class Node{
public:
Node*next;
int data;
Node(int value){
    this->data = value;
    next = nullptr;
}
};

class Linkedlist{
public:
Node*head,*tail;
Linkedlist(){
    head = tail = nullptr;
}

void pushfront(int value){
    Node*newNode = new Node(value);
    if(head == nullptr){
        head = tail = newNode;
    }else{
        newNode->next = head;
        head = newNode;
    }
}

void pushback(int value){
    Node*newNode = new Node(value);
    if(head == nullptr){
        head = tail = newNode;
    }else{
        tail->next = newNode;
        tail = newNode;
        tail->next = nullptr;
    }
}

Node* MiddleLinkedlist(){
    Node*slow = head;
    Node*fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void display(){
    Node*temp = head;
    while(temp != nullptr){
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<"Null"<<endl;
}
};
int main(){
Linkedlist l;
l.pushfront(20);
l.pushfront(30);
l.pushfront(40);
l.pushfront(50);
l.pushfront(60);
l.pushfront(70);
l.display();

Node*mid = l.MiddleLinkedlist();
cout<<"Value of mid: "<<mid->data<<endl;
return 0;
}