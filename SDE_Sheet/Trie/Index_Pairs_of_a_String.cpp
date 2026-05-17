#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node* links[26];
    bool flag=false;

    bool containsKey(char ch)
    {
        return (links[ch-'a'] != NULL);
    }
    void put(char ch, Node* node)
    {
        links[ch-'a']=node;
    }
    Node* get(char ch)
    {
        return links[ch-'a'];
    }
    void setEnd()
    {
        flag=true;
    }
    bool getEnd()
    {
        return flag;
    }
};
class Trie{
    Node* root;
public:
    Trie(){
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
        }
        node->setEnd();
    }
    vector<pair<int,int>> getIndexPairs(string &str)
    {
        vector<pair<int,int>>ans;
        int n=(int)str.size();
        for(int i=0;i<n;i++)
        {
            Node* node = root;
            for(int j=i;j<n;j++)
            {
                if(!node->containsKey(str[j])) break;
                node = node->get(str[j]);
                if(node->getEnd())
                {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
int main()
{
    string str;
    cin>>str;
    int n;
    cin>>n;
    vector<string>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    Trie t;
    for(int i=0;i<n;i++)
    {
        t.insertWord(arr[i]);
    }
    vector<pair<int,int>> ans = t.getIndexPairs(str);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
}
/*
ababa
2
aba
ab

thestoryofleetcodeandme
3
story
fleet
leetcode

aaaaa
3
a
aa
aaa
*/
