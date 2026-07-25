// https://www.hackerrank.com/contests/sda-hw-3-2025/challenges/cache-8/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache
{
    int capacity;

    list<pair<int,int>> cache;

    unordered_map<int, list<pair<int,int>>::iterator> mp;


public:

    LRUCache(int c)
    {
        capacity = c;
    }


    void put(int key, int value)
    {
        if(mp.count(key))
        {
            auto it = mp[key];

            cache.erase(it);
            mp.erase(key);
        }


        cache.push_front({key,value});

        mp[key] = cache.begin();


        if(cache.size() > capacity)
        {
            auto last = cache.end();

            --last;

            mp.erase(last->first);

            cache.pop_back();
        }
    }



    int get(int key)
    {
        if(!mp.count(key))
            return -1;


        auto it = mp[key];

        int value = it->second;


        cache.splice(
            cache.begin(),
            cache,
            it
        );


        return value;
    }



    void heat()
    {
        if(cache.empty())
            return;


        auto last = cache.end();

        --last;

        mp.erase(last->first);

        cache.pop_back();
    }
};



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int capacity, q, k;

    cin >> capacity >> q >> k;


    LRUCache cache(capacity);


    for(int i = 1; i <= q; i++)
    {
        string command;

        cin >> command;


        if(command == "put")
        {
            int key,value;

            cin >> key >> value;

            cache.put(key,value);
        }
        else
        {
            int key;

            cin >> key;

            cout << cache.get(key) << "\n";
        }


        if(i % k == 0)
        {
            cache.heat();
        }
    }


    return 0;
}
