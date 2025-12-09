#include<bits/stdc++.h>
using namespace std;
struct Node {
    Node* links[26];
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
class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    bool insertWord(string &str)
    {
        Node* node = root;
        int f = 0;
        for(int i=0;i<str.size();i++)
        {
            if(!node->containsKey(str[i]))
            {
                f=1;
                node->put(str[i], new Node());
            }
            node = node->get(str[i]);
        }
        node->setEnd();
        return f;
    }
    bool searchWord(string &str)
    {
        Node* node = root;
        for(int i=0;i<str.size();i++)
        {
            if(!node->containsKey(str[i])) return false;
            node = node->get(str[i]);
        }
        return node->getEnd();
    }
    bool isPrefix(string &str)
    {
        Node* node = root;
        for(int i=0;i<str.size();i++)
        {
            if(!node->containsKey(str[i])) return false;
            node = node->get(str[i]);
        }
        return true;
    }
};
int countDistinctSubstrings(string &str)
{
    Trie t;
    int n=(int)str.size();
    int ans=0;
    for(int i=0;i<n;i++)
    {
        string temp="";
        for(int j=i;j<n;j++)
        {
            temp+=str[j];
            if(t.insertWord(temp))
            {
                ans++;
            }
        }
    }
    return ans;
}
int main()
{
    string str;
    cin>>str;
    cout<<countDistinctSubstrings(str)<<endl;
}
