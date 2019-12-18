#ifndef _QUEUE_H_
#define _QUEUE_H_

template <typename T>
class Queue
{
public:
    virtual int size() const  = 0;
    virtual bool empty() const  = 0;
    virtual void push(T e) = 0;
    virtual T front() = 0;
    virtual T pop() = 0;
    //friend ostream& operator<<(ostream&os, Queue& q);
};


#endif /* _QUEUE_H_ */
