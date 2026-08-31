#include<bits/stdc++.h>
using namespace std;
/*
   Problem: Given the root of a binary tree, reverse the values of nodes at every alternate level from left to right, while keeping the tree
   structure unchanged. Only the node values may be modified.

   Note: The root node is considered to be at level 0. Therefore, values at levels 1, 3, 5, ... are reversed.

   Input: root[] = [1, 2, 3, 42, 51, 63, 72]
   Output: 1 3 2 42 51 63 72

   Input: root[] = [1, 2, N, 3, 4, 5, N, N, 6]
   Output: 1 2 3 4 6 5
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
      queue<Node*> q;
      Node* root = new Node(arr[0]);
      int ind = 1;
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
   }
};
class Solution {
  public:
    void alternateReverse(Node* root) {
        queue<Node*> q;
        q.push(root);
        int level = 0;

        while(!q.empty())
        {
           int sz = (int)q.size();
           vector<Node*> nodes;
           vector<int> values;
           for(int i=0;i<sz;i++)
           {
              Node* curr = q.front();
              q.pop();

              if(curr->left)
              {
                 q.push(curr->left);
                 if(level%2 == 0)
                 {
                    nodes.push_back(curr->left);
                    values.push_back(curr->left->data);
                 }
              }
              if(curr->right)
              {
                 q.push(curr->right);
                 if(level%2 == 0)
                 {
                    nodes.push_back(curr->right);
                    values.push_back(curr->right->data);
                 }
              }
           }
           if(nodes.size() > 0)
           {
              reverse(values.begin(), values.end());
              for(int i=0;i<nodes.size();i++)
              {
                 Node* curr = nodes[i];
                 curr->data = values[i];
              }
           }
           level++;
        }
        return;
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
   Solution s;
   s.alternateReverse(root);
   bt.printTree(root);
}
/*
15
1 2 3 42 51 63 72 -1 -1 -1 -1 -1 -1 -1 -1

9
1 2 -1 3 4 5 -1 -1 6
*/
