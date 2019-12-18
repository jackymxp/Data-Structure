#include "heap.hpp"

template<typename T>
class PriQueue
{
private:
    MaxHeap<T> mp;
public:
    int size() const {return mp.size();}
    bool empty() const {return mp.empty();}
    T front(){return mp.findMax();}
    void push(T e){mp.add(e);}
    T pop(){return mp.extractMax();}
};
