#include<bits/stdc++.h>
using namespace std;
/*
    Problem: Given the root of a AVL Tree and an integer key, insert the key into the given AVL Tree such that the tree remains a valid AVL Tree after the insertion. The task is to return the root of the updated AVL Tree after inserting the given key. 

    Note:


    The given tree is initially a valid AVL Tree.
    The key does not already exist in the tree.
*/

// Structure of AVL Tree Node

class Node {
public:
    int key;
    int height;
    Node *left, *right;
    Node(int x) {
        key = x;
        height = 1;
        left = right = nullptr;
    }
};

class Solution {
    int getHeight(Node* n) { return n ? n->height : 0; }
    int getBalance(Node* n) { return n ? getHeight(n->left)-getHeight(n->right) : 0; }
    void updateHeight(Node* n) {
        n->height = 1 + max(getHeight(n->left), getHeight(n->right));
    }
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* B = x->right;

        x->right = y;
        y->left = B;

        updateHeight(y);
        updateHeight(x);

        return x;
    }
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* B = y->left;

        y->left = x;
        x->right = B;

        updateHeight(x);
        updateHeight(y);
        return y;
    }
  public:
    Node* insertToAVL(Node* root, int key) {
        if(!root) return new Node(key);
        if(key < root->key) root->left = insertToAVL(root->left, key);
        else root->right = insertToAVL(root->right, key);

        updateHeight(root);
        int bal = getBalance(root);

        if(bal > 1 && key < root->left->key)
        {
            return rightRotate(root);
        }

        if(bal < -1 && key > root->right->key)
        {
            return leftRotate(root);
        }
        if(bal > 1 && key > root->left->key)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if(bal < -1 && key < root->right->key) 
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }
};
int main()
{
    // Driver code;
}