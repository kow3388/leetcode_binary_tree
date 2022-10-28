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

bool postorder(TreeNode *root, int &num)
{
    if(!root)
        return false;
    
    if(!root->left and !root->right)
    {
        num++;
        return true;
    }
    else if(!root->left and root->right)
    {
        if(postorder(root->right, num) and root->val == root->right->val)
        {
            num++;
            return true;
        }
        return false;
    }
    else if(root->left and !root->right)
    {
        if(postorder(root->left, num) and root->val == root->left->val)
        {
            num++;
            return true;
        }
        return false;
    }
    else
    {
        bool l = postorder(root->left, num);
        bool r = postorder(root->right, num);
        if(l and r and root->val == root->left->val and root->val == root->right->val)
        {
            num++;
            return true;
        }
        return false;
    }
}

int countUnivalSubtrees(TreeNode *root)
{
    int num = 0;
    postorder(root, num);

    return num;
}

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(5);
    int ans = countUnivalSubtrees(root);

    cout << ans << endl;

    return 0;
}