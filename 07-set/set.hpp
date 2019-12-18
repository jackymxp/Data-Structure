#ifndef _SET_H_
#define _SET_H_

#include <iostream>

using namespace std;

template<typename K>
class Set
{
public:
    virtual bool empty() const = 0;
    virtual int size() const = 0;
    virtual void add(K key) = 0;
    virtual void remove(K key) = 0;
    virtual bool contain(K key) = 0;
};

#endif /* _SET_H_ */
