#include <bits/stdc++.h>
#define ll long long
using namespace std;
/*
    Problem: Given the roots of two binary trees, root1 and root2, determine whether the
    tree rooted at root2 is a subtree of the tree rooted at root1.

    Return true if there exists a node in the tree rooted at root1 such that the subtree
    rooted at that node is identical to the tree rooted at root2. Otherwise, return false.

    Note: Two binary trees are considered identical if they have the same structure and the
    same node values.

    Input: root1 = [1, 2, 3, N, N, 4], root2 = [3, 4]
    Output: true 

    Input: root1 = [26, 10, N, 20, 30, 40, 60], root2 = [26, 10, N, 20, 30, 40, 60]
    Output: true 
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
    bool isIdentical(Node* root1, Node* root2) {
        if(root1 == NULL && root2 == NULL) return true;
        if(root1 == NULL || root2 == NULL) return false;

        return (root1->data == root2->data) && isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right);
    }
    void serialize(Node* root, string &s) {
        if (!root) {
            s += "#,";
            return;
        }

        s += "V" + to_string(root->data) + ",";
        serialize(root->left, s);
        serialize(root->right, s);
    }
  public:
    bool isSubTree(Node *root1, Node *root2) {
        // if(!root2) return true;
        // if(!root1) return false;

        // if(isIdentical(root1, root2)) return true;
        // return isSubTree(root1->left, root2) || isSubTree(root1->right, root2);

        if(!root2) return true;
        if(!root1) return false;

        string s1, s2;
        serialize(root1, s1);
        serialize(root2, s2);

        return s1.find(s2) != string::npos;
    }
};
int main() 
{
    int n,m;
    cin>>n>>m;
    vector<int> a(n), b(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int j=0;j<m;j++) cin>>b[j];

    BSTree bt;
    Node* root1 = bt.buildTree(a);
    Node* root2 = bt.buildTree(b);

    Solution s;
    cout<<s.isSubTree(root1, root2)<<endl;
}
/*
9 5
1 2 3 -1 -1 4 -1 -1 -1
3 4 -1 -1 -1

13 13
26 10 -1 20 30 40 60 -1 -1 -1 -1 -1 -1
26 10 -1 20 30 40 60 -1 -1 -1 -1 -1 -1
*/