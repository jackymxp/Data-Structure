#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>

using namespace std;

template<typename K, typename V>
class ListMap
{
private:
    class Node
    {
    public:
        K k;
        V v;
        Node* next;
        Node(K k, V v):k(k), v(v), next(NULL){}
        Node(K k, V v, Node* n):k(k), v(v), next(n){}
        Node():next(NULL) {}
    };
    Node* dummyHead;
    int count;
    Node* getNode(K k)
    {
        Node* p = dummyHead;
        while(p)
        {
            if(p->k == k)
                return p;
            p = p->next;
        }
        return nullptr;
    }
public:
    ListMap()
    {
        dummyHead = new Node();
        count = 0;
    }
    ~ListMap()
    {
        Node* p = dummyHead;
        while(p)
        {
            Node* next = p->next;
            delete p;
            p = next;
        }
    }
    void add(K k, V v)
    {
        Node* node = getNode(k);
        if(node == nullptr)
        {
            dummyHead->next = new Node(k, v, dummyHead->next);
            count++;
        }
        else
        {
            node->v = v;
        }
    }
    void set(K k, V v)
    {
        Node* node = getNode(k);
        if(node != nullptr)
            node->v = v;
    }
    V remoev(K k)
    {
        Node* prev = dummyHead;
        while(prev->next)
        {
            if(prev->next->k == k)
                break;
            prev = prev->next;
        }
        if(prev->next)
        {
            Node* delNode = prev->next;
            prev->next = delNode->next;
            delete delNode;
            count--;
            return delNode->v;
        }
        return NULL;
    }
    bool contain(K k){return getNode(k) != nullptr;}
    bool empty(){return count == 0;}
    int size(){return count;}
    V get(K k)
    {
        Node* node = getNode(k);
        return node == nullptr ? NULL : node->v;
    }

};


#endif /* MAP_HPP */