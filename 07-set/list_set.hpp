#include "../04-list/dummyList.hpp"

template<typename T>
class ListSet
{
private:
    List<T> l;
public:
    void empty(){return l.empty();}
    int size() {return l.size();}
    bool contain(T e){return l.contain(e);}

    void add(T e)
    {
        if(l.contain(e) == false)
            l.addFirst(e);
    }

    void remove(T e)
    {
        l.removeElement(e);
    }
};