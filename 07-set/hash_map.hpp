

#ifndef _HASH_MAP_H_
#define _HASH_MAP_H_

#include "../14-hash-table/hash_table.hpp"
#include "map.hpp"

template<typename K, typename V>
class HashTableMap : public Map<K, V>
{
private:
    HashTable<K, V> hash_map;
public:
    HashTableMap()
    {}
    HashTableMap(int size)
    {
        hash_map = HashTable<K, V>(size);
    }
    ~HashTableMap()
    {}
    
    void add(K key, V value){hash_map.add(key, value);}
    V remove(K key){return hash_map.remove(key);}
    bool contain(K key){return hash_map.contain(key);}
    V get(K key){return hash_map.get(key);}
    void set(K key, V value){hash_map.set(key, value);}
    int size(){return hash_map.size();}
    bool empty(){return hash_map.empty();}
};


#endif /* _HASH_MAP_H_ */