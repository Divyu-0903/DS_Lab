#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

Node* reverseList(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* reversed = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;

    return reversed;
}

void displayList(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements in the linked list: ";
    cin >> n;

    Node* head = NULL;

    for (int i = 0; i < n; i++) {
        int val;
        cout << "Enter element " << i + 1 << ": ";
        cin >> val;
        Node* newNode = new Node(val);

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

    cout << "Original Linked List: ";
    displayList(head);

    head = reverseList(head);

    cout << "Reversed Linked List: ";
    displayList(head);
}
