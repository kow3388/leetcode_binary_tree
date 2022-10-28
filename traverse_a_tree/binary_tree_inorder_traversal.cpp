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

void inorder(TreeNode *root, vector<int> &LDR)
{
    if(!root)
        return;
    
    inorder(root->left, LDR);
    LDR.push_back(root->val);
    inorder(root->right, LDR);
}

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> LDR;
    inorder(root, LDR);

    return LDR;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    vector<int> ans = inorderTraversal(root);

    for(const auto &a : ans)
        cout << a << endl;
    
    return 0;
}