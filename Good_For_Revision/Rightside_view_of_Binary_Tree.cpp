#include<bits/stdc++.h>
using namespace std;
/*
    Problem: Given the root of a binary Tree. Return the right view of the binary tree. The right
    view of a Binary Tree is the set of nodes visible when the tree is viewed from the right side.

    Input: root = [1, 2, 3, N, N, 4, 5]
    Output: [1, 3, 5]

    Input: root = [1, 2, 3, 4, N, N, N, N, 5]
    Output: [1, 3, 4, 5]
*/
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
class BTree {
    public:

    Node* buildTree(vector<int> &arr)
    {
        int n = (int)arr.size();
        Node* root = new Node(arr[0]);
        queue<Node*> q;
        q.push(root);
        int ind = 1;
        while(!q.empty())
        {
            int sz = (int)q.size();
            for(int i=0;i<sz;i++)
            {
                Node* curr = q.front();
                q.pop();

                if(ind < n)
                {
                    if(arr[ind] != -1)
                    {
                        Node* n = new Node(arr[ind]);
                        curr->left = n;
                        q.push(curr->left);
                    }
                    ind++;
                }
                if(ind < n)
                {
                    if(arr[ind] != -1)
                    {
                        Node* n = new Node(arr[ind]);
                        curr->right = n;
                        q.push(curr->right);
                    }
                    ind++;
                }
            }
        }
        return root;
    }
    void printTree(Node* root)
    {
        if(!root) return;
        printTree(root->left);
        cout<<root->data<<" ";
        printTree(root->right);
    }
};
class Solution {
  public:
    vector<int> rightView(Node *root) {
        vector<int> ans;
        queue<Node*> q;
        q.push(root);
        ans.push_back(root->data);
        
        while(!q.empty())
        {
            int sz = (int)q.size();
            int rightMost = -1;
            for(int i=0;i<sz;i++)
            {
                Node* curr = q.front();
                q.pop();
                if(curr->left)
                {
                    q.push(curr->left);
                    rightMost = curr->left->data;
                }
                if(curr->right)
                {
                    q.push(curr->right);
                    rightMost = curr->right->data;
                }
            }
            if(rightMost != -1) ans.push_back(rightMost);
        }

        return ans;
    }
};
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    BTree bt;
    Node* root = bt.buildTree(arr);
    //bt.printTree(root);
    Solution s;
    vector<int> ans = s.rightView(root);
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    cout<<endl;
}
/*
11
1 2 3 -1 -1 4 5 -1 -1 -1 -1

9
1 2 3 4 -1 -1 -1 -1 5
*/