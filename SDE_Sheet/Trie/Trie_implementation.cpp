#include<bits/stdc++.h>
using namespace std;
struct Node
{
    Node* links[26];
    bool flag = false;
    int wordCount=0;
    int prefCount=0;

    bool containsKey(char ch) {
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
        wordCount+=1;
    }
    int getWordCount()
    {
        return wordCount;
    }
    void setPrefCount()
    {
        prefCount++;
    }
    int getPrefCount()
    {
        return prefCount;
    }
    void decreaseWordCount()
    {
        wordCount--;
    }
    void decreasePrefCount()
    {
        prefCount--;
    }
};
class Trie
{
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
            node->setPrefCount();
            node = node->get(str[i]);
        }
        node->setEnd();
        node->setWordCount();
        node->setPrefCount();
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

    int countWords(string &str)
    {
        Node* node = root;
        for(int i=0;i<str.size();i++)
        {
            if(!node->containsKey(str[i])) return 0;
            node = node->get(str[i]);
        }
        return node->getWordCount();
    }

    int countWordsStartingWith(string &str)
    {
        Node* node = root;
        for(int i=0;i<str.size();i++)
        {
            if(!node->containsKey(str[i])) return 0;
            node = node->get(str[i]);
        }
        return node->getPrefCount();
    }
    void eraseWord(string &str)
    {
        Node* node = root;
        if(searchWord(str))
        {
            for(int i=0;i<str.size();i++)
            {
                node->decreasePrefCount();
                node = node->get(str[i]);
            }
            node->decreasePrefCount();
            node->decreaseWordCount();
        }
    }
};
int main()
{
    Trie t;
    while(true)
    {
        cout<<"1. INSERT"<<endl;
        cout<<"2. SEARCH THE WORD"<<endl;
        cout<<"3. IS PREFIX"<<endl;
        cout<<"4. COUNT WORDS"<<endl;
        cout<<"5. COUNT WORDS STARTING WITH"<<endl;
        cout<<"6. ERASE THE WORD"<<endl;
        int controller;
        cin>>controller;
        if(controller == 0) break;
        string str;
        cin>>str;
        if(controller == 1)
        {
            t.insertWord(str);
        }
        else if(controller == 2)
        {
            cout<<t.searchWord(str)<<endl;
        }
        else if(controller == 3)
        {
            cout<<t.isPrefix(str)<<endl;
        }
        else if(controller == 4)
        {
            cout<<t.countWords(str)<<endl;
        }
        else if(controller == 5)
        {
            cout<<t.countWordsStartingWith(str)<<endl;
        }
        else if(controller == 6)
        {
            t.eraseWord(str);
        }
    }
}
