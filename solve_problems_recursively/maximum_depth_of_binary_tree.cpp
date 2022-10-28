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

int maxDepth(TreeNode *root)
{
    if(!root)
        return 0;
    
    int l = 0, r = 0;
    if(!root->left and !root->right)
        return 1;
    
    l += maxDepth(root->left) + 1;
    r += maxDepth(root->right) + 1;

    return max(l, r);
}

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    int ans = maxDepth(root);

    cout << ans << endl;

    return 0;
}