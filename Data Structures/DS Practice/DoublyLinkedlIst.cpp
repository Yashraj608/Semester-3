#include<iostream>
using namespace std;
class DoubleNode{
public:
int data;
DoubleNode*next;
DoubleNode*prev;
DoubleNode(int data){
    this->data = data;
    next = prev = nullptr;
}
};

class DoubleLinkedlist{
public:
DoubleNode*head,*tail;
DoubleLinkedlist(){
    head = tail = nullptr;
}


void pushfront(int value){
    DoubleNode*newNode = new DoubleNode(value);
    if(head == nullptr){
        head = tail = newNode;
    }else{
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}


void displayForward(){
    cout<<"Displaying Linkedlist in Forward manner: "<<endl;
    DoubleNode*temp = head;
    while(temp!= nullptr){
        cout<<temp->data<<"<->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}


void displayBackward(){
    cout<<"Displaying Linkedlist in Backward manner: "<<endl;
    DoubleNode*temp = tail;
    while(temp != nullptr){
        cout<<temp->data<<"<->";
         temp = temp->prev;
    }
    cout<<"NULL"<<endl;
}


void popback(){
    DoubleNode*temp = tail;
    if(head == tail){
        head = tail = nullptr;
    }
    else{
        tail = temp->prev;
        temp->prev = nullptr;
        tail->next = NULL;
        delete temp;
    }
}

void popfront(){
    DoubleNode*temp = head;
    if(head == nullptr){
        cout<<"Doubly LinkedList is already empty"<<endl;
        return;
    }
    if(head == tail){
        head = tail = nullptr;
    } 
    else{
head = head->next;
head->prev = nullptr;
delete temp;
    }
}
};
int main(){
    DoubleLinkedlist dll;
    dll.pushfront(22);
    dll.pushfront(23);
    dll.pushfront(25);
    dll.pushfront(24);
    dll.displayForward();
    dll.popfront();
    dll.displayForward();
    dll.popback();
    dll.displayForward();
 
    return 0;
}