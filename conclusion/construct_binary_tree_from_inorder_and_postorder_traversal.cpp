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

TreeNode* construct(vector<int> &in, vector<int> &post,
                    int in_l, int in_r, int pos_l, int pos_r)
{
    if(in_l > in_r or pos_l > pos_r)
        return nullptr;
    
    //root
    TreeNode *node = new TreeNode(post[pos_r]);
    //find root in inorder
    int D = in_l;
    while(node->val != in[D])
        D++;
    
    int dis = D - in_l;
    node->left = construct(in, post, in_l, D-1, pos_l, pos_l+dis-1);
    node->right = construct(in, post, D+1, in_r, pos_l+dis, pos_r-1);

    return node;
}

//LDR, LRD
TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder)
{
    int in_n = inorder.size()-1;
    int post_n = postorder.size()-1;
    return construct(inorder, postorder, 0, in_n, 0, post_n);
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
    vector<int> post = {9,15,7,20,3};
    TreeNode *root = buildTree(in, post);

    vector<vector<int>> ans = levelOrder(root);
    for(int i = 0; i < ans.size(); i++)
    {
        for(const auto &a : ans[i])
            cout << a << " ";
        cout << endl;
    }

    return 0;
}