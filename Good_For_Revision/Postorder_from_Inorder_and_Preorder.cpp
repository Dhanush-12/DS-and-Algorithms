#include<bits/stdc++.h>
using namespace std;
/*
    Problem: Given the preorder and inorder traversals of a binary tree, return its postorder 
    traversal. You are required to complete the function getPostorder() that returns the nodes
    of the tree in postorder sequence.

    Note: All node values are distinct.

    Input: inorder[] = [4, 2, 5, 1, 3, 6], preorder[] = [1, 2, 4, 5, 3, 6]         
    Output: [4, 5, 2, 6, 3, 1]

    Input: inorder[] = [2, 1, 4, 3, 5], preorder[] = [1, 2, 3, 4, 5]        
    Output: [2, 4, 5, 3, 1]
*/
class Solution {
    void getHelper(int is, int ie, vector<int> &inorder, int &ps, vector<int> &preorder, unordered_map<int,int> &mp, vector<int> &ans)
    {
        if(is > ie) return;

        int root = preorder[ps++];
        int inRoot = mp[root];

        getHelper(is, inRoot-1, inorder, ps, preorder, mp, ans);
        getHelper(inRoot+1, ie, inorder, ps, preorder, mp, ans);

        ans.push_back(root);
        return;
    }
  public:
    vector<int> getPostorder(vector<int>& inorder, vector<int>& preorder) {
        vector<int> ans;
        int n = (int)inorder.size();
        int m = (int)preorder.size();

        unordered_map<int,int> mp;
        for(int i=0;i<n;i++) mp[inorder[i]] = i;

        int pre = 0;

        getHelper(0, n-1, inorder, pre, preorder, mp, ans);

        return ans;
    }
};
int main()
{
    int n;
    cin>>n;
    vector<int> inorder(n), preorder(n);
    for(int i=0;i<n;i++) cin>>inorder[i];
    for(int i=0;i<n;i++) cin>>preorder[i];
    Solution s;
    vector<int> ans = s.getPostorder(inorder, preorder);
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    cout<<endl;
}
/*
6
4 2 5 1 3 6
1 2 4 5 3 6
*/