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

bool pathsum(TreeNode *root, int target, int &sum)
{
    if(!root)
        return false;
    
    sum += root->val;
    if(!root->left and !root->right)
    {
        if(sum == target)
            return true;
        else
            return false;
    }
    else
    {
        bool flag = false;
        if(root->left and !flag)
        {
            flag = pathsum(root->left, target, sum);
            sum -= root->left->val;
        }
        if(root->right and !flag)
        {
            flag = pathsum(root->right, target, sum);
            sum -= root->right->val;
        }

        return flag;
    }
}

bool hasPathSum(TreeNode *root, int targetSum)
{
    int sum = 0;
    return pathsum(root, targetSum, sum);
}

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);
    int target = 22;
    bool ans = hasPathSum(root, target);

    cout << ans << endl;

    return 0;
}