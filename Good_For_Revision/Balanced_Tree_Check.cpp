#include<bits/stdc++.h>
using namespace std;
/*
   Problem: Given the root of a binary tree, determine if it is height-balanced or not.

   Note: A binary tree is considered height-balanced if the absolute difference in heights of the left and right subtrees is at most
   1 for every node in the tree.

   Input: root = [10, 20, 30, 40, 60]
   Output: true

   Input: root = [1, 2, 3, 4, N, N, N, 5]
   Output: false
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
   bool ok;
   int solve(Node* root)
   {
      if(!root) return 0;

      if(!ok) return 0;

      int left = solve(root->left);
      int right = solve(root->right);

      if(abs(left-right) > 1)
      {
         ok = false;
         return 0;
      }
      return 1 + max(left, right);
   }
   // More cleaner version
   int solveClean(Node* root)
   {
      if(!root) return 0;

      int left = solveClean(root->left);
      if(left == -1) return -1;

      int right = solveClean(root->right);
      if(right == -1) return -1;

      if(abs(left-right) > 1) return -1;

      return 1 + max(left, right);
   }
  public:
    bool isBalanced(Node* root) {
        //ok = true;
        //solve(root);
        //return ok;

        return solveClean(root) != -1;
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
   cout<<s.isBalanced(root)<<endl;
}
/*
7
10
20 30
40 60 -1 -1

9
1
2 3
4 -1 -1 -1
5 -1
*/
