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
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    vector<vector<int>> ans = levelOrder(root);

    for(int i = 0; i < ans.size(); i++)
    {
        for(const auto &a : ans[i])
            cout << a << " ";
        cout << endl;
    }

    return 0;
}