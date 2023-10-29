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

Node* insertAtStart(Node* head, int value) {
    Node* new_node = new Node(value);
    new_node->next = head;
    return new_node;
}

Node* deleteFromStart(Node* head) {
    if (head == NULL) {
        cout << "Empty List!" << endl;
        return NULL;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

int main() {
    Node* head = NULL;

    head = insertAtStart(head, 3);
    head = insertAtStart(head, 2);
    head = insertAtStart(head, 1);
    cout << "Inserted at beginning: ";
    displayList(head);

    head = deleteFromStart(head);
    cout << "Deleted from beginning: ";
    displayList(head);
}