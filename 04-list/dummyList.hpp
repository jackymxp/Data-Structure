#ifndef DU_LIST_HPP
#define DU_LIST_HPP

#include <iostream>
#include <cassert>

using namespace std;

template<typename T>
class List
{
private:
    class Node
    {
    public:
        T data;
        Node* next;
        Node(T d):data(d), next(NULL) {}
        Node(T d, Node* n):data(d), next(n){}
        Node():next(NULL) {}
    };
    Node* dummyHead;
    int count;
public:
    List():count(0){
        dummyHead = new Node();
    }
    ~List() {
        Node* p = dummyHead;
        while(p)
        {
            Node* next = p->next;
            delete p;
            p = next;
        }
    }
    int size() {return count;}
    bool empty() {return count == 0;}
    
    void add(int index, T e)
    {
        assert(index >= 0 && index <= count);
        Node* prev = dummyHead;
        for(int i = 0; i < index; i++)
            prev = prev->next;
        Node* node = new Node(e);
        node->next = prev->next;
        prev->next = node;
        count++;
    }
    void addFirst(T e){add(0, e); }
    void addLast(T e){add(count, e); }
    T get(int index)
    {
        assert(index >= 0 && index < count);
        Node* cur = dummyHead->next;
        for(int i = 0; i < index; i++)
            cur = cur->next;
        return cur->data;
    }
    T getFirst(){return get(0);}
    T getLast(){return get(count - 1);}
    void set(int index, T e)
    {
        assert(index >= 0 && index < count);
        Node* cur = dummyHead->next;
        for(int i = 0; i < index; i++)
            cur = cur->next;
        cur->data = e;
    }
    T setFirst(T e){set(0, e);}
    T setLast(T e){set(count - 1, e);}
    bool contains(T e)
    {
        Node* cur = dummyHead->next;
        while(cur)
        {
            if(cur->data == e)
                return true;
            cur = cur->next;
        }
        return false;
    }

    T remove(int index)
    {
        assert(index >= 0 && index < count);
        Node* prev = dummyHead;
        for(int i = 0; i < index; i++)
            prev = prev->next;
        Node* delNode = prev->next;
        prev->next = delNode->next;
        T ret = delNode->data;
        delete delNode;
        count--;
        return ret;
    }
    T removeFirst(){return remove(0);}
    T removeLast(){return remove(count-1);}
    template<typename T1> 
    friend ostream& operator<<(ostream& os, List<T1>& p);
};


template<typename T>
ostream& operator<<(ostream& os, List<T>& p)
{
    os << "size = " << p.count << endl;
    auto h = p.dummyHead->next;
    while(h)
    {
        if(h->next)
            os << h->data << "-->" ;
        else
            os << h->data;
        h = h->next;
    }
    return os;
} 
#endif  /* DU_LIST_HPP */
