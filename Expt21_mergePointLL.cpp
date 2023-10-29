#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int findLength(Node* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

Node* findMergePoint(Node* head1, Node* head2) {
    Node* temp1 = head1;
    Node* temp2 = head2;

    while (temp1 != NULL) {
        temp2 = head2;
        while (temp2 != NULL) {
            if (temp1->data == temp2->data) {
                return temp1;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }

    return NULL;
}

Node* createLinkedList(int n) {
    Node* head = NULL;
    Node* current = NULL;

    for (int i = 0; i < n; i++) {
        int data;
        cout << "Enter data for node " << i + 1 << ": ";
        cin >> data;

        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            current = head;
        } else {
            current->next = newNode;
            current = newNode;
        }
    }

    return head;
}

int main() {
    int n1, n2;
    cout << "Enter the number of nodes for Linked List 1: ";
    cin >> n1;
    Node* head1 = createLinkedList(n1);

    cout << "Enter the number of nodes for Linked List 2: ";
    cin >> n2;
    Node* head2 = createLinkedList(n2);

    Node* mergePoint = findMergePoint(head1, head2);

    if (mergePoint != NULL) {
        cout << "Merge Point Value: " << mergePoint->data << endl;
    } else {
        cout << "No merge point found." << endl;
    }

    return 0;
}