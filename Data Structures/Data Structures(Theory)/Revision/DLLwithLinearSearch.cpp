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
class DoublyLinkedList{
public:
DoubleNode*head,*tail;
DoublyLinkedList(){
head = tail = nullptr;
}

void insertAtFront(int value){
    DoubleNode*newNode =new DoubleNode(value);
    if(head == nullptr){
        head = tail = newNode;
    }else{
        newNode->next = head;
       head->prev = newNode;
        head = newNode;
       
    }

}

void InsertAtBack(int value){
    DoubleNode*newNode = new DoubleNode(value);
    if(head == nullptr){
        head = tail  = newNode;
    }else{
        tail->next  = newNode;
        newNode->prev  = tail;
        tail = newNode;
    }
}

void displayFoward(){
    DoubleNode*temp = head;
    while(temp != nullptr){
        cout<<temp->data<<"<->";
        temp = temp->next;
    }
     cout<<"Null"<<endl;
}

void displayBackward(){
    DoubleNode*temp = tail;
    while(temp != nullptr){
       cout<<temp->data<<"<->";
        temp = temp->prev;
    }
    cout<<"NULL";
}

void InsertAtAnyPoint(int pos,int value){
    if(pos < 0){
        return;
    }
    if(pos ==0){
        insertAtFront(value);
    }
    int count = 0;
    DoubleNode*temp = head;
    while(temp != nullptr && count < pos-1){
        temp = temp->next;
        count ++;
    }
    DoubleNode*newNode = new DoubleNode(value);
    newNode->next= temp->next;
    newNode->prev = temp;

    if(temp->next != nullptr){
        temp->next->prev = newNode;
    }else{
        tail = newNode;
    }
    temp->next = newNode;
}


void  LinearSearch(int key){
    DoubleNode*temp = head;
    bool found = false;
    while(temp != nullptr){
         if(temp->data == key){
            found = true;
            break;
         }
    }
     temp = temp->next;
    if(found){
        cout<<"Key Found"<<endl;
    }else{
        cout<<"Key Not Found !"<<endl;
    }
}
};

int main(){

    DoublyLinkedList dll;
    dll.insertAtFront(2);
    dll.insertAtFront(9);
    dll.insertAtFront(8);
    dll.insertAtFront(4);
    dll.insertAtFront(5);
    dll.displayFoward();
    cout<<endl;
    dll.displayBackward();
    cout<<endl;
    dll.InsertAtAnyPoint(5,6);
    cout<<endl;
    dll.displayFoward();

    dll.LinearSearch(5);

    return 0;
}