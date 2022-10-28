#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

TreeNode* lca(TreeNode *root, int start, int dest)
{
    if(!root)
        return root;
    if(root->val == start or root->val == dest)
        return root;

    TreeNode *l = lca(root->left, start, dest);
    TreeNode *r = lca(root->right, start, dest);

    if(l and r)
        return root;
    return l? l : r;
}

bool path(TreeNode *root, int value, string &p)
{
    if(!root)
        return false;
    if(root->val == value)
        return true;
    
    p.push_back('L');
    bool res = path(root->left, value, p);

    if(res)
        return true;
    
    p.pop_back();
    p.push_back('R');

    res = path(root->right, value, p);
    
    if(res)
        return true;
    
    p.pop_back();

    return false;
}

string getDirections(TreeNode *root, int startValue, int destValue)
{
    TreeNode *common = lca(root, startValue, destValue);
    string p1, p2;

    path(common, startValue, p1);
    path(common, destValue, p2);

    for(auto &s : p1)
        s = 'U';
    
    return p1+p2;
}

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    string s = getDirections(root, 8, 2);

    cout << s << endl;

    return 0;
}