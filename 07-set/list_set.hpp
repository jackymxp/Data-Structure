#include "../02-list/dummyList.hpp"
#include "set.hpp"
template<typename T>
class ListSet : public Set<T>
{
private:
    List<T> l;
public:
    bool empty() const {return l.empty();}
    int size() const {return l.size();}
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
