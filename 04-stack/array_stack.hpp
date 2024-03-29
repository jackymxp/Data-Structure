#ifndef ARR_STACK_HPP
#define ARR_STACK_HPP

#include "../01-array/array.hpp"
#include "stack.hpp"
template<typename T>
class ArrayStack : public Stack<T>
{
public:
    ArrayStack(int cap)
    {
        arr = Array<T>(cap);
    }
    ArrayStack()
    {
        arr = Array<T>();
    }
    int size() const {return arr.size();}
    int getCapacity() const {return arr.getCapacity();}
    bool empty() const {return arr.size() == 0;}
    void push(T e){arr.addLast(e);}
    T top(){return arr.getLast();}
    T pop() {return arr.removeLast();}
    template<typename T1>
    friend ostream& operator<<(ostream& os, ArrayStack<T1>& s);
private:
    Array<T> arr;
};

template<typename T>
ostream& operator<<(ostream& os, ArrayStack<T>& s)
{
    os << "stack size = " << s.size() << "    stack capacity = " << s.getCapacity() << endl;
    os << s.arr;
    os << "top";
    return os;
}


#endif /*  ARR_STACK_HPP  */
