#ifndef BST_SET_HPP
#define BST_SET_HPP

#include <iostream>
#include "../06-bst/bst.hpp"
#include "set.hpp"

using namespace std;

template<typename K>
class BSTSet : public Set<K>
{
private:
    BST<K> bst;
public:
    void add(K e){
        bst.add(e);
    }
    void remove(K e){
        bst.remove(e);
    }
    bool contain(K e){
        return bst.contain(e);
    }
    int size(){
        return bst.size();
    }
    bool empty(){
        return bst.empty();
    }
};


#endif /*BST_SET_HPP */
