#include<bits/stdc++.h>
using namespace std;
/*
   Problem: Given a Binary Tree, find the maximum width of it. Maximum width is defined as the maximum number of
   nodes at any level.

   Input: root = [1, 2, 3, 4, 5, 6, 7]
   Output: 4

   Input: root = [10, 20, 30, 40, 60]
   Output: 2
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
    int maxWidth(Node* root) {
        int ans = 0;
        queue<Node*> q;
        q.push(root);

        while(!q.empty())
        {
           int sz = (int)q.size();
           ans = max(ans, sz);

           for(int i=0;i<sz;i++)
           {
              Node* curr = q.front();
              q.pop();

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
   cout<<s.maxWidth(root)<<endl;
}
/*
15
1
2 3
4 5 6 7
-1 -1 -1 -1 -1 -1 -1 -1

7
10
20 30
40 60 -1 -1
*/
