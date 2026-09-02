#include<bits/stdc++.h>
using namespace std;
/*
   Problem: Given an array parent[] where each index represents a node and parent[i] gives the parent’s index, with -1 indicating the
   root. Your task is to construct the binary tree in standard linked-node form (each node having left and right pointers) based on
   this parent–child relationship and return the root node.

   Note: If two elements have the same parent, the one that appears first in the array will be the left child and the other is the
   right child. You don't need to print anything, the driver code will print the level order traversal of the returned root node to
   verify the output.

   Input: parent[] = [-1, 0, 0, 1, 1, 3, 5]
   Output: [0, 1, 2, 3, 4, N, N, 5, N, N, N, 6]

   Input: parent[] = [2, 0, -1]
   Output: [2, 0, N, 1]
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
   public:
   void printTree(Node* root)
   {
      if(!root) return;
      printTree(root->left);
      cout<<root->data<<" ";
      printTree(root->right);

      return;
   }
    Node* createTree(vector<int>& parent) {
        unordered_map<int, Node*> mp;
        Node* root;
        for(int i=0;i<parent.size();i++)
        {
            Node* child = NULL;
            if(mp.find(i) != mp.end()) child = mp[i];
            else
            {
                child = new Node(i);
                mp[i] = child;
            }

            Node* par = NULL;
            if(parent[i] == -1)
            {
                root = child;
                continue;
            }
            if(mp.find(parent[i]) != mp.end()) par = mp[parent[i]];
            else
            {
                par = new Node(parent[i]);
                mp[parent[i]] = par;
            }

            if(par->left == NULL) par->left = child;
            else par->right = child;
        }
        return root;
    }
};
int main()
{
   int n;
   cin>>n;
   vector<int> arr(n);
   for(int i=0;i<n;i++) cin>>arr[i];
   Solution s;
   Node* root = s.createTree(arr);
   s.printTree(root);
}
/*
7
-1 0 0 1 1 3 5

3
2 0 -1
*/
