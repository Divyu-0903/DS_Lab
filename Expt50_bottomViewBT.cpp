#include <iostream>
#include <map>
#include <queue>
#include <utility>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

void bottomView(TreeNode* root) {
    if (!root) {
        return;
    }

    map<int, int> verticalDistanceMap;
    queue< pair<TreeNode*, int> > q;

    q.push(make_pair(root, 0));

    while (!q.empty()) {
        TreeNode* node = q.front().first;
        int horizontalDistance = q.front().second;
        q.pop();

        verticalDistanceMap[horizontalDistance] = node->data;

        if (node->left) {
            q.push(make_pair(node->left, horizontalDistance - 1));
        }

        if (node->right) {
            q.push(make_pair(node->right, horizontalDistance + 1));
        }
    }

    for (map<int, int>::iterator it = verticalDistanceMap.begin(); it != verticalDistanceMap.end(); ++it) {
        cout << it->second << " ";
    }
    cout << endl;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    cout<<"Bottom view of binary tree is : "<<endl;
    bottomView(root);

    return 0;
}