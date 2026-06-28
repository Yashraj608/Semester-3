#include<iostream>
using namespace std;
class Node{
public:
int data;
Node*next;
Node(int value){
    this->data = value;
    next = nullptr;
}
};

class CircularLinkedList{
public:
Node*head,*tail;
CircularLinkedList(){
    head =tail = nullptr;
}


void Push_Front(int value){
    Node*newNode = new Node(value);
    if(head == nullptr){
        head = tail = newNode;
        tail->next = head;
    }else{
       newNode->next = head;
       head  = newNode;
       tail->next = head;
    }
}

void push_back(int value){
    Node*newNode = new Node(value);
    if(head == nullptr){
        head = tail = newNode;
        tail->next  = head;
    }else{
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }
}


void pop_back(){
    if(head == nullptr){
        return;
    }

    if(head == tail){
        delete head;
        head = tail = nullptr;
        return;
    }else{
        Node*temp  = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = head;
    }
}


void pop_front(){
    if(head == nullptr){
        return;
    }

    if(head == tail){
     delete head;
     head = tail = nullptr;
     return;
    }else{
        Node*temp = head;
        head = head->next;
        tail->next = head;
        delete temp;

    }
}

void print(){
    if(head==nullptr){
        cout<<"Empty LinkedList"<<endl;
        return;
    }
       Node*temp = head;
    do{
     
       cout<<temp->data<<"->";
       temp = temp->next;
    }while(temp != head);
    cout<<"head"<<endl;
}


};
int main(){
    CircularLinkedList cll;
    
    cll.Push_Front(9);
    cll.Push_Front(3);
    cll.Push_Front(6);
    cll.Push_Front(1);
    cll.Push_Front(8);
    cll.push_back(2);
    cll.print();
    cll.pop_back();
    cout<<endl;
    cll.print();
    return 0;
}