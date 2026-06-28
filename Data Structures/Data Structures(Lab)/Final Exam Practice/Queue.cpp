#include <iostream>
#include <string>
using namespace std;

// Patient struct with two priority parameters
struct Patient {
    string name;
    int urgency;
    int arrivalTime; // lower = earlier arrival
};

class PriorityQueue {
private:
    Patient* arr;
    int size;
    int capacity;

    // Comparison function for multi-level priority
    bool higherPriority(Patient& p1, Patient& p2) {
        // return true if p1 should come before p2
        if (p1.urgency > p2.urgency) return true;
        if (p1.urgency == p2.urgency && p1.arrivalTime < p2.arrivalTime) return true;
        return false;
    }

    void HeapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (higherPriority(arr[index], arr[parent])) {
                swap(arr[index], arr[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void HeapifyDown(int index) {
        int largest;
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            largest = index;

            if (left < size && higherPriority(arr[left], arr[largest]))
                largest = left;
            if (right < size && higherPriority(arr[right], arr[largest]))
                largest = right;

            if (largest != index) {
                swap(arr[index], arr[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

public:
    PriorityQueue(int cap = 100) {
        capacity = cap;
        size = 0;
        arr = new Patient[capacity];
    }

    ~PriorityQueue() {
        delete[] arr;
    }

    void enqueue(Patient p) {
        if (size == capacity) {
            cout << "Queue full!\n";
            return;
        }
        arr[size++] = p;
        HeapifyUp(size - 1);
    }

    void dequeue() {
        if (size == 0) {
            cout << "Queue empty!\n";
            return;
        }
        arr[0] = arr[size - 1];
        size--;
        HeapifyDown(0);
    }

    Patient peek() {
        if (size == 0) {
            cout << "Queue empty!\n";
            return {"", -1, -1};
        }
        return arr[0];
    }

    void display() {
        cout << "Patients in queue:\n";
        for (int i = 0; i < size; i++)
            cout << arr[i].name << " (Urgency: " << arr[i].urgency 
                 << ", Arrival: " << arr[i].arrivalTime << ")\n";
        cout << endl;
    }
};

// ----------------- Example Scenario -----------------
int main() {
    PriorityQueue pq;

    pq.enqueue({"John", 5, 1});
    pq.enqueue({"Alice", 8, 2});
    pq.enqueue({"Bob", 8, 0});
    pq.enqueue({"Eve", 7, 3});
    pq.enqueue({"Charlie", 5, 0});

    cout << "Most urgent patient: " << pq.peek().name << endl << endl;

    cout << "Queue before dequeue:\n";
    pq.display();

    pq.dequeue();

    cout << "Queue after dequeue:\n";
    pq.display();

    return 0;
}
