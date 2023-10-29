#include <iostream>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;
    ListNode(int x) : data(x), next(NULL) {}
};

ListNode* detectCycle(ListNode* head) {
    if (!head) {
        return NULL;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return slow;
        }
    }

    return NULL;
}

void removeCycle(ListNode* head, ListNode* cycleNode) {
    if (!head || !cycleNode) {
        return;
    }

    ListNode* ptr1 = head;
    ListNode* ptr2 = cycleNode;

    while (ptr1->next != ptr2->next) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    ptr2->next = NULL;
}

void displayList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = NULL;
    ListNode* tail = NULL;

    int n, data;
    cout << "Enter the number of nodes in the linked list: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter data for node " << i + 1 << ": ";
        cin >> data;
        if (!head) {
            head = tail = new ListNode(data);
        } else {
            tail->next = new ListNode(data);
            tail = tail->next;
        }
    }

    if (n > 1) {
        tail->next = head->next;
    }

    ListNode* cycleNode = detectCycle(head);

    if (cycleNode) {
        cout << "Cycle detected at node with value " << cycleNode->data << endl;
        removeCycle(head, cycleNode);
        cout << "Cycle removed." << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    cout << "Linked List after removing the cycle:" << endl;
    displayList(head);
    return 0;
}
