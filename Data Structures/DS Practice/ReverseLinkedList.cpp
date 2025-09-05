#include<iostream>
using namespace std;
class Node{
public:
int data;
Node*next;
Node(int value){
    this->data = value;
    next = NULL;
}
};

class LinkedList{
public:
Node*head;
Node*tail;
LinkedList(){
    head = tail = NULL;
}


void pushfront(int value){
    Node*newNode = new Node(value);
    if(head == NULL){
        head = tail = newNode;
    }else{

        newNode->next = head;
        head = newNode;
    }
}

void pushback(int value){
    Node*newNode = new Node(value);
    if(head == NULL){
        head = tail = newNode;
    }else{
        tail->next = newNode;
        tail = newNode;
        tail->next  = NULL;
    }
}

Node* reverse(Node*head){
    Node*current = head;
    Node*prev = NULL;
    Node*next = NULL;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

void display(){
    Node*temp = head;
    while(temp != NULL){
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
};
int main(){
    LinkedList l;
    l.pushfront(48);
    l.pushfront(40);
    l.pushfront(54);
    l.pushfront(65);
    l.display();
    l.head = l.reverse(l.head);
   cout<<"Reversed LinkedList is : "<<endl; 
    l.display();
    return 0;
}