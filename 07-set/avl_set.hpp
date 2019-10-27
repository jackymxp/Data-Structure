#include "../12-avl-tree/avl_tree.hpp"


template<typename K>
class AVLSet : public Set<K>
{
private:
    AVLTree<K, K> atree;
public:
    AVLSet(){}
    ~AVLSet(){}
    int size() { return atree.size(); }
    bool empty() { return atree.empty(); }

    void add(K key){atree.add(key, key);}
    void remove(K key){atree.remove(key);}
    bool contain(K key) { return atree.contain(key);}


};