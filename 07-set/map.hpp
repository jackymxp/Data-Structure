#ifndef _MAP_H_
#define _MAP_H_

template<typename K, typename V>
class Map {
public:
    virtual bool empty() = 0;
    virtual int size() = 0;
    virtual void add(K key, V value) = 0;
    virtual bool contain(K key) = 0;
    virtual V get(K key) = 0;
    virtual void set(K key, V value) = 0;
    virtual V remove(K key) = 0;
};


#endif /*_MAP_H_ */