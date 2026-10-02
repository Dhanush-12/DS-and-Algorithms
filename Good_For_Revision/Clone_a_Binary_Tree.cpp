#include<bits/stdc++.h>
using namespace std;
/*
    Problem: A special binary tree with random pointers along with the usual left and right 
    pointers is given. Clone the given tree.

    Note: The output is 1 if the tree is cloned successfully. Otherwise, the output is 0.
*/
struct Node {
    int data;
    Node* left;
    Node* right;
    Node* random;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
        random = NULL;
    }
};
class Solution {
    public:
    Node* cloneTree(Node* root) {
        if(!root) return NULL;

        unordered_map<Node*, Node*> mp;
        queue<Node*> q;
        mp[root] = new Node(root->data);
        q.push(root);

        while(!q.empty())
        {
            Node* curr = q.front();
            q.pop();

            if(curr->left) {
                mp[curr->left] = new Node(curr->left->data);
                q.push(curr->left);
            }

            if(curr->right) {
                mp[curr->right] = new Node(curr->right->data);
                q.push(curr->right);
            }
        }

        q.push(root);
        while(!q.empty()) {
            Node* curr = q.front();
            q.pop();

            Node* clone = mp[curr];

            clone->left = curr->left ? mp[curr->left] : NULL;
            clone->right = curr->right ? mp[curr->right] : NULL;
            clone->random = curr->random ? mp[curr->random] : NULL;

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }

        return mp[root];
    }
};
int main()
{
    // Driver Code
}