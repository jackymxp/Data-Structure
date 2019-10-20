#ifndef BST_SET_HPP
#define BST_SET_HPP

#include <iostream>
#include "../06-bst/bst.hpp"

using namespace std;

template<typename T>
class BSTSet
{
private:
    BST<T> bst;
public:
    void add(T e){
        bst.add(e);
    }
    void remove(T e){
        bst.remove(e);
    }
    bool contain(T e){
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
