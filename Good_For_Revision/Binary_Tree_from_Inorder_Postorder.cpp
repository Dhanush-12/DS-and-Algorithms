#include<bits/stdc++.h>
using namespace std;
/*
   Problem: Given two arrays representing the inorder and postorder traversals of a binary tree, your task is to
   construct the binary tree and return its root.

   Note: The inorder and postorder traversals contain unique values, and every value present in the postorder
   traversal is also found in the inorder traversal.

   Input: inorder[] = [4, 8, 2, 5, 1, 6, 3, 7], postorder[] = [8, 4, 5, 2, 6, 7, 3, 1]
   Output: [1, 2, 3, 4, 5, 6, 7, N, 8]

   Input: inorder[] = [9, 5, 2, 3, 4], postorder[] = [5, 9, 3, 4, 2]
   Output: [2, 9, 4, N, 5, 3]
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
class Solution {
    Node* buildHelper(vector<int> &in, int is, int ie, vector<int> &post, int ps, int pe, map<int,int> &mp)
    {
        if(ps > pe || is > ie) return NULL;

        Node* root = new Node(post[pe]);

        int inRoot = mp[post[pe]];
        int numsLeft = inRoot - is;

        root->left = buildHelper(in, is, inRoot-1, post, ps, ps+numsLeft-1, mp);
        root->right = buildHelper(in, inRoot+1, ie, post, ps+numsLeft, pe-1, mp);

        return root;
    }
  public:
    Node *buildTree(vector<int> &inorder, vector<int> &postorder) {
       if(inorder.size() != postorder.size()) return NULL;

       map<int,int>mp;
       for(int i=0;i<inorder.size();i++) mp[inorder[i]] = i;
       
       return buildHelper(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, mp);
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
int main()
{
   int n;
   cin>>n;
   vector<int> in(n), post(n);
   for(int i=0;i<n;i++) cin>>in[i];
   for(int i=0;i<n;i++) cin>>post[i];
   Solution s;
   Node* root = s.buildTree(in, post);
   s.printTree(root);
}
/*
8
4 8 2 5 1 6 3 7
8 4 5 2 6 7 3 1

5
9 5 2 3 4
5 9 3 4 2

6
40 20 50 10 60 30
40 50 20 60 30 10
*/
