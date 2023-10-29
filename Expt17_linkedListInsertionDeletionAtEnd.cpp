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

void displayList(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

Node* insertAtEnd(Node* head, int value) {
    Node* new_node = new Node(value);

    if (head == NULL) {
        return new_node;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new_node;
    return head;
}

Node* deleteFromEnd(Node* head) {
    if (head == NULL) {
        cout << "Empty List!" << endl;
        return NULL;
    }

    if (head->next == NULL) {
        delete head;
        return NULL;
    }

    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
    return head;
}

int main() {
    Node* head = NULL;

    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 3);
    cout << "Inserted at end: ";
    displayList(head);

    head = deleteFromEnd(head);
    cout << "Deleted from end: ";
    displayList(head);
}
