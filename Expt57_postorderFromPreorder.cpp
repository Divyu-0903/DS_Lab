#include<iostream>
#include<climits>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int value) : val(value), left(NULL), right(NULL) {}
};

TreeNode *buildTreeFromPreorder(vector<int> &preorder, int &index, int maxValue)
{
    if (index >= preorder.size() || preorder[index] >= maxValue)
    {
        return NULL;
    }

    TreeNode *root = new TreeNode(preorder[index++]);
    root->left = buildTreeFromPreorder(preorder, index, root->val);
    root->right = buildTreeFromPreorder(preorder, index, maxValue);
    return root;
}

void postorderTraversal(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->val << " ";
}

int main()
{
    int n;
    cin>>n;
    vector<int> preorder(n);
    for(int i=0;i<n;i++){
        cin>>preorder[i];
    }
    int index = 0;
    int maxValue = INT_MAX;

    TreeNode *root = buildTreeFromPreorder(preorder, index, maxValue);

    postorderTraversal(root);
    cout << endl;

    return 0;
}