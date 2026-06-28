#include<iostream>
using namespace std;
class Node{
public:
int data;
Node*next;
Node(int value){
    this->data =value;
    next = nullptr;
}
};

class SinglyLinkedList{
public:
Node*head,*tail;
SinglyLinkedList(){
    head = tail = nullptr;
}

void InsertAtHead(int value){
    Node*newNode = new Node(value);
    if(head == nullptr){
        head = tail = newNode;
    }else{
        newNode->next = head;
        head = newNode;
    }
}

void pop_front(){
    if(head == tail){
        delete head;
        head = tail = nullptr;
    }else{
        Node*temp = head;
        head=  head->next;
        temp->next = nullptr;
        delete temp;
    }
}
void pop_back(){
    Node*temp = head;
    if(head == tail){
        delete head;
        head = tail = nullptr;
    }else{
        while(temp->next != tail){
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = nullptr;
    }
}
void InsertAtBack(int value){
    Node*newNode = new Node(value);
    if(head == nullptr){
   head = tail = newNode;
    }else{
        tail->next = newNode;
        tail = newNode;
    }
}

void DisplayLinkedList(){
    Node*temp = head;
    while(temp != nullptr){
        cout<<temp->data<< "->";
        temp = temp->next;
    }
    cout<<"Null"<<endl;
}
void InsertAtAnyPos(int pos, int value){
    Node*newNode = new Node(value);
    if(pos==0){
        InsertAtHead(value);
    }
    if(pos<0){
        return;
    }

    Node*temp = head;
    for(int i =0;i<pos-1 && temp->next != nullptr;i++){
      temp = temp->next;
    }
    if(temp == nullptr){
        cout<<"Out of Range"<<endl;
        delete newNode;
        return;
    }else{
        newNode->next = temp->next;
        temp->next = newNode;
    }

    if(newNode->next == nullptr){
        tail = newNode;
    }
}

Node*ReverseLinkedList(){
    Node*current = head;
    Node*prev = nullptr;
    Node*next = nullptr;
    while(current != nullptr){
      next =   current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
   return head = prev;
}
 
};
int main(){
SinglyLinkedList s;
s.InsertAtBack(22);
s.InsertAtHead(2);
s.InsertAtHead(9);
s.InsertAtHead(4);
s.InsertAtHead(10);
s.DisplayLinkedList();
cout<<endl;
s.pop_back();
s.DisplayLinkedList();
cout<<endl;
s.pop_front();
s.DisplayLinkedList();
s.InsertAtAnyPos(3,15);
cout<<endl;
s.DisplayLinkedList();

Node*Reversed = s.ReverseLinkedList();
cout<<"After Reversing the linked list: "<<endl;
s.DisplayLinkedList();
    return 0;
}