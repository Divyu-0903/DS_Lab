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

TreeNode *buildTreeFromPostorder(vector<int> &postorder, int &index, int minValue)
{
    if (index < 0 || postorder[index] <= minValue)
    {
        return NULL;
    }

    TreeNode *root = new TreeNode(postorder[index--]);
    root->right = buildTreeFromPostorder(postorder, index, root->val);
    root->left = buildTreeFromPostorder(postorder, index, minValue);
    return root;
}

void preorderTraversal(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->val << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main()
{
    int n;
    cin>>n;
    vector<int> postorder(n);
    for(int i=0;i<n;i++){
        cin>>postorder[i];
    }
    int index = n-1;

    TreeNode *root = buildTreeFromPostorder(postorder, index, INT_MIN);

    preorderTraversal(root);
    cout << endl;

    return 0;
}