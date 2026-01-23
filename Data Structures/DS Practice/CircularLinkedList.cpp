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

class circularLinkedlIst{
public:
Node*head,*tail;
circularLinkedlIst(){
    head = nullptr;
    tail = nullptr;
}


void insertAtHead(int value){
    Node*newNode = new Node(value);
    if(head == nullptr){
        head = tail = newNode;
        tail->next = head;
    }
    else{
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }
}

void InsertAtBack(int value){
    Node*newNode = new Node(value);
    if(head == nullptr){
         head = tail = newNode;
         tail->next = head;
    }
   else{
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }

}

void PopBack(){
    Node*temp = tail;
    if(head == nullptr){
        return;
    }
    if(head == tail){
        delete head;
        head = tail = nullptr;
    }
    while(temp->next != tail){
        temp = temp->next;
    }
    delete tail;
    temp = tail;
    tail->next  = head;
}

void popFront(){
    Node*temp = head;
    if(head == nullptr){
        return;
    }
    if(head == tail){
        delete head;
        head = tail = nullptr;
        return;
    }else{
        head = head->next;
        tail->next = head;
        delete temp;
    }
}
Node*LinearSearch(int value){
       Node*temp = head;
    do{
       if(temp->data == value){
        return temp;
       }
       temp = temp->next;

    }while(temp != head);
    return nullptr;
}

void display(){
    if(head == nullptr){
        return;
        cout<<"Circular LinkedList is empty ! "<<endl;
    }
    Node*temp = head;
    do{
       cout<<temp->data<<"->";
       temp = temp->next;
    }while(temp != head);
}
};
int main(){
  circularLinkedlIst cll;
  cll.insertAtHead(9);
  cll.insertAtHead(3);
  cll.insertAtHead(4);
  cll.insertAtHead(5);
  cll.display();

  Node*result = cll.LinearSearch(4);
  if(result){
    cout<<"Found :"<<result->data<<endl;
  }
    return 0;
}