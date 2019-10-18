#ifndef LIST_QUEUE_HPP
#define LIST_QUEUE_HPP

#include <iostream>

using namespace std;

template<typename T>
class ListQueue
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
    Node* head;//队首，删除用
    Node* tail; //队尾，增加用
    int count;
public:
    ListQueue()
    {
        head = NULL;
        tail = NULL;
        count = 0;
    }
    ~ListQueue()
    {
        Node* p = head;
        while(p)
        {
            Node* next = p->next;
            delete p;
            p = next;
        }
    }
    int size(){return count;}
    bool empty(){return count == 0;}
    void push(T e)
    {
        if(tail == NULL)
        {
            tail = new Node(e);
            head = tail;
        }
        else
        { 
            tail->next = new Node(e);
            tail = tail->next;
        }
        count++;
    }
    
    T front()
    {
        assert(count > 0);
        if(head == NULL)
            cout << "head == NULL " << endl;
        else 
            cout << "head != NULL" << endl;
        return head->data;
    }
    T pop()
    {
        assert(count > 0);
        Node* retNode = head;
        head = head->next;
        T ret = retNode->data;
        delete retNode;
        count--;
        return ret;
    }
    template<typename T1>
    friend ostream& operator<<(ostream& os, ListQueue<T1>& s);
};

template<typename T>
ostream& operator<<(ostream& os, ListQueue<T>& s)
{
    os << "queue size = " << s.size() <<  endl;
    os << "front " << endl;
    auto p = s.head;
    while(p)
    {
        os << p->data;
        if(p->next)
            os << "-->";
        p = p->next;
    }
    os <<" tail" << endl;
    return os;
}

#endif /* LIST_QUEUE_HPP */