#include<iostream>
using namespace std;
class Node{
public:
int data;
Node*next,*prev;
Node(int data){
    this->data = data;
    next = prev = nullptr;
}
};
class DLinkedlist{
public:
Node*head,*tail;
DLinkedlist(){
    head = tail = nullptr;
}

void InsertAtHead(int value){
    Node*newNode = new Node(value);
    if(head == nullptr){
       head = tail = newNode;
    }else{
        newNode->next = head;
        head->prev = newNode;
        head  = newNode;
    }
}

void InsertAtback(int value){
    Node*newNode = new Node(value);
    if(head == nullptr){
        head = tail = newNode;
    }else{
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

Node*LinearSearch(int value){
    Node*temp = head;
    while(temp != nullptr){
        if(temp->data == value){
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

Node*Middle(Node*start,Node*end){
        Node*slow = start;
        Node*fast = start;
        while(fast != end && fast->next != end){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
}
Node*binarySearch(Node*head, int value){
    Node*start = head;
    Node*end = nullptr;
    while(start != end){
        Node*mid = Middle(start,end);
        if(mid->data == value){
            return mid;
        }else if(mid->data < value){
             start = mid->next;
        }else{
            end = mid;
        }
    }
}

void Popback(){
    if(head == nullptr){
        return;
    }
    if(head == tail){
        delete head;
        head = tail = nullptr;
    }else{
        Node*temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
    }
}

void displayForward(){
    Node*temp = head;
    while(temp != nullptr){
        cout<<temp->data<<"->";
         temp = temp->next;
    }
      
    cout<<"Null";
}


void PopFront(){
    if(head == nullptr){
        return;
    }
    if(head == tail){
        delete head;
        head = tail = nullptr;
    }else{
        Node*temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
    }
}

void bubblesort(){
    if(head ==  nullptr){
        return;
    }
    bool swapped;
    do{
        swapped = false;
        Node*current = head;
        while(current->next != nullptr){
            if(current->data > current->next->data){
                swap(current->data,current->next->data);
                swapped  = true;
            }
            current = current->next;
        }
    }while(swapped);
}
};
int main(){
    
    DLinkedlist dll;
    dll.InsertAtHead(1);
    dll.InsertAtHead(3);
    dll.InsertAtHead(4);
    dll.InsertAtHead(10);
    dll.InsertAtHead(6);
    dll.InsertAtback(5);
    dll.displayForward();
    cout<<endl;

    dll.bubblesort();
    cout<<endl;
    cout<<"After sorting : "<<endl;
    dll.displayForward();
cout<<endl;
    dll.Popback();
    dll.displayForward();
    cout<<endl;
    dll.PopFront();
    dll.displayForward();

cout<<endl;
    Node*resultOfLinear = dll.LinearSearch(5);
    if(resultOfLinear){
        cout<<resultOfLinear->data<<" found successfully"<<endl;
    }else{
        cout<<"Not Found ! "<<endl;
    }

    return 0;
}