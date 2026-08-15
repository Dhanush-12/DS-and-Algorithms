#include<bits/stdc++.h>
using namespace std;
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
class Solution {
    void getSortedValues(Node* root, vector<int> &arr)
    {
        if(!root) return;
        getSortedValues(root->left, arr);
        arr.push_back(root->data);
        getSortedValues(root->right, arr);
        return;
    }
  public:
    // Good Solution but extra space
    // Time Complexity: O(n) n is number of nodes
    // Space Complexity: O(n) " " "
    int getCount(Node *root, int l, int h) {
        vector<int> values;
        getSortedValues(root, values);
        int lInd = lower_bound(values.begin(), values.end(), l)-values.begin();
        int rInd = upper_bound(values.begin(), values.end(), h)-values.begin();

        return rInd-lInd;
    }
    
    // Better solution as Tree is already a Binary Search Tree
    int getCount(Node *root, int l, int h) {
        if(!root) return 0;
        
        if(root->data < l) return getCount(root->right, l, h);
        if(root->data > h) return getCount(root->left, l, h);
        
        return 1+getCount(root->left, l, h)+getCount(root->right, l, h);
    }
};
int main()
{
    // In order to run the program, Implementation of BS Tree is needed, So just writing the algorithms for solution sake.
}
/*
10 5 50 1 N 40 100
l = 10, h = 100

Ans: 4
*/
