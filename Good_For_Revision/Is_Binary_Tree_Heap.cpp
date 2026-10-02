#include<bits/stdc++.h>
using namespace std;
/*
    Problem: You are given the root of a binary tree, and the task is to determine whether
    it satisfies the properties of a max-heap.

    A binary tree is considered a max-heap if it satisfies the following conditions:

    Completeness: Every level of the tree, except possibly the last, is completely filled,
    and all nodes are as far left as possible.
    Max-Heap Property: The value of each node is greater than or equal to the values of its
    children.

    Input: root = [97, 46, 37, 12, 3, 7, 31, 6, 9]
    Output: true
    Explanation: The tree is complete and satisfies the max-heap property.

    Input: root = [97, 46, 37, 12, 3, 7, 31, N, N, 2, 4]
    Output: false
    Explanation: The tree is not complete and does not follow the Max-Heap Property, hence it is not a max-heap.
*/
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data  = data;
        left = NULL;
        right = NULL;
    }
};
class Solution {
  public:
    bool isHeap(Node* tree) {
        queue<Node*> q;
        q.push(tree);

        bool missing = false;

        while(!q.empty())
        {
            Node* curr = q.front();
            q.pop();

            if(curr->left)
            {
                if(curr->left->data > curr->data) return false;
                if(missing) return false;
                q.push(curr->left);
            }
            else missing = true;
            if(curr->right)
            {
                if(curr->right->data > curr->data) return false;
                if(missing) return false;
                q.push(curr->right);
            }
            else missing = true;
        }

        return true;
    }
};
int main()
{
    // Driver Code
}