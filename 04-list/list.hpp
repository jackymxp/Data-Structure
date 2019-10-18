#ifndef LIST_HPP
#define LIST_HPP

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
    Node* head;
    int count;
public:
    List():head(NULL), count(0){}
    ~List(){
        Node* p = head;
        while(p){
            Node* next = p->next;
            delete p;
            p = next;
        }
    }
    int size() {return count;}
    bool empty() {return count == 0;}
    void addFirst(T e)
    {
        Node* node = new Node(e);
        node->next = head;
        head = node;
        count++;
    }
    
    void add(int index, T e)
    {
        assert(index >= 0 && index <= count);
        if(index == 0)  
            addFirst(e);
        else
        {
            Node* prev = head;
            for(int i = 0; i < index - 1; i++)
                prev = prev->next;
            Node* node = new Node(e);
            node->next = prev->next;
            prev->next = node;
            count++;
        }
    }
    void addLast(T e)
    {
        add(count, e);
    }

    template<typename T1> 
    friend ostream& operator<<(ostream& os, List<T1>& p);
};


template<typename T>
ostream& operator<<(ostream& os, List<T>& p)
{
    os << "size = " << p.count << endl;
    auto* h = p.head;
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

#endif /* DU_LIST_HPP */