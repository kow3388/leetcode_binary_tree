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

void postorder(TreeNode *root, vector<int> &LRD)
{
    if(!root)
        return;
    
    postorder(root->left, LRD);
    postorder(root->right, LRD);
    LRD.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> LRD;
    postorder(root, LRD);

    return LRD;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    vector<int> ans = postorderTraversal(root);

    for(const auto &a : ans)
        cout << a << endl;
    
    return 0;
}