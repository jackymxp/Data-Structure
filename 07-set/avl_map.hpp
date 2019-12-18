#ifndef _AVL_MAP_H_
#define _AVL_MAP_H_

#include "../12-avl-tree/avl_tree.hpp"
#include "map.hpp"

template<typename K, typename V>
class AVLMap : public Map<K, V>
{
private:
    AVLTree<K, V> atree;
public:
    AVLMap()
    {}
    ~AVLMap()
    {}
    
    void add(K key, V value){atree.add(key, value);}
    V remove(K key){return atree.remove(key);}
    bool contain(K key){return atree.contain(key);}
    V get(K key){return atree.get(key);}
    void set(K key, V value){atree.set(key, value);}
    int size() const {return atree.size();}
    bool empty() const {return atree.empty();}
};


#endif /* _AVL_MAP_H_ */
