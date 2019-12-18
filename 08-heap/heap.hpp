#ifndef HEAP_HPP
#define HEAP_HPP


#include <istream>
#include <vector>
#include "../01-array/array.hpp"

using namespace std;

template<typename T>
class MaxHeap
{
private:
    Array<T> arr;
    inline int parent(int index){
        assert(index > 0);
        return (index-1)/2;
    }
    inline int leftChild(int index){return index * 2 + 1;}
    inline int rightChild(int index){return index * 2 + 2;}
    void shiftUp(int index)
    {
        while (index > 0 && arr.get(parent(index)) < arr.get(index) )
        {
            arr.swap(index, parent(index));
            index = parent(index);
        }
        
    }
    void shiftDown(int index)
    {
        while(leftChild(index) < arr.size())
        {
            int k = leftChild(index);
            if(rightChild(index) < arr.size() && arr.get(leftChild(index)) < arr.get(rightChild(index)))
                k = rightChild(index);
            if(arr.get(index) >= arr.get(k))
                break;
            else
            {
                arr.swap(index, k);
                index = k;
            }
        }
    }
public:
    MaxHeap(int cap)
    {
        arr = Array<T>(cap);
    }
    MaxHeap()
    {
        arr = Array<T>();
    }
    MaxHeap(vector<T> a)
    {
        arr = Array<T>();
        int len = a.size();
        for(int i = 0; i < len; i++)
            arr.addLast(a[i]);
        heapify();
    }
    int size() const {return arr.size();}
    bool empty() const {return arr.empty();}

    void add(T e)
    {
        arr.addLast(e);
        shiftUp(arr.size() - 1);
    }
    T findMax()
    {
        assert(arr.empty() == false);
        return arr.get(0);
    }
    T extractMax()
    {
        T ret = findMax();
        arr.swap(0, arr.size() - 1);
        arr.removeLast();
        shiftDown(0);
        return ret;
    }
    T replace(T e)
    {
        T ret = findMax();
        arr.set(0, e);
        shiftDown(0);
        return ret;
    }
    void heapify()
    {
        //从第一个非叶子节点开始
        for(int i = parent(arr.size() - 1); i >= 0; i--)
        {
            shiftDown(i);
        }
    }
};

#endif /*  HEAP_HPP */
