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
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

Node* removeNthFromEnd(Node* head, int n) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }

    int len = 0;
    Node* temp = head;
    while (temp != NULL) {
        temp = temp->next;
        len++;
    }

    if (n == len) {
        Node* new_head = head->next;
        delete head;
        return new_head;
    }

    temp = head;
    int count = 1;
    while (count < (len - n)) {
        temp = temp->next;
        count++;
    }

    Node* to_delete = temp->next;
    temp->next = to_delete->next;
    delete to_delete;

    return head;
}

int main() {
    int n;
    cout << "Enter the number of elements in the linked list: ";
    cin >> n;

    Node* head = NULL;

    for (int i = 0; i < n; i++) {
        int value;
        cout << "Enter element " << i + 1 << ": ";
        cin >> value;
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    cout << "Linked List: ";
    displayList(head);

    int N;
    cout << "Enter the value of N to remove from the end: ";
    cin >> N;

    head = removeNthFromEnd(head, N);

    Node* current = head;
    cout << "Updated Linked List: ";
    while (current != NULL) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}