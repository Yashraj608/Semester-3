#include<iostream>
using namespace std;
class PriorityQueue{
public:
int size;
int arr[1000];

PriorityQueue(){
    size = 0;
}

void HeapifyUp(int index){
    while(index >1){
        int parent = index/2;
        if(arr[parent] < arr[index]){
            swap(arr[parent],arr[index]);
            index = parent;
        }else{
            break;
        }
    }
}

void HeapifyDown(int index){
    while(true){
        int left = 2*index;
        int right = left +1;
        int largest = index;

        if(left <= size && arr[left] > arr[largest]){
            largest = left;
        }
        if(right <= size && arr[right] > arr[largest]){
            largest = right;
        }

        if(largest != index){
            swap(arr[index],arr[largest]);
            index = largest;
        }else{
            break;
        }
    }
}

void push(int value){
    size++;
arr[size] = value;
HeapifyUp(size);
}

int top(){
    if(size == 0){
        return -1;
    }
    return arr[1];
}

void pop(){
    if(size == 0){
        return;
    }else{
        arr[1] = arr[size];
        size--;
        HeapifyDown(1);
    }
}

bool empty(){
    if(size==0){
        return true;
    }
    return false;
}

void Display(){
    for(int i =1;i<size;i++){
     cout<<arr[i]<<" ";
    }
    cout<<endl;
}
};
int main(){
    PriorityQueue pq;
    pq.push(21);
    pq.push(27);
    pq.push(26);
    pq.push(22);
    pq.push(20);
    cout<<"Priority Queue is: "<<endl;
    pq.Display();
    return 0;
}