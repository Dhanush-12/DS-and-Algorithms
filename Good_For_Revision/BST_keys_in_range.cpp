#include<bits/stdc++.h>
using namespace std;
/*
    Problem: Given the root of a Binary Search Tree (BST) and two integers low and high, return
    all node values that lie in the inclusive range [low, high] in ascending order.

    Input: root = [17, 4, 18, 2, 9, N, N], l = 4, h = 17
    Output: [4, 9, 17]

    Input: root = [16, 7, 20, 1, 10, N, N], l = 13, h = 23
    Output: [16, 20]
*/
class Node {
public:
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
        int ind = 1;
        Node* root = new Node(arr[0]);
        queue<Node*> q;
        q.push(root);
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
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                Node* curr = q.front();
                q.pop();
                cout<<curr->data<<" ";
                if(curr->left)
                {
                    q.push(curr->left);
                }
                if(curr->right)
                {
                    q.push(curr->right);
                }
            }
        }
        cout<<endl;
        return;
    }
};
class Solution {
    void solve(Node* root, int low, int high, vector<int> &ans)
    {
        if(!root) return;
        
        solve(root->left, low, high, ans);
        if(root->data >= low && root->data <= high) ans.push_back(root->data);
        solve(root->right, low, high, ans);
        return;
    }
  public:
    vector<int> nodesInRange(Node *root, int low, int high) {
        vector<int> ans;
        solve(root, low, high, ans);
        return ans;
    }
};
int main()
{
    int n, l, h;
    cin>>n>>l>>h;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    BTree bt;
    Node* root = bt.buildTree(arr);
    Solution s;
    vector<int> ans = s.nodesInRange(root, l, h);
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    cout<<endl;
}