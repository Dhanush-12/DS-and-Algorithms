#include<bits/stdc++.h>
using namespace std;
/*
   Problem: Given the root of a binary tree, find the maximum difference between an ancestor node A and its
   descendant node B, i.e., maximize A - B.
   
   Input: root[] = [5, 2, 1] 
   Output: 4
   
   Input: root[] = [1, 2, 3, N, N, N, 7]
   Output: -1
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
      int ind = 1;
      queue<Node*> q;
      Node* root = new Node(arr[0]);
      q.push(root);

      while(!q.empty())
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
      return root;
   }
   void printTree(Node* root)
   {
      if(!root) return;

      printTree(root->left);
      cout<<root->data<<" ";
      printTree(root->right);

      return;
   }
};
class Solution {
    int solve(Node* root, Node* anc)
    {
        if(!root) return INT_MIN;

        int ans = INT_MIN;
        if(anc != root) ans = anc->data-root->data;

        if(root->data > anc->data) anc = root;

        int left = solve(root->left, anc);
        int right = solve(root->right, anc);

        return max({ans, left, right});
    }
  public:
    int maxDiff(Node* root) {
        return solve(root, root);
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
   bt.printTree(root);
}
/*
7
5 2 1 -1 -1 -1 -1

9
1 2 3 -1 -1 -1 7 -1 -1
*/
