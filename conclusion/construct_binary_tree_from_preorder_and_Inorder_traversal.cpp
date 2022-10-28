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

TreeNode* build(vector<int> &pre, vector<int> &in, int x, int y, int a, int b)
{
    if(x > y or a > b)
        return nullptr;

    TreeNode *root = new TreeNode(pre[x]);
    int D = a;
    while(root->val != in[D])
        D++;
    
    int dis = D - a;
    root->left = build(pre, in, x+1, x+dis, a, D-1);
    root->right = build(pre, in, x+dis+1, y, D+1, b);

    return root;
}

TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int in_n = inorder.size()-1;
    int pre_n = preorder.size()-1;

    return build(preorder, inorder, 0, pre_n, 0, in_n);
}

vector<vector<int>> levelOrder(TreeNode *root)
{
    if(!root)
        return {};

    queue<TreeNode*> bfs;
    vector<vector<int>> ans;

    bfs.push(root);

    while(!bfs.empty())
    {
        int s = bfs.size();
        vector<int> tmp;
        while(s-- > 0)
        {
            TreeNode *node = bfs.front();
            bfs.pop();
            if(node->left)
                bfs.push(node->left);
            if(node->right)
                bfs.push(node->right);
            
            tmp.push_back(node->val);
        }

        ans.push_back(tmp);
    }

    return ans;
}

int main()
{
    vector<int> in = {9,3,15,20,7};
    vector<int> pre = {3,9,20,15,7};
    TreeNode *root = buildTree(pre, in);

    vector<vector<int>> ans = levelOrder(root);
    for(int i = 0; i < ans.size(); i++)
    {
        for(const auto &a : ans[i])
            cout << a << " ";
        cout << endl;
    }

    return 0;
}