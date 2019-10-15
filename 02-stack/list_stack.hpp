#include "../04-list/dummyList.hpp"

template<typename T>
class ListStack
{
public:
    ListStack()
    {
        l = List<T>();
    }
    int size(){return l.size();}
    bool isEmpty(){return l.isEmpty();}
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
    os << "[";
    //auto p = s.l.dummyHead->next;
    while(p)
    {
        os << p->data;
        if(p->next)
            os << "-->";
    }
    os << "top" << endl;
    return os;
}
