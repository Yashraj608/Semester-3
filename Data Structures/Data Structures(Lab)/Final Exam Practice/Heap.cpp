#include<iostream>
using namespace std;

class Heap {
public:
    int* arr;
    int size;
    int capacity;

    Heap(int capacity = 100) {
        this->capacity = capacity;
        size = 0;
        arr = new int[capacity];
    }

    
    void HeapifyUp(int index) {
          while(index > 0){
            int parent = (index -1)/2;
            if(arr[parent] <arr[index]){
                swap(arr[parent],arr[index]);
                index = parent;
            }else{
                break;
            }
          }
    }

    // ===== You will write this =====
    void HeapifyDown(int index) {
      int left , right , largest;
      while(true){
        left = 2*index +1;
        right = 2*index +2;
        largest = index;

        if(left < size && arr[left] > arr[largest]){
            largest = left;
        }

        if(right < size && arr[right] > arr[largest]){
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

    void insert(int value) {
        if (size == capacity) {
            cout << "Heap is full !" << endl;
            return;
        }
        arr[size++] = value;
        HeapifyUp(size - 1);  // call your function
    }

    int extractMax() {
        if (size == 0) {
            cout << "Heap is empty !" << endl;
            return -1;
        }
        int maxVal = arr[0];
        arr[0] = arr[size - 1];
        size--;
        HeapifyDown(0);  // call your function
        return maxVal;
    }

    int top() {
        if (size == 0) {
            cout << "Heap is empty !" << endl;
            return -1;
        }
        return arr[0];
    }

    void Display() {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Heap h;
    h.insert(23);
    h.insert(22);
    h.insert(24);
    h.insert(20);
    h.insert(21);

    cout << "Heap is : " << endl;
    h.Display();

    return 0;
}
