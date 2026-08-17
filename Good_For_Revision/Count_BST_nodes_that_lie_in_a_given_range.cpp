#include<bits/stdc++.h>
using namespace std;
/*
Given a Binary Search Tree (BST) and a range l-h (inclusive), your task is to return the number
of nodes in the BST whose value lie in the given range.

Examples :

Input: root[] = [10, 5, 50, 1, N, 40, 100], l = 5, h = 45 Answer: 3
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
    void getSortedValues(Node* root, vector<int> &arr)
    {
        if(!root) return;
        getSortedValues(root->left, arr);
        arr.push_back(root->data);
        getSortedValues(root->right, arr);
        return;
    }
  public:
    // Good Solution but extra space
    // Time Complexity: O(n) n is number of nodes
    // Space Complexity: O(n) " " "
    int getCount(Node *root, int l, int h) {
        vector<int> values;
        getSortedValues(root, values);
        int lInd = lower_bound(values.begin(), values.end(), l)-values.begin();
        int rInd = upper_bound(values.begin(), values.end(), h)-values.begin();

        return rInd-lInd;
    }

    // Better solution as Tree is already a Binary Search Tree
    int getCount(Node *root, int l, int h) {
        if(!root) return 0;

        if(root->data < l) return getCount(root->right, l, h);
        if(root->data > h) return getCount(root->left, l, h);

        return 1+getCount(root->left, l, h)+getCount(root->right, l, h);
    }

    // Simpler to understand stack version
    int getCount(Node* root, int l, int r)
    {
        stack<Node*> st;
        Node* curr = root;
        int ans = 0;

        while(curr || !st.empty())
        {
            while(curr)
            {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();

            if(curr->data >= l && curr->data <= r)
            {
                ans++;
            }

            if(curr->data > r) break;
            curr = curr->right;
        }
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
    //bt.printTree(root);

    Solution s;
    cout<<s.getCount(root, l, h)<<endl;
    return 0;
};
/*
10 5 50 1 N 40 100
l = 10, h = 100

Ans: 4
*/
