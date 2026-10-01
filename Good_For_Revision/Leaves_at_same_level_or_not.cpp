#include <bits/stdc++.h>
#define ll long long
using namespace std;
/*
    Problem: Given the root of a binary tree, find if all its leaf nodes are present at the same level or not.

    Examples :

    Input: root = [12, 5, 7, 3, N, N, 1]
    Output: true
    Explanation: The tree has two leaf nodes: 1 and 3. Both leaf nodes are present at the same level, so the output is true. 

    Input: root = [12, 5, 7, 3, N]
    Output: false
    Explanation: The leaf nodes are 3 and 7. Node 3 is at a deeper level than node 7, so all leaf nodes are not at the same level.

    Input: root = [3]

    Output: true
    Explanation: There is only one leaf node, so all leaf nodes are at the same level.
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
    bool checkHelper(Node* root, int curr, int &level)
    {
        if(!root) return true;
        
        if(!root->left && !root->right)
        {
            if(level == -1) level = curr;
            else return level == curr;
        }
        
        return checkHelper(root->left, curr+1, level) && checkHelper(root->right, curr+1, level);
    }
  public:
    bool check(Node* root) {
        int level = -1;
        int curr = 0;
        return checkHelper(root, curr, level);
    }
};
int main() 
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    BSTree bt;
    Node* root = bt.buildTree(a);

    Solution s;
    cout<<s.check(root)<<endl;
}
/*
11
12 5 7 3 -1 -1 1 -1 -1 -1 -1

7
12 5 7 3 -1 -1 -1
*/