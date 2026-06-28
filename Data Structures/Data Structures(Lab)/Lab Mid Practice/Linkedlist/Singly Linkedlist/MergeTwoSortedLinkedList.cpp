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

Node*mergeSortedLinkedList(Node*head1, Node*head2){
    if(!head1){
        return head2;
    }
    if(!head2){
        return head1;
    }

    Node*mergedHead = nullptr;
    if(head1->data < head2->data){
      mergedHead = head1;
      head1 = head1->next;
    }else{
        mergedHead = head2;
        head2 = head2->next;
    }

    Node*mergedTail = mergedHead;

    while(head1 && head2){
        if(head1->data <= head2->data){
          mergedTail->next = head1;
          head1 = head1->next;
        }else{
            mergedTail->next = head2;
            head2 = head2->next;
        }
        mergedTail = mergedTail->next;
    }

    if(head1){
        mergedTail->next = head1;
    }
    if(head2){
        mergedTail->next = head2;
    }

return mergedHead;
}

 
};
int main(){
SinglyLinkedList s,s1;
s.InsertAtBack(16);
s.InsertAtHead(12);
s.InsertAtHead(8);
s.InsertAtHead(4);
s.InsertAtHead(2);
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


s1.InsertAtHead(13);
s1.InsertAtHead(5);
s1.InsertAtHead(3);
s1.InsertAtHead(1);


Node*result = s.mergeSortedLinkedList(s.head,s1.head);
cout<<"Merged Sorted LinkedList is: "<<endl;
s.head = result;
s.DisplayLinkedList();
    return 0;
}