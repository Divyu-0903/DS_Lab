#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

TreeNode* createBinaryTree() {
    int data;
    cout << "Enter node data (Enter -1 for NULL): ";
    cin >> data;

    if (data == -1) {
        return NULL;
    }

    TreeNode* newNode = new TreeNode(data);

    cout << "Enter left child of " << data << ": ";
    newNode->left = createBinaryTree();

    cout << "Enter right child of " << data << ": ";
    newNode->right = createBinaryTree();

    return newNode;
}

void inorderTraversal(TreeNode* root) {
    if (root) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    cout << "Create a Binary Tree using NULL (Enter -1 for NULL):\n";
    TreeNode* root = createBinaryTree();

    cout << "Inorder Traversal of the Binary Tree: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
