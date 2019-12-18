#ifndef _STACK_H_
#define _STACK_H_


template <typename T>
class Stack {
public:
    virtual int size() const  = 0; 
    virtual bool empty() const = 0;
    virtual void push(T e) = 0;
    virtual T pop() = 0; 
    virtual T top() = 0;
};

#endif /* _STACK_H_ */
