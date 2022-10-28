#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node* connect(Node *root)
{
    if(!root)
        return nullptr;
    
    queue<Node*> bfs;
    bfs.push(root);

    while(!bfs.empty())
    {
        int s = bfs.size();
        while(s-- > 0)
        {
            Node *curr = bfs.front();
            bfs.pop();
            Node *tmp = bfs.front();

            if(curr->left)
                bfs.push(curr->left);
            if(curr->right)
                bfs.push(curr->right);
                
            if(s == 0)
                curr->next = nullptr;
            else
                curr->next = tmp;
        }
    }

    return root;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(7);

    Node *ans = connect(root);
    while(ans)
    {
        Node *tmp = ans;
        while(tmp->next)
        {
            cout << tmp->val << " ";
            tmp = tmp->next;
        }
        cout << tmp->val << endl;
        ans = ans->left;
    }

    return 0;
}