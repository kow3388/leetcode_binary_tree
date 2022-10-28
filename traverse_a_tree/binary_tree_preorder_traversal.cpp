#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void preorder(TreeNode *root, vector<int> &DLR)
{
    if(!root)
        return;
    
    DLR.push_back(root->val);
    preorder(root->left, DLR);
    preorder(root->right, DLR);
}

vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> DLR;
    preorder(root, DLR);

    return DLR;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    vector<int> ans = preorderTraversal(root);

    for(const auto &a : ans)
        cout << a << endl;
    
    return 0;
}