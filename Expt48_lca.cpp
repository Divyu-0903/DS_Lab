#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

Node* lca(Node* root, int n1, int n2) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data == n1 || root->data == n2) {
        return root;
    }

    Node* left = lca(root->left, n1, n2);
    Node* right = lca(root->right, n1, n2);

    if (left == NULL && right == NULL) {
        return NULL;
    }

    if (left == NULL && right != NULL) {
        return right;
    }

    if (right == NULL && left != NULL) {
        return left;
    }

    return root;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int n1 = 4, n2 = 5;

    Node* lowestCommonAncestor = lca(root, n1, n2);

    cout << "Lowest Common Ancestor of " << n1 << " and " << n2 << " is: " << lowestCommonAncestor->data << endl;

    return 0;
}