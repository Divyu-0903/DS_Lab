#include <iostream>
using namespace std;

class Stack {
private:
    int size;
    int top;
    int* arr;

public:
    Stack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int value) {
        if (top < size - 1) {
            arr[++top] = value;
        } else {
            cout << "Stack is full. Cannot push." << endl;
        }
    }

    void pop() {
        if (top >= 0) {
            top--;
        } else {
            cout << "Stack is empty. Cannot pop." << endl;
        }
    }

    int peek() {
        if (top >= 0) {
            return arr[top];
        } else {
            cout << "Stack is empty. Cannot peek." << endl;
            return -1;
        }
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == size - 1;
    }
};

int main() {
    Stack myStack(5);

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    cout << "Top element: " << myStack.peek() << endl;
    myStack.pop();

    cout << "Top element after pop: " << myStack.peek() << endl;

    myStack.push(4);
    myStack.push(5);
    myStack.push(6); 

    while (!myStack.isEmpty()) {
        cout << "Popped: " << myStack.peek() << endl;
        myStack.pop();
    }

    return 0;
}
