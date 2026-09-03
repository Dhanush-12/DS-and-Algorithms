#include<bits/stdc++.h>
using namespace std;
/*
   Problem: You are given the root of a binary tree, and your task is to return its bottom view. The bottom view of
   a binary tree is the set of nodes visible when the tree is viewed from the bottom.

   Note: If there are multiple bottom-most nodes for a horizontal distance from the root, then the latter one in the
   level order traversal is considered.

   Input: root = [1, 2, 3, 4, 5, N, 6]
   Output: [4, 2, 5, 3, 6]

   Input: root = [20, 8, 22, 5, 3, 4, 25, N, N, 10, 14, N, N, 28, N]
   Output: [5, 10, 4, 28, 25]
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
      int ind = 1;
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
      if(!root) return;
      printTree(root->left);
      cout<<root->data<<" ";
      printTree(root->right);
   }
};
class Solution {
  public:
    vector<int> bottomView(Node *root) {
        vector<int> ans;
        map<int, int> mp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        mp[0] = root->data;

        while(!q.empty())
        {
           int sz = (int)q.size();
           for(int i=0;i<sz;i++)
           {
              Node* curr = q.front().first;
              int col = q.front().second;
              q.pop();
              if(curr->left)
              {
                 q.push({curr->left, col-1});
                 mp[col-1] = curr->left->data;
              }
              if(curr->right)
              {
                 q.push({curr->right, col+1});
                 mp[col+1] = curr->right->data;
              }
           }
        }

        for(auto it : mp)
        {
           ans.push_back(it.second);
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
   BSTree bst;
   Solution s;
   Node* root = bst.buildTree(arr);
   vector<int> ans = s.bottomView(root);
   for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
   cout<<endl;
}
/*
7
1
2 3
4 5 -1 6

15
20
8 22
5 3 4 25
-1 -1 10 14 -1 -1 28 -1
*/
