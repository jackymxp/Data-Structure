#ifndef ARR_QUEUE_HPP
#define ARR_QUEUE_HPP

#include "../01-array/array.hpp"
#include "queue.hpp"

template<typename T>
class ArrayQueue : public Queue<T>
{
public:
    ArrayQueue(int cap)
    {
        arr = Array<T>(cap);
    }
    ArrayQueue()
    {
        arr = Array<T>();
    }
    int size(){return arr.size();}
    int getCapacity(){return arr.getCapacity();}
    bool empty(){return arr.size() == 0;}
    void push(T e){arr.addLast(e);}
    T front(){return arr.getFirst();}
    T pop() {return arr.removeFirst();}
    template<typename T1>
    friend ostream& operator<<(ostream& os, ArrayQueue<T1>& s);
private:
    Array<T> arr;    
};

template<typename T>
ostream& operator<<(ostream& os, ArrayQueue<T>& s)
{
    os << "queue size = " << s.size() << "    queue capacity = " << s.getCapacity() << endl;
    os << "front " << s.arr << " tail" << endl;
    return os;
}
#endif /* ARR_QUEUE_HPP */
