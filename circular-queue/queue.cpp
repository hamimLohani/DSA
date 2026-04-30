#include <iostream>
using namespace std;

class CircularQueue {
private:
    int arr[5];
    int front, rear, size;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
        size = 5;
    }
    bool isFull() {
        return (front == (rear + 1) % size);
    }
    bool isEmpty() {
        return (front == -1);
    }
    void enqueue(int value) {
        if (isFull()) {
            cout << "The queue is overloaded!\n";
            return;
        }
        if (isEmpty()) 
            front = rear = 0;
        else
            rear = (rear + 1) % size;
            
        arr[rear] = value;
        cout << value << " enqueued.\n";
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "The queue is underflow!\n";
            return;
        }
        cout << arr[front] << " dequeued.\n";
        if (front == rear) 
            front = rear = -1;
        else 
            front = (front + 1) % size;
    }
    void display() {
        if (isEmpty()) {
            cout << "The queue is empty.\n";
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) 
                break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    int choice, value;

    while (true) {
        cout << "\n=== Circular Queue Operation ===\n";
        cout << "\t1. Enqueue.\n";
        cout << "\t2. Dequeue.\n";
        cout << "\t3. Exit.\n";

        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter element: ";
            cin >> value;
            q.enqueue(value);
            q.display();
            break;
        case 2:
            q.dequeue();
            q.display();
            break;
        case 3:
            return 0;    
        default:
            cout << "Invalid choice.\n";
        }
    }
   
}