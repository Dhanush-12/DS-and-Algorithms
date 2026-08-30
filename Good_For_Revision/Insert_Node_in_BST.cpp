#include<bits/stdc++.h>
using namespace std;
/*
    Problem: Given the root of a Binary Search Tree (BST) and an integer key, insert a new node with value key into the BST. Return
    the root of the modified tree after the insertion.

    Note: All the nodes have distinct values in the BST and the new value to be inserted is not present in the BST.

    Input: root = [2, 1, 3], key = 4
    Output: [2, 1, 3, N, N, N, 4]
    Explanation: After inserting the node 4, the new tree will be [2, 1, 3, N, N, N, 4].
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
class BSTree {
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
    Node* insert(Node* root, int key) {
        Node* curr = root;
        Node* n = new Node(key);
        Node* prev = root;

        while(curr)
        {
           prev = curr;
           if(key > curr->data) curr = curr->right;
           else curr = curr->left;
        }
        if(prev->data > key) prev->left = n;
        else prev->right = n;
        return root;
    }
};
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int key;
    cin>>key;
    BSTree bst;
    Node* root = bst.buildTree(arr);
    Solution s;
    root = s.insert(root, key);
    bst.printTree(root);
}
/*
11
6 5 34 -1 -1 18 38 -1 -1 35 -1
8
*/
