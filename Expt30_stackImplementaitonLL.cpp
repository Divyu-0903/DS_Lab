#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top != NULL) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    int peek() {
        if (top != NULL) {
            return top->data;
        }
        return -1;
    }

    bool isEmpty() {
        return top == NULL;
    }
};

int main() {
    Stack myStack;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    cout << "Top element: " << myStack.peek() << endl;
    myStack.pop();

    cout << "Top element after pop: " << myStack.peek() << endl;

    myStack.push(4);
    myStack.push(5);

    while (!myStack.isEmpty()) {
        cout << "Popped: " << myStack.peek() << endl;
        myStack.pop();
    }

    return 0;
}
