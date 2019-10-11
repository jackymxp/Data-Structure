//#include "../01-array/array.hpp"
#include "array.hpp"
template<typename T>
class Stack
{
public:
    Stack(int cap)
    {
        arr = Array<T>(cap);
    }
    Stack()
    {
        arr = Array<T>();
    }
    int size(){return arr.size();}
    int getCapacity(){return arr.getCapacity();}
    bool isEmpty(){return arr.size() == 0;}
    void push(T e){arr.pushLast(e);}
    T top(){return arr.getLast();}
    T pop() {return arr.removeLast();}
    template<typename T1>
    friend ostream& operator<<(ostream& os, Stack<T1>& s);
private:
    Array<T> arr;
};

template<typename T>
ostream& operator<<(ostream& os, Stack<T>& s)
{
    os << "stack size = " << s.size() << "    stack capacity = " << s.getCapacity() << endl;
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