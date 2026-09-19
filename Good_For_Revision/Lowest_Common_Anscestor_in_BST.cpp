#include<bits/stdc++.h>
using namespace std;
/*
    Problem: Given a Binary Search Tree (BST) with unique node values and two nodes n1 and n2 (n1 != n2), find their Lowest Common Ancestor (LCA).

    The Lowest Common Ancestor (LCA) of two nodes is defined as the deepest node in the tree that has both n1 and n2 as descendants, where a node can be a descendant of itself.

    Input: root = [5, 4, 6, 3, N, N, 7, N, N, N, 8], n1->data = 7, n2->data = 8
    Output: 7

    Input: root = [20, 8, 22, 4, 12, N, N, N, N, 10, 14], n1->data = 8, n2->data = 14
    Output: 8

    Input: root = [2, 1, 3], n1->data = 1, n2->data = 3
    Output: 2
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
    Node* findNode(int a, Node* root)
    {
        while(root->data != a && root)
        {
            if(root->data > a) root = root->left;
            else root = root->right;
        }
        return root;
    }
};
class Solution {
  public:
    Node* findLCA(Node* root, Node* n1, Node* n2) {
        unordered_set<Node*> visited;
        unordered_map<Node*,Node*> mp;
        mp[root] = NULL;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int sz = (int)q.size();
            for(int i=0;i<sz;i++)
            {
                Node* curr = q.front();
                q.pop();
                if(curr->left)
                {
                    q.push(curr->left);
                    mp[curr->left] = curr;
                }
                if(curr->right)
                {
                    q.push(curr->right);
                    mp[curr->right] = curr;
                }
            }
        }
        Node* curr = n1;
        while(curr != NULL)
        {
            visited.insert(curr);
            curr = mp[curr];
        }
        curr = n2;
        while(curr != NULL)
        {
            if(visited.count(curr)) return curr;
            curr = mp[curr];
        }
        return NULL;
    }
};
int main()
{
    int n, a, b;
    cin>>n>>a>>b;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    BTree bt;
    Node* root = bt.buildTree(arr);
    Node* n1 = bt.findNode(a, root);
    Node* n2 = bt.findNode(b, root);
    Solution s;
    Node* ans = s.findLCA(root, n1, n2);
    cout<<ans->data<<endl;
}
/*
13 7 8
5 4 6 3 -1 -1 7 -1 -1 -1 8 -1 -1

15 8 14
20 8 22 4 12 -1 -1 -1 -1 10 14 -1 -1 -1 -1

7 1 3
2 1 3 -1 -1 -1 -1
*/