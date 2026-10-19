#include <bits/stdc++.h>
#define ll long long
using namespace std;
/*
    Problem: Design a data structure that works like a LRU Cache. Here cap denotes the capacity
    of the cache and Q denotes the number of queries. Query can be of two types:

    PUT x y: sets the value of the key x with value y
    GET x: gets the value of key x if present else returns -1.
    The LRUCache class has two methods get() and put() which are defined as follows.

    get(key): returns the value of the key if it already exists in the cache otherwise returns
    -1.
    put(key, value): if the key is already present, update its value. If not present, add the
    key-value pair to the cache. If the cache reaches its capacity it should remove the least
    recently used item before inserting the new item.
    In the constructor of the class the capacity of the cache should be initialized.
    Examples:

    Input: cap = 2, Q = 2, Queries = [["PUT", 1, 2], ["GET", 1]]
    Output: [2]
    Explanation: Cache Size = 2
    ["PUT", 1, 2] will insert the key-value pair (1, 2) in the cache,
    ["GET", 1] will print the value corresponding to Key 1, ie 2.
    Input: cap = 2, Q = 8, Queries = [["PUT", 1, 2], ["PUT", 2, 3], ["PUT", 1, 5], ["PUT", 4, 5],
    ["PUT", 6, 7], ["GET", 4], ["PUT", 1, 2], ["GET", 3]]
    Output: [5, -1]
*/
class LRUCache {
    map<int, pair<int,int>> byId;
    unordered_map<int, pair<int,int>> byKey;
    int capacity = 0;
    int currId = 0;
  public:
    LRUCache(int cap) {
        capacity = cap;
    }

    int get(int key) {
        if(byKey.find(key) == byKey.end()) return -1;
        currId += 1;
        auto it = byKey[key];
        int value = it.first;
        int id = it.second;
        byId.erase(id);
        byId[currId] = {key, value};
        byKey[key] = {value, currId};
        return value;
    }

        
    void put(int key, int value) {
        currId += 1;
        if(byKey.find(key) == byKey.end())
        {
            if(byId.size() < capacity) {
                byKey[key] = {value, currId};
                byId[currId] = {key, value};
                return;
            }
            auto it = *(byId.begin());
            int k = it.second.first;
            int leastId = it.first;
            byId.erase(leastId);
            byKey.erase(k);
            byId[currId] = {key, value};
            byKey[key] = {value, currId};
            return;
        }
        auto it = byKey[key];
        int id = it.second;
        byId.erase(id);
        byId[currId] = {key, value};
        byKey[key] = {value, currId};
    }
};
int main() 
{
    int cap,q;
    cin>>cap>>q;
    LRUCache lru(cap);
    string str;
    int a,b;
    for(int i=0;i<q;i++)
    {
        cin>>str;
        if(str == "GET")
        {
            cin>>a;
            cout<<lru.get(a)<<endl;
        }
        else
        {
            cin>>a>>b;
            lru.put(a, b);
        }
    }
}