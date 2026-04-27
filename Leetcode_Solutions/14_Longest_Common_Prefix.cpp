#include<bits/stdc++.h>
using namespace std;
struct Node
{
    Node* links[26];
    int letterCount = 0;
    bool flag = false;

    bool containsKey(char ch)
    {
        return (links[ch-'a'] != NULL);
    }
    void put(char ch, Node* node)
    {
        links[ch-'a'] = node;
    }
    Node* get(char ch)
    {
        return links[ch-'a'];
    }
    void setEnd()
    {
        flag = true;
    }
    bool getEnd()
    {
        return flag;
    }
    void setLetterCount()
    {
        letterCount++;
    }
    int getLetterCount()
    {
        return letterCount;
    }
};
class Trie
{
    Node* root;
public:
    Trie()
    {
        root = new Node();
    }
    void insertWord(string &str)
    {
        Node* node = root;
        for(int i=0;i<str.size();i++)
        {
            if(!node->containsKey(str[i]))
            {
                node->put(str[i], new Node());
            }
            node = node->get(str[i]);
            node->setLetterCount();
        }
        node->setEnd();
    }
    string solve(string &str, int n)
    {
        string ans = "";
        Node* node = root;
        for(int i=0;i<str.size();i++)
        {
            node = node->get(str[i]);
            if(node->getLetterCount() == n)
            {
                ans += str[i];
            }
            else break;
        }
        return ans;
    }
};
class Solution {
    Trie t;
public:
    // Time Complexity : O(n * lengthOfLongestString)
    // Space Complexity : O(lengthOfLongestString)
    string longestCommonPrefix(vector<string>& strs) {
        for(string& str : strs)
        {
            t.insertWord(str);
        }
        return t.solve(strs[0], strs.size());
    }
    // Time Complexity : O(n * lengthOflongestCommonPrefix)
    // Space Complexity : O(1)
    string longestCommonPrefix(vector<string>& strs, int n)
    {
        string ans = "";
        for(int i=0;i<strs[0].size();i++)
        {
            for(int j=1;j<n;j++)
            {
                if(strs[0][i] != strs[j][i]) return ans;
            }
            ans += strs[0][i];
        }
        return ans;
    }
};
int main()
{
    int n;
    cin>>n;
    vector<string> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    Solution s;
    cout<<s.longestCommonPrefix(arr)<<endl;
    cout<<s.longestCommonPrefix(arr, n)<<endl;
}
