#include<bits/stdc++.h>
using namespace std;
/*
   Problem: Given root of a Binary Search Tree (BST), modify the tree such that every node stores the sum of its original value and
   all node values greater than it in the BST. Return the root of the modified BST.

   Input: root[] = [50, 30, 70, 20, 40, 60, 80]
   Output: [260, 330, 150, 350, 300, 210, 80]

   Input: root[] = [2, 1, 5, N, N, 4, 7]
   Output: [18, 19, 12, N, N, 16, 7]
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
   int right = 0;
   int solve(Node* root)
   {
      if(!root) return 0;
      right = max(right, solve(root->right));
      root->data = root->data + right;
      right = max(right, root->data);
      int left = solve(root->left);
      return right;
   }
   // Clean and Standard version
   int sum = 0;
   void solveCleanVersion(Node* root)
   {
      if(!root) return;

      solve(root->right);

      int org = root->data;
      root->data += sum;
      sum += org;

      solve(root->left);
   }
  public:
    Node *transformTree(Node *root) {
        solve(root);
        right = 0;
        return root;
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
   root = s.transformTree(root);
   bst.printTree(root);
}
/*
15
50
30 70
20 40 60 80
-1 -1 -1 -1 -1 -1 -1 -1

11
2
1 5
-1 -1 4 7
-1 -1 -1 -1
*/
