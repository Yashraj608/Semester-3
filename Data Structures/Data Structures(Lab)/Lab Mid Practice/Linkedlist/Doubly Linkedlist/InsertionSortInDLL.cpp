#include<iostream>
using namespace std;
class Node{
public:
int data;
Node*next;
Node*prev;
Node(int data){
    this->data = data;
    next= prev = nullptr;
}
};

class DoublyLinkedList{
public:
Node*head,*tail;
DoublyLinkedList(){
    head = tail = nullptr;
}

void pushBack(int value){
    Node* newNode = new Node(value);
    if(head == nullptr){
        head = tail = newNode;
    }else{
        newNode->prev = tail;   // FIXED: link backward
        tail->next = newNode;
        tail = newNode;
    }
}


void pop_back(){
    if(head==nullptr){
     return;
    }
    
    if(head ==tail){
       delete head;
      head = tail = nullptr;
    }else{
        Node*temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
       
    }
}

void Pop_front(){
    if(head==nullptr){
        return;
    }

    if(head==tail){
        delete head;
        head = tail = nullptr;
    }else{
        Node*temp = head;
       head = head->next;
       head->prev = nullptr;
        delete temp;
    }
}

void pushFront(int value){
    Node*newNode = new Node(value);
    if(head == nullptr){
        head = tail = newNode;
        newNode->prev= nullptr;
    }else{
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void DisplayBackward(){
    Node*temp = tail;
    while(temp != nullptr){
        cout<<temp->data<<"->";
        temp = temp->prev;
    }
    cout<<"Null"<<endl;
}

void DisplayForward(){
    Node*temp = head;
    while(temp != nullptr){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"Null"<<endl;
}

void InsertionSort(){
if(!head){
    return;
}
    for(Node*i = head->next;i != nullptr;i = i->next){
      Node*j = i;
      while(j->prev != nullptr &&j->data < j->prev->data){
              swap(j->data , j->prev->data);
                j = j->prev;
        }
        }
    }

};
int main(){
    DoublyLinkedList dll;
    dll.pushFront(3);
    dll.pushFront(2);
    dll.pushFront(7);
    dll.pushFront(6);
    dll.DisplayForward();
    dll.pushBack(34);
    dll.DisplayForward();
    dll.pop_back();
    dll.DisplayForward();
    dll.Pop_front();
    dll.DisplayForward();

    dll.InsertionSort();
    dll.DisplayForward();

}