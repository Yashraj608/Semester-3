#include<iostream>
using namespace std;
class Heap{
public:
int size;
int arr[100];
Heap(){
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

void deleteRoot(){
    if(size == 0){
        return;
    }else{
        arr[1] = arr[size];
        size--;
        HeapifyDown(1);
    }
}

void insert(int value){
    size++;
    arr[size] = value;
    HeapifyUp(size);
}


int getMax(){
    if(size ==0){
        return 0;
    }else{
        return arr[1];
    }
}

int extractMax(){
    if(size ==0){
        return 0;
    }else{
        int max = arr[1];
        deleteRoot();
        return max;
    }
}


bool Search(int value){
    if(size == 0){
        return false;
    }else{
        for(int i =1;i<=size;i++){
            if(arr[i]==value){
                return true;
            }
        }
    }
    return false;
}

void BuildHeap(int input[], int n){
    size = n;
    for(int i =1;i<=n;i++){
     arr[i] = input[i-1];
    }
    for(int i = size/2;i>=1;i--){
        HeapifyDown(i);
    }
}

void Display(){
    for(int i =1;i<=size;i++){
        cout<<arr[i]<<" ";
    }
cout<<endl;
}

void HeapSort(){
    int original = size;
    for(int i =size;i>1;i--){
        swap(arr[1],arr[i]);
        size--;
        HeapifyDown(1);
    }
    size = original;
}
};

int main(){
Heap h;
h.insert(19);
h.insert(23);
h.insert(30);
h.insert(27);
h.insert(24);
h.insert(29);
h.insert(21);
h.insert(22);
h.insert(20);

cout<<"Heap is: "<<endl;
h.Display();

cout<<"Max Element is : "<<h.getMax()<<endl;

cout<<"Extract Max : "<<h.extractMax()<<endl;
h.Display();
h.HeapSort();
cout<<"Heap After sorting : "<<endl;
h.Display();

int n;
cout<<"Enter the heap Size : "<<endl;
cin>>n;
int*arr = new int[n];
cout<<"Enter the elements of heap: "<<endl;
for(int i =0;i<n;i++){
    cin>>arr[i];
}
h.BuildHeap(arr,n);
cout<<"Heap After build Heap: "<<endl;
h.Display();

delete[]arr;
return 0;
}