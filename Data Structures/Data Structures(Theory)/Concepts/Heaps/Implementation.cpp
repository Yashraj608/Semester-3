#include<iostream>
using namespace std;
class Heap{
public:
int arr[100];
int size;
Heap(){
  size = 0;
  arr[0] = -1;
}

void heapify(int i ){
    int largest = i;
    int left = 2*i;
    int right = 2*i +1;


    if(left <= size && arr[left] > arr[largest]){
        largest = left;
    }


    if(right <= size && arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != i){
        swap(arr[i],arr[largest]);
        heapify(largest);
    }
}

void insert(int value){
    size = size +1;
    int index = size ;
    arr[index] = value;

    while(index >1 ){
        int parent = index/2;
      if(arr[parent] < arr[index]){
        swap(arr[parent],arr[index]);
        index = parent;
      }else{
        break;
      }
    }
}


void Deletion(){
    if(size == 0){
        cout<<"Heap is empty "<<endl;
        return;
    }

    arr[1] = arr[size];
    size--;

    heapify(1);
}


void display(){
    for(int i = 1; i <= size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


void HeapSort(){
    int n = size;
    int i = n /2;
    while(i >0){
        heapify(1);
        i--;
    }
    int end = n ;
    while(end >1 ){
        swap(arr[1], arr[end]);
        size --;
        heapify(1);
        end--;
    }

    size = n ;
    cout<<"Heap Sorted in ascending order : ";
    for(int i =1;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
};

int main(){
Heap h;
h.insert(50);
h.insert(55);
h.insert(53);
h.insert(52);
h.insert(54);


cout<<"Heap Elements: "<<endl;
h.display();

cout<<"After deleteing root: "<<endl;
h.Deletion();
h.display();

cout<<"After heap Sort: "<<endl;
h.HeapSort();
return 0;
}