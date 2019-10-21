#include "heap.hpp"

template<typename T>
class PriQueue
{
private:
    MaxHeap<T> mp;
public:
    int size(){return mp.size();}
    bool empty(){return mp.empty();}
    T front(){return mp.findMax();}
    void push(T e){mp.add(e);}
    T pop(){return mp.extractMax();}
};