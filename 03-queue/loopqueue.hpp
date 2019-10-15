#include <iostream>

using namespace std;

template<typename T>
class LoopQueue
{
private:
    T* data;
    int head, tail;
    int count;
    int capacity;
    void resize(int newCap) 
    {
        T* newData = new T[newCap + 1];
        for(int i = 0; i < count; i++)
        {
            newData[i] = data[(i+head)%capacity];
        }
        delete data;
        data = newData;
        head = 0;
        tail = count;
        capacity = newCap;
    }
public:
    //入队tail = (tail + 1) % 数组长度
    //出队head = (head + 1) % 数组长度
    //head == tail 对列为空
    //(tail + 1) % 数组长度 == head 队列满
    LoopQueue(int cap)
    {
        capacity = cap + 1; //要有一个元素空着，标志数组为满
        data = new T[capacity];
        head = 0;
        tail = 0;//[head tail) 使用的是这个范围内的数据，作为队列
        count = 0;
    }
    
    LoopQueue()
    {
        capacity = 11;
        data = new T[capacity];
        head = 0;
        tail = 0;
        count = 0;
    }
    ~LoopQueue()
    {
        delete[] data;
    }
    int getCapacity(){return capacity - 1;}
    int size(){return count;}
    bool isEmpty(){return head == tail;}
    void push(T e)
    {
        if((tail+1)%capacity == head)
            resize(getCapacity() * 2);
        data[tail] = e;
        tail = (tail + 1) % capacity;
        count++;
    }
    T pop()
    {
        assert(isEmpty() == false);
        T ret = data[head];
        head = (head + 1) % capacity;
        count--;
        if(count == getCapacity() / 4 && getCapacity() / 2 != 0) 
            resize(getCapacity() / 2);
        return ret;
    }
    T front()
    {
        assert(isEmpty() == false);
        return data[head];
    }
    template<typename T1>
    friend ostream& operator<<(ostream& os, LoopQueue<T1>& s);
};

template<typename T>
ostream& operator<<(ostream& os, LoopQueue<T>& s)
{
    os << "loopqueue size = " << s.size() << "    loopqueue capacity = " << s.getCapacity() << endl;
    os << "[";
    for(int i = s.head; i != s.tail; i = (i+1)%s.capacity)
    {
        os << s.data[i];
        if((i+1)%s.capacity != s.tail)
            os << ", ";
    }
    os << "] top" << endl;
    return os;
}


