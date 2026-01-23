#include<iostream>
using namespace std;
class Node{
public:
Node*next;
int data;
Node(int value){
    this->data = value;
}
};
class CircularList{
public:
Node*head,*tail;
CircularList(){
    head = tail = nullptr;
}

void InsertAtHead(int value){
    Node*newNode = new Node(value);
    if(tail == nullptr){
        head = tail = newNode;
        tail->next = head;
    }else{
        newNode->next = head;
        head = newNode;
        tail->next = newNode;
    }
}

void InsertAtBack(int value){
    Node*newNode = new Node(value);
    if(head== nullptr){
        head = tail = newNode;
    }else{
     newNode->next = tail;
     tail = newNode;
     tail->next = head;
    }
}

void printList(){
    Node*temp = head;
    do{
       cout<<temp->data<<" ";
       temp = temp->next;
    }while(temp != head);
}

int getLength(){
    int count=0;
    Node*temp = head;
    do{
        count++;
        temp = temp->next;
    }while(temp != head);
    return count;
}

Node* getMiddle(int index){
    Node*temp = head;
    for(int i =0;i<index;i++){
        temp = temp->next;
    }
    return temp;
}

int binarySearch(int key){
    int start = 0;
    int end = getLength()-1;

    while(start <= end){
        int mid = start + (end - start)/2;
        Node*middleNode = getMiddle(mid);
        if(middleNode->data == key){
            return mid;
        }
        if(middleNode->data <key ){
            start = mid+1;
        }else{
            end = mid-1;
        }
    }
    return -1;
}
};
int main(){
    
    CircularList cll;
    cll.InsertAtHead(4);
    cll.InsertAtHead(3);
    cll.InsertAtHead(9);
    cll.InsertAtHead(7);
    cll.InsertAtHead(5);
    cll.printList();
    cll.InsertAtBack(5);

cout<<endl;
    int key = 7;
    int result = cll.binarySearch(key);
    if(result){
        cout<<"Key : "<<key<<" -> found using Binary Search"<<endl;
    }
    else{
        cout<<"Key Not Found ! "<<endl;
    }
    return 0;
}