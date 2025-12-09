#include<bits/stdc++.h>
using namespace std;
struct Node {
    Node* links[26];
    bool flag = false;
    ~Node() {
        for (int i=0; i<26; ++i) {
            delete links[i];
    }}

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
    };

    void setEnd()
    {
        flag=true;
    }
    bool getEnd()
    {
        return flag;
    }
};
int countDistinctSubstrings(string &str)
{
    int n = (int)str.size();
    Node* root = new Node();
    int ans=0;
    for(int i=0;i<n;i++)
    {
        Node* node = root;
        for(int j=i;j<n;j++)
        {
            if(!node->containsKey(str[j]))
            {
                ans++;
                node->put(str[j], new Node());
            }
            node = node->get(str[j]);
        }
    }
    delete root;
    return ans;
}
int main()
{
    string str;
    cin>>str;
    cout<<countDistinctSubstrings(str)<<endl;
}
