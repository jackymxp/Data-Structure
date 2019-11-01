#ifndef _HASH_TABLE_H_
#define _HASH_TABLE_H_

#include <iostream>
#include <vector>
#include <map>
#include <cassert>

using namespace std;

template <typename K, typename V>
class HashTable
{
private:
    int capacity[26] = {53, 97, 193, 389, 769, 1543, 3079, 6151, 12289, 24593,
            49157, 98317, 196613, 393241, 786433, 1572869, 3145739, 6291469,
            12582917, 25165843, 50331653, 100663319, 201326611, 402653189, 805306457, 1610612741};
    vector<map<K, V>> hashtable;
    int M; //选择一个合适的size;
    int count;
    static const int upperTol = 10;
    static const int lowerTol = 2;
    int capacityIndex = 0;
    int hash(string key)
    {
        int hash = 0;
        int B = 26;
        for(const char c : key)
            hash = (hash * B + c) % M; 
        return hash;
    }

    void resize(int newM)
    {
        vector<map<K, V>> newHash = vector<map<K, V>>(newM);
        int oldM = M;
        this->M = newM;
        for(int i = 0; i < oldM; i++)
        {
            map<K, V>& mapping = hashtable[i];
            for(auto it = mapping.begin(); it != mapping.end(); it++)
            {
                int index = hash(it->first);
                newHash[index][it->first] = it->second;
            }
        }
        this->hashtable = newHash;
    }
public:
    HashTable(int M, int(*hash)(K)) : M(M), count(0) { 
        hashtable = vector<map<K, V>>(M);
    }

    HashTable(int M) : M(M), count(0) { 
        hashtable = vector<map<K, V>>(M);
    }
    HashTable() : M(capacity[capacityIndex]), count(0) { 
        hashtable = vector<map<K, V>>(capacity[capacityIndex]);

    }
    int size(){ return count; }
    bool empty(){return count == 0;}
    void add(K key, V value)
    {
        int index = hash(key);
        assert(index < M);
        //cout << "index = " << index << endl;
        map<K, V>& mapping = hashtable[index];
        //cout << "key = " << key << "  index = " << index << "  count = " << mapping.count(key) << endl;
        if(mapping.count(key) == 0)
        {
            //mapping[key] = value;
            mapping.insert(make_pair(key, value));
            count++;
            if(count >= upperTol * M && capacityIndex + 1 < sizeof(capacity) / sizeof(capacity[0]))
            {
                //resize(2*M);
                capacityIndex++;
                resize(capacity[capacityIndex]);
            }
                
        }
        else
        {
            mapping[key] = value;
        }
    }
    V remove(K key)
    {
        map<K, V>& mapping = hashtable[hash(key)];
        V ret;
        if(mapping.count(key))
        {
            ret = mapping[key];
            mapping.erase(key);
            count--;
            if(count < lowerTol * M && capacityIndex - 1 >= 0)
            {
                //resize(M / 2);
                resize(capacity[capacityIndex]);
            }

        }
        return ret;
    }
    void set(K key, V value)
    {
        map<K, V>& mapping = hashtable[hash(key)];
        if(mapping.count(key))
        {
                mapping[key] = value;
        }
        else{
            throw "not founded ";
        }
    }
    bool contain(K key)
    {
        map<K, V>& mapping = hashtable[hash(key)];
        return mapping.count(key) != 0;
    }
    V get(K key)
    {
        map<K, V>& mapping = hashtable[hash(key)];
        return mapping[key];
    }
};


#endif /* _HASH_TABLE_H_ */