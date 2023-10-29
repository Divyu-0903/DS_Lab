#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

Node* mergeTwoLists(Node* list1, Node* list2) {
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }
    Node* h1 = list1;
    Node* h2 = list2;
    Node* final_head = NULL;
    Node* t = NULL;
    if (h1->data < h2->data) {
        final_head = h1;
        t = h1;
        h1 = h1->next;
    } else {
        final_head = h2;
        t = h2;
        h2 = h2->next;
    }
    while (h1 != NULL && h2 != NULL) {
        if (h2->data < h1->data) {
            t->next = h2;
            t = h2;
            h2 = h2->next;
        } else {
            t->next = h1;
            t = h1;
            h1 = h1->next;
        }
    }
    if (h2 == NULL) {
        t->next = h1;
    }
    if (h1 == NULL) {
        t->next = h2;
    }
    return final_head;
}

void displayList(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    int n1;
    cout << "Enter the number of elements for the first list: ";
    cin >> n1;

    Node* list1 = NULL;

    for (int i = 0; i < n1; i++) {
        int data;
        cout << "Enter element " << i + 1 << ": ";
        cin >> data;
        Node* newNode = new Node(data);
        if (list1 == NULL) {
            list1 = newNode;
        } else {
            Node* temp = list1;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    int n2;
    cout << "Enter the number of elements for the second list: ";
    cin >> n2;

    Node* list2 = NULL;

    for (int i = 0; i < n2; i++) {
        int data;
        cout << "Enter element " << i + 1 << ": ";
        cin >> data;
        Node* newNode = new Node(data);
        if (list2 == NULL) {
            list2 = newNode;
        } else {
            Node* temp = list2;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    cout << "First List: ";
    displayList(list1);

    cout << "Second List: ";
    displayList(list2);

    Node* mergedList = mergeTwoLists(list1, list2);

    cout << "Merged List: ";
    displayList(mergedList);

    return 0;
}
