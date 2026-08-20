#include<bits/stdc++.h>
using namespace std;
/*
Problem : Given a binary tree with n nodes and two node values a and b, find the minimum distance between them. The distance is
defined as the minimum number of edges between the two nodes. It is guaranteed that both nodes exist in the binary tree and all node values
are unique.

Input: a = 2, b = 3
Output: 2

Input: a = 4, b = 7
Output: 4
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
    Node* buildTree(vector<int> &arr) {
        int n = (int)arr.size();
        queue<Node*> q;
        Node* root = new Node(arr[0]);
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
    void printTree(Node* root) {
        if(!root) return;

        queue<Node*> q;
        q.push(root);

        while(!q.empty())
        {
            int sz = (int)q.size();
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
        return;
    }
};
class Solution {
  public:
    int findDist(Node* root, int a, int b) {
        if(a == b) return 0;

        unordered_map<int,int>parent;
        queue<Node*> q;
        q.push(root);
        parent[root->data] = -1;
        while(!q.empty())
        {
            int sz = (int)q.size();
            for(int i=0;i<sz;i++)
            {
                Node* curr = q.front();
                q.pop();

                if(curr->left)
                {
                    parent[curr->left->data] = curr->data;
                    q.push(curr->left);
                }
                if(curr->right)
                {
                    parent[curr->right->data] = curr->data;
                    q.push(curr->right);
                }
            }
        }
        unordered_map<int,int>mp;
        int curr = a;
        int dis = 0;
        while(curr != -1)
        {
            mp[curr] = dis;
            dis++;
            curr = parent[curr];
        }

        curr = b;
        dis= 0;
        while(curr != -1)
        {
            if(mp.find(curr) != mp.end())
            {
                return mp[curr]+dis;
            }

            curr = parent[curr];
            dis++;
        }
        return -1;
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
    //bt.printTree(root);

    Solution s;
    cout<<s.findDist(root, a, b)<<endl;

}
/*
7 4 7
1 2 3 4 5 6 7
*/
