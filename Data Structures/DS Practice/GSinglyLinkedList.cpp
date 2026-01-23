#include<iostream>
#include<string>
#include<cstring>
using namespace std;

template<typename T> 
class Node{
 public:
 T data;
 Node<T>*next;
 Node(T data){
   this->data = data;
   next = nullptr;
 }
};

template<typename T>
class SinglyLinkedList{
public:
Node<T>*head,*tail;
SinglyLinkedList(){
    head = tail = nullptr;
}

void InsertAtHead(T value){
    Node<T>*newNode = new Node<T>(value);
    if(head == nullptr){
        head = tail = newNode;
    }else{
        newNode->next = head;
        head = newNode;
    }
}


void BubbleSort(Node<T>*head){
        if(head == nullptr){
            return;}

            bool swapped;
            do{
                swapped = false;
                Node<T>*current = head;
                while(current->next != nullptr){
                    if(current->data > current->next->data){
                        swap(current->data,current->next->data);
                        swapped = true;
                    }
                     current = current->next;
                }
               



            }while(swapped);
}

void InsertAtBack(T value){
    Node<T>*newNode = new Node<T>(value);
    if(head == nullptr){
        head = tail = newNode;
    }else{
        tail->next = newNode;
        tail = newNode;
    }
}

Node<T>* LinearSearch(T value){
    Node<T>*temp = head;
    while(temp != nullptr){
        if(temp->data==value){
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

Node<T>* MiddleOfLinkedlist(Node<T>*start,Node<T>*end){
    Node<T>*slow = start;
    Node<T>*fast = start;
    while(fast != end && fast->next != end){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node<T>*BinarySearch(T value){
    Node<T>*start = head;
    Node<T>*end = nullptr;
    while(start != end){
        Node<T>*mid= MiddleOfLinkedlist(start,end);
        if(mid->data==value){
            return mid;
        }else if(mid->data >value){
           end = mid;
        }else{
            start = mid->next;
        }
    }
    return nullptr;
}
void Display(){
    Node<T>*temp = head;
    while(temp != nullptr){
        cout<<temp->data<<"->";
        temp= temp->next;
    }
    cout<<"Null";
}

T*toArray(T &size){
    size= 0;
    Node<T>*temp = head;
    while(temp != nullptr){
        size++;
        temp = temp->next;
    }
    T*arr = new T[size];
    temp = head;
    int i =0;
    while(temp != nullptr){
        arr[i++] = temp->data;
        temp = temp->next;
    }
    return arr;

}
};
int main(){
SinglyLinkedList <int>sll;
sll.InsertAtHead(12);
sll.InsertAtHead(28);
sll.InsertAtHead(32);
sll.InsertAtHead(21);
sll.InsertAtBack(25);
sll.Display();    
cout<<endl;
// Node<int>*searchResult = sll.LinearSearch(23);

SinglyLinkedList<string> sl;
sl.InsertAtHead("Helo");
sl.InsertAtHead("Hello World");
sl.Display();
Node<string>*binaryResult = sl.BinarySearch("Hello World");

if(binaryResult){
    cout<<"Target found : "<<binaryResult->data<<endl;
}else{
    cout<<"Not Found"<<endl;
}

sll.BubbleSort(sll.head);
sll.Display();

int size =0;
int*arr = sll.toArray(size);
for(int i =0;i<size;i++){
    cout<<arr[i]<<" ";
}
return 0;
}