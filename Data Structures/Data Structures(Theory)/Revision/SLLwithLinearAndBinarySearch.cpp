//This program includes every functions built from scratch and also includes the linear search and the binary search function on linkedlist//
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
class SingleLinkdeList{
public:
Node*head,*tail;
SingleLinkdeList(){
    head = tail = nullptr;
}

void insertAtHead(int value){
    Node*newNode  = new Node(value);
    if(head == nullptr){
        head = tail = newNode;
    }else{
        newNode->next = head;
        head = newNode;
    }
}

void InsertAtback(int value){
Node*newNode = new Node(value);
if(head == nullptr){
    head = tail = newNode;
}else{
     tail->next = newNode;
     tail = newNode;
}
}

void DisplayLinkedList(){
    Node*temp=head;
    while(temp != nullptr){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL";
}

void popback(){
    if(head == nullptr){
        return;
    }
    if(head == tail){
        delete head,tail;
        head = tail = nullptr;
    }else{
        Node*temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = nullptr;
    }
}


void InsertAtposition(int value,int pos){
    if(pos<0){return;}
    if(pos == 0){
      insertAtHead(value);
      return;
    }
    int count=0;
    Node*temp = head;
    while(temp != nullptr && count < pos-1){
        temp = temp->next;
        count++;
    }
        if(temp== nullptr){
            return;
        }
        Node*newNode = new Node(value);
        newNode->next  = temp->next;
        temp->next = newNode;
        }
    


        void popfront(){
            if(head == nullptr){
                return;
            }

            if(head == tail){
                delete head;
                delete tail;
                return;
            }else{
                Node*temp = head;
                head = head->next;
                delete temp;
            }
        }

        int linearSearch(int key){
            Node*temp = head;
            int pos=0;
          
            while(temp != nullptr){
                if(temp->data == key){
                    return pos;
                }
                pos++;
                temp = temp->next;
            }
            return -1;
        }


        Node*middleOfLinkedlist(Node*start, Node*end){
            Node*slow = start;
            Node*fast = end;
            while(fast != nullptr && fast->next != nullptr){
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;
        }


        Node* BinarySearch(int key){
            Node*start = head;
            Node*end = nullptr;
            if(start == nullptr){
                return nullptr;
            }

            while(start != end){
                Node*mid  = middleOfLinkedlist(start,end);
                if(mid->data == key){
                    return mid;
                }
                if(mid->data > key){
                    start = mid->next;
                }else{
                    end = mid;
                }
            }
            return nullptr;
        }
};
int main(){
SingleLinkdeList sll;
sll.insertAtHead(3);
sll.insertAtHead(1);
sll.insertAtHead(4);
sll.insertAtHead(5);
sll.insertAtHead(6);
sll.InsertAtback(10);
sll.DisplayLinkedList();
sll.popback();
cout<<endl;
sll.DisplayLinkedList();
sll.InsertAtposition(7,0);
cout<<endl;
sll.DisplayLinkedList();
sll.popfront();
cout<<endl;
sll.DisplayLinkedList();
cout<<endl;
int result = sll.linearSearch(1);
if(result != -1){
    cout<<"Key Found at :"<<result<<" index"<<endl;
}else{
    cout<<"Key not found !"<<endl;
}


Node*BinaryResult = sll.BinarySearch(4);
if(BinaryResult != nullptr){
    cout<<"Found the data : "<<BinaryResult->data<<endl;
}
else{
    cout<<"Data Not Found"<<endl;
}
return 0;
}