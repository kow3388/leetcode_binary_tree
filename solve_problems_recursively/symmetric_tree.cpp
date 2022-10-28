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

bool isS(TreeNode *l, TreeNode *r)
{
    if(!l and !r)
        return true;
    
    if(!l or !r)
        return false;
    
    if(l->val != r->val)
        return false;
    
    return isS(l->left, r->right) and isS(l->right, r->left);
}

bool isSymmetric(TreeNode *root)
{
    return isS(root->left, root->right);
}

int main()
{
    TreeNode *root = NULL;

    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    bool ans = isSymmetric(root);
    
    cout << ans << endl;

    return 0;
}