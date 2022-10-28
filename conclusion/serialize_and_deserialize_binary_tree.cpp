#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

//想法跟網路上一樣
//只是他們用stringstream
//比較可靠
class Codec
{
    public:
        string serialize(TreeNode *root)
        {
            ostringstream DLR;
            preorder(root, DLR);

            return DLR.str();
        }
        TreeNode* deserialize(string data)
        {
            istringstream dlr(data);

            return createtree(dlr);
        }

    private:
        void preorder(TreeNode *root, ostringstream &s)
        {
            if(root == NULL)
                s << "# ";
            else
            {
                s << root->val << " ";
                preorder(root->left, s);
                preorder(root->right, s);
            }
        }
        TreeNode* createtree(istringstream &s)
        {
            string tmp;
            s >> tmp;
            if(tmp == "#")
                return nullptr;
            else
            {
                TreeNode *root = new TreeNode(stoi(tmp));
                root->left = createtree(s);
                root->right = createtree(s);

                return root;
            }
        }
};