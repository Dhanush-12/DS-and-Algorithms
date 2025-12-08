#include<bits/stdc++.h>
using namespace std;
struct Node {
    Node* links[26];
    bool flag=false;
    int wordCount=0;
    int prefixCount=0;

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
        flag=true;
    }
    bool getEnd()
    {
        return flag;
    }
    void setWordCount()
    {
        wordCount++;
    }
    int getWordCount()
    {
        return wordCount;
    }
    void setPrefixCount()
    {
        prefixCount++;
    }
    int getPrefixCount()
    {
        return prefixCount;
    }
    void decrementWord()
    {
        wordCount--;
    }
    void decrementPrefix()
    {
        prefixCount--;
    }
};
class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insertWord(string &str) {
        Node* node = root;
        for(int i=0;i<str.size();i++)
        {
            if(!node->containsKey(str[i]))
            {
                node->put(str[i], new Node());
            }
            node->setPrefixCount();
            node = node->get(str[i]);
        }
        node->setEnd();
        node->setPrefixCount();
        node->setWordCount();
    }
    bool checkIsPrefix(string &str)
    {
        bool flag = true;
        Node* node = root;
        for(int i=0;i<str.size();i++)
        {
            if(!node->containsKey(str[i])) return false;
            node = node->get(str[i]);
            if(!node->getEnd()) return false;
        }
        return true;
    }
};
// Time Complexity: O(n * avglen of words) 
string longestWordWithAllPrefixes(int n, vector<string>&arr)
{
    Trie t;
    for(auto &it:arr) t.insertWord(it);
    string ans="";
    for(auto &it:arr)
    {
        if(t.checkIsPrefix(it))
        {
            if(it.size() > ans.size())
            {
                ans=it;
            }
            else if(it.size() == ans.size())
            {
                ans=min(ans,it);
            }
        }
    }
    return ans == "" ? "None" : ans;
}
int main()
{
    int n;
    cin>>n;
    vector<string>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    string ans = longestWordWithAllPrefixes(n,arr);
    cout<<ans<<endl;
}
/*
6
n
ninja
ninj
ni
nin
ninga
*/
