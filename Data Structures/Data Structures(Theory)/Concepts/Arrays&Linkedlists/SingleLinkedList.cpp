#include<iostream>
using namespace std;
class Node{
public:
int data;
Node*next;
Node(int data){
this->data = data;
next = NULL;
}
};

class LinkedList{
public:
Node*head;
Node*Tail;
LinkedList(){
    head = NULL;
    Tail = NULL;
}
void push_front(int value){
  Node*newNode = new Node(value);
  if(head==NULL){
    head = Tail= newNode;
    return;
  }
  else{
    newNode->next = head;
    head = newNode;
  }
}

void pushback(int value){
    Node*newNode = new Node(value);
    if(head==NULL){
        head = Tail = newNode;
    }else{
         Tail->next = newNode;
         Tail = newNode;
    }
}

void insertAtposition(int value,int pos){
    if(pos == 0){
        push_front(value);
    }

    if(pos<0){
        cout<<"Invalid Position"<<endl;
        return;
    }
    else{
        Node*temp = head;
        for(int i =0;i<pos;i++){
            temp = temp->next;
        }
        Node*newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void popfront(){
    if(head==NULL){
        return;
    }
    Node*temp = head;
    head = head->next;
    temp->next = nullptr;
    delete temp;
}

void pop_back() {
    if (head == NULL) {
        return;
    }

    if (head == Tail) { // Only one node
        delete head;
        head = Tail = NULL;
        return;
    }

    Node* temp = head;
    while (temp->next != Tail) {
        temp = temp->next;
    }

    delete Tail;
    Tail = temp;
    Tail->next = NULL;
}


void display(){
    Node*temp = head;
    while(temp != NULL){
        cout<<temp->data<<" -> ";
        temp= temp->next;
    }
cout<<"NULL"<<endl;
}


int searchKey(int key){
    int index = 0;
    Node*temp = head;
    while(temp != NULL){
        if(temp->data == key){
            return index;
        }
        temp = temp->next;
        index++;
    }
    cout<<endl;
return -1;
}
};
int main(){
LinkedList l;
l.push_front(10);
l.push_front(20);
l.push_front(30);
// l.display();
l.pushback(40);
l.display();
l.pop_back();
l.display();

cout<<l.searchKey(30);
cout<<l.searchKey(40);
    return 0;
}