#include<bits/stdc++.h>
using namespace std;
struct Node
{
    Node* links[26];
    bool containsKey(char ch)
    {
        return (links[ch-'a'] != NULL);
    }
    void put(char ch,Node* node)
    {
        links[ch-'a']=node;
    }
    Node* get(char ch)
    {
        return links[ch-'a'];
    }
};
int countDistinctSubstrings(string &str)
{
    int cnt=0;
    Node* root=new Node();
    for(int i=0;i<str.size();i++)
    {
        Node* node=root;
        for(int j=i;j<str.size();j++)
        {
            if(!node->containsKey(str[j]))
            {
                cnt++;
                node->put(str[j],new Node());
            }
            node=node->get(str[j]);
        }
    }
    return cnt+1;
}
int main()
{
    string str;
    cin>>str;
    cout<<countDistinctSubstrings(str)<<endl;
}
