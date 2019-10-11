#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "../01-array/array.hpp"

template<typename T>
class Queue
{
public:
    Queue(int cap)
    {
        arr = Array<T>(cap);
    }
    Queue()
    {
        arr = Array<T>();
    }
    int size(){return arr.size();}
    int getCapacity(){return arr.getCapacity();}
    bool isEmpty(){return arr.size() == 0;}
    void push(T e){arr.pushLast(e);}
    T front(){return arr.getFirst();}
    T pop() {return arr.removeFirst();}
    template<typename T1>
    friend ostream& operator<<(ostream& os, Queue<T1>& s);
private:
    Array<T> arr;    
};

template<typename T>
ostream& operator<<(ostream& os, Queue<T>& s)
{
    os << "queue size = " << s.size() << "    queue capacity = " << s.getCapacity() << endl;
    os << "[";
    for(int i = 0; i < s.size(); i++)
    {
        os << s.arr.get(i);
        if(i != s.size() - 1)
            os << ", ";
    }
    os << "] top" << endl;
    return os;
}
#endif /* QUEUE_HPP */
