#include<bits/stdc++.h>
using namespace std;
/*
   Problem: Given the root of a Binary Tree, find the vertical traversal of the tree starting from the leftmost level to the rightmost level.

    Note: If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.

    Input: root = [1, 2, 3, 4, 5, 6, 7, N, N, N, 8, N, 9, N, 10, 11, N]
    Output: [[4], [2], [1, 5, 6, 11], [3, 8, 9], [7], [10]]

    Input: root = [1, 2, 3, 4, 5, N, 6]
    Output: [[4], [2], [1, 5], [3], [6]]
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
    vector<vector<int>> verticalOrder(Node *root) {
        map<int, vector<int>> mp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        mp[0].push_back(root->data);

        while(!q.empty())
        {
            Node* curr = q.front().first;
            int line = q.front().second;
            q.pop();

            if(curr->left)
            {
                q.push({curr->left, line-1});
                mp[line-1].push_back(curr->left->data);
            }
            if(curr->right)
            {
                q.push({curr->right, line+1});
                mp[line+1].push_back(curr->right->data);
            }
        }

        vector<vector<int>> ans;

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
   vector<vector<int>> ans = s.verticalOrder(root);
   for(int i=0;i<ans.size();i++)
   {
        for(int a : ans[i])
        {
            cout<<a<<" ";
        }
        cout<<endl;
   }
}
