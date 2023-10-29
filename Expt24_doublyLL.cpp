#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = prev = NULL;
    }
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = tail = NULL;
    }

    void displayList() {
        Node* current = head;
        cout<<"NULL <-> ";
        while (current != NULL) {
            cout << current->data << " <-> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    void insertAtStart(int value) {
        Node* new_node = new Node(value);
        if (head == NULL) {
            head = tail = new_node;
        } else {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
    }

    void insertAtEnd(int value) {
        Node* new_node = new Node(value);
        if (tail == NULL) {
            head = tail = new_node;
        } else {
            new_node->prev = tail;
            tail->next = new_node;
            tail = new_node;
        }
    }

    void deleteNode(int value) {
        Node* current = head;
        while (current != NULL && current->data != value) {
            current = current->next;
        }

        if (current == NULL) {
            cout << "Node with value " << value << " not found." << endl;
            return;
        }

        if (current->prev != NULL) {
            current->prev->next = current->next;
        } else {
            head = current->next;
        }

        if (current->next != NULL) {
            current->next->prev = current->prev;
        } else {
            tail = current->prev;
        }

        delete current;
    }
};

int main() {
    DoublyLinkedList head;
    int choice, value;

    while (true) {
        cout << "1. Insert at the beginning" << endl;
        cout << "2. Insert at the end" << endl;
        cout << "3. Delete a node" << endl;
        cout << "4. Display the list" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value to insert at the beginning: ";
            cin >> value;
            head.insertAtStart(value);
        } else if (choice == 2) {
            cout << "Enter value to insert at the end: ";
            cin >> value;
            head.insertAtEnd(value);
        } else if (choice == 3) {
            cout << "Enter value to delete: ";
            cin >> value;
            head.deleteNode(value);
        } else if (choice == 4) {
            cout << "Doubly Linked List: ";
            head.displayList();
        } else if (choice == 5) {
            return 0;
        } else {
            continue;
        }
    }
}