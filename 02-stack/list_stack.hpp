#ifndef LIST_STACK
#define LIST_STACK

#include "../04-list/dummyList.hpp"

template<typename T>
class ListStack
{
public:
    int size(){return l.size();}
    bool empty(){return l.empty();}
    void push(T e){l.addFirst(e);}
    T top(){return l.getFirst();}
    T pop(){return l.removeFirst();}
    template<typename T1>
    friend ostream& operator<<(ostream& os, ListStack<T1>& s);
    
private:
    List<T> l;
};

template<typename T1>
ostream& operator<<(ostream& os, ListStack<T1>& s)
{
    os << "stack size = " << s.size() << endl;
    os << s.l;
    os << "top" << endl;
    return os;
}


#endif /* LIST_STACK */