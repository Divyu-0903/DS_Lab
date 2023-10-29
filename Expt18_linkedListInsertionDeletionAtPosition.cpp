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

Node* insertAtPosition(Node* head, int value, int position) {
    Node* new_node = new Node(value);

    if (position == 1) {
        new_node->next = head;
        return new_node;
    }

    Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Invalid position" << endl;
        return head;
    }

    new_node->next = temp->next;
    temp->next = new_node;
    return head;
}

Node* deleteFromPosition(Node* head, int position) {
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        cout << "Invalid position" << endl;
        return head;
    }

    Node* node_to_delete = temp->next;
    temp->next = node_to_delete->next;
    delete node_to_delete;
    return head;
}

int main() {
    Node* head = NULL;

    head = insertAtPosition(head, 1, 1);
    head = insertAtPosition(head, 3, 2);
    head = insertAtPosition(head, 2, 2);
    head = insertAtPosition(head, 4, 4);
    cout << "Inserted at position: ";
    displayList(head);

    head = deleteFromPosition(head, 3);
    cout << "Deleted from position: ";
    displayList(head);
}