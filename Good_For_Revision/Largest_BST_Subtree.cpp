#include<bits/stdc++.h>
using namespace std;
/*
    Problem: Given the root of a binary tree, find the size of the largest subtree that is also
    a Binary Search Tree (BST). A subtree is considered a BST if, for every node in the subtree:

    -> All nodes in its left subtree have values less than the node's value.
    -> All nodes in its right subtree have values greater than the node's value.
    -> The subtree contains no duplicate values.
    -> Return the number of nodes in the largest BST subtree.

    Note: The size of a subtree is the total number of nodes it contains.

    Input: root = [5, 2, 4, 1, 3]
    Output: 3

    Input: root = [6, 7, 3, N, 2, 2, 4]
    Output: 3
*/

// Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
    struct Info {
        int mn, mx;   // min and max value in this subtree
        int sz;       // size of this subtree (valid only if bst is true)
        bool bst;     // is this whole subtree a BST?
    };

    Info solve(Node* root, int &best)
    {
        // empty tree: a BST of size 0.
        // mn = INT_MAX and mx = INT_MIN so every comparison with the parent passes
        if (!root) return {INT_MAX, INT_MIN, 0, true};

        Info L = solve(root->left, best);
        Info R = solve(root->right, best);

        // this subtree is a BST only if both children are BSTs
        // AND the node sits strictly between them
        if (L.bst && R.bst && L.mx < root->data && root->data < R.mn)
        {
            int sz = L.sz + R.sz + 1;
            best = max(best, sz);               // record the largest seen so far
            return { min(L.mn, root->data),     // min can be root itself if left is empty
                    max(R.mx, root->data),      // max can be root itself if right is empty
                    sz, true };
        }

        // not a BST: parent can never use this subtree.
        // the answer for deeper BSTs was already recorded in `best`
        return {0, 0, 0, false};
    }
    // Another method without using custom data type
    int solve(Node* root, int &mn, int &mx, bool &isBST)
    {
        if(!root)
        {
            mn = INT_MAX;
            mx = INT_MIN;
            isBST = true;
            return 0;
        }
        
        int lmn, lmx, rmn, rmx;
        bool leftBST, rightBST;
        
        int leftSize = solve(root->left, lmn, lmx, leftBST);
        int rightSize = solve(root->right, rmn, rmx, rightBST);
        
        if(leftBST && rightBST && lmx < root->data && root->data < rmn)
        {
            isBST = true;
            
            mn = min(lmn, root->data);
            mx = max(rmx, root->data);
            
            return (leftSize + rightSize + 1);
        }
        
        isBST = false;
        
        mn = INT_MIN;
        mx = INT_MAX;
        
        return max(leftSize, rightSize);
    }
  public:
    int largestBst(Node *root) {
        int mn, mx;
        bool isBST;
        
        return solve(root, mn, mx, isBST);
    }
};
int main()
{
    // Driver Code
}