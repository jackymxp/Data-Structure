#ifndef RBTREE_SET_H_
#define RBTREE_SET_H_

#include "../13-rb-tree/rb_tree.hpp"


template<typename K>
class RBTreeSet : public Set<K>
{
private:
    RBTree<K, K> rb_tree;
public:
    RBTreeSet(){}
    ~RBTreeSet(){}
    int size() { return rb_tree.size(); }
    bool empty() { return rb_tree.empty(); }

    void add(K key){rb_tree.add(key, key);}
    void remove(K key){rb_tree.remove(key);}
    bool contain(K key) { return rb_tree.contain(key);}


};


#endif /*RBTREE_SET_H_ */
