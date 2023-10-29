#include <iostream>
using namespace std;

class Queue {
private:
    int front, rear, size;
    int* arr;

public:
    Queue(int s) {
        size = s;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    ~Queue() {
        delete[] arr;
    }

    void enqueue(int value) {
        if (rear == size - 1) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }

        if (front == -1) {
            front = 0;
        }

        arr[++rear] = value;
    }

    void dequeue() {
        if (front == -1) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        cout << "Dequeued: " << arr[front] << endl;
        
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }

    int peek() {
        if (front == -1) {
            cout << "Queue is empty. No element to peek." << endl;
            return -1;
        }
        return arr[front];
    }

    bool isEmpty() {
        return (front == -1);
    }
};

int main() {
    Queue myQueue(5);

    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);

    cout << "Front element: " << myQueue.peek() << endl;
    myQueue.dequeue();

    cout << "Front element after dequeue: " << myQueue.peek() << endl;

    myQueue.enqueue(4);
    myQueue.enqueue(5);

    return 0;
}
