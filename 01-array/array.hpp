#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cassert>
using namespace std;

template<typename T>
class Array
{
private:
    int count;
    int capacity;
    T* data;
    void resize(int newCap)
    {
        capacity = newCap;
        T* newData = new T[newCap];
        for(int i = 0; i < count; i++)
            newData[i] = data[i];
        delete[] data;
        data = newData;
    }
public:
    Array(int cap)
    {
        count = 0;
        capacity = cap;
        data = new T[capacity];
    }
    Array()
    {
        count = 0;
        capacity = 10;
        data = new T[capacity];
    }
    int getCapacity() { return capacity; }
    int size(){return count;}
    bool empty(){return count == 0;}
    void add(int index, T e)
    {
        assert(index >= 0 && index <= count);
        //assert(count < capacity);
        if(count == capacity)
            resize(2*capacity);
        for(int i = count - 1; i >= index; i--)
            data[i+1] = data[i];
        data[index] = e;
        count++;
    }
    void pushFirst(T e){add(0, e);}
    void pushLast(T e){add(count, e);}
    T get(int index)
    {
        assert(index >= 0 && index < count);
        return data[index];
    }
    T operator[](int index)
    {
        assert(index >= 0 && index < count);
        return data[index];
    }
    T getFirst(){return get(0);}
    T getLast(){return get(count-1);}

    void set(int index, T e)
    {
        assert(index >= 0 && index < count);
        data[index] = e;
    }
    int find(T e)
    {
        for(int i = 0; i < count; i++)
            if(e == data[i])
                return i;
        return -1;
    }
    bool contain(T e)
    {
        for(int i = 0; i < count; i++)
            if(e == data[i])
                return true;
        return false;
    }
    T remove(int index)
    {
        assert(index >= 0 && index < count);
        T ret = data[index];
        for(int i = index; i < count - 1; i++)
            data[i] = data[i+1]; 
        count--;
        if(count == capacity / 4 && capacity / 2 != 0)
            resize(capacity / 2);
        return ret;
    }
    T removeFirst(){return remove(0);}
    T removeLast(){return remove(count-1);}
    void removeElement(T e)
    {
        int index = find(e);
        if(index != -1)
            remove(index);
    }

    template<typename T1>
    friend ostream& operator<<(ostream& os, Array<T1> a);
};

    template<typename T>
    ostream& operator<<(ostream& os, Array<T> a)
    {
        os << "size = " << a.count << "   capacity = " << a.capacity << endl;
        os << "[" ;
        for(int i = 0; i < a.count; i++)
        {
            
            os << a.data[i] ;
            if(i != a.count-1)
                os << ", ";
            else
                os << "]" << endl;
        }
        return os;
    }

#endif /* ARRAY_HPP */
