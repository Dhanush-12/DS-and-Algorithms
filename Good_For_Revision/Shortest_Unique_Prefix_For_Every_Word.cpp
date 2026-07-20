#include<bits/stdc++.h>
using namespace std;
/*
    Given an array of strings arr[ ], find the shortest prefix of each string that uniquely identifies it among all strings in the
    array. A prefix is unique if it is not a prefix of any other string in the array.

    Note: No string in the given array is a prefix of another string.

    Examples :

    Input: arr[] = {"zebra", "dog", "duck", "dove"}
    Output: z dog du dov
    Explanation: z => zebra, dog => dog, duck => du, dove => dov 
*/
struct Node {
    Node* links[26];
    int flag = 0;
    int prefCount = 0;

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

    void setPrefCount()
    {
        prefCount += 1;
    }

    int getPrefCount()
    {
        return prefCount;
    }

};
class Trie {
    Node* root;
public:
    Trie() {
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
            node->setPrefCount();
        }
        node->setEnd();
    }

    string findNonPref(string &str)
    {
        Node* node = root;
        string ans = "";
        for(char ch:str) {
            ans += ch;
            node = node->get(ch);
            if(node->getPrefCount() == 1) return ans;
        }
        return ans;
    }
};
class Solution {
  public:
    vector<string> findPrefixes(vector<string>& arr) {
        vector<string> ans;
        Trie t;
        for(string &str : arr) t.insertWord(str);
        for(string &str : arr)
        {
            ans.push_back(t.findNonPref(str));
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
    vector<string> ans = s.findPrefixes(arr);
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    cout<<endl;
}
/*
4
zebra dog duck dove
*/
