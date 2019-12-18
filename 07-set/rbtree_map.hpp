#ifndef RBTREE_MAP_H_
#define RBTREE_MAP_H_

#include "../13-rb-tree/rb_tree.hpp"

template<typename K, typename V>
class RBTreeMap : public Map<K, V>
{
private:
    RBTree<K, V> rb_tree;
public:
    void add(K key, V value){rb_tree.add(key, value);}
    V remove(K key){return rb_tree.remove(key);}
    bool contain(K key){return rb_tree.contain(key);}
    V get(K key){return rb_tree.get(key);}
    void set(K key, V value){rb_tree.set(key, value);}
    int size() const {return rb_tree.size();}
    bool empty() const {return rb_tree.empty();}
};


#endif /* RBTREE_MAP_H_ */
