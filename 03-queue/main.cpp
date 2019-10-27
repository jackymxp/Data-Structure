#include "array_queue.hpp"
#include "list_queue.hpp"
#include "loop_queue.hpp"

#include <ctime>
#include <stdlib.h>

class Student
{
public:
    Student(){age = 10;score = 10;}
    Student(int age, int score):age(age), score(score){}
    bool operator==(const Student& other)
    {
        return this->age == other.age && this->score == other.score;
    }
    friend ostream& operator<<(ostream& os, Student& s);
private:
    int age;
    int score;
};

ostream& operator<<(ostream& os, Student& s)
{  
    os << "age = " << s.age << "  score = " << s.score << endl;
    return os;
}



template<typename T>
void testQueue(Queue<T>* s, string queueName, int oc)
{
    cout << "start test " << queueName << endl;
    for(int i = 0; i < oc; i++)
    {   
        Student t(i, i);
        cout << "push   " << t << endl;
        s->push(t);
    }
    cout << "--------test pop and top---------" << endl;    
    while(!s->empty())
    {
        Student ss = s->front();
        assert(ss == s->pop());
        cout << "pop   " << ss << endl;
    }
    cout << "test " << queueName << "successed !" << endl;
}

template<typename T>
void compareQueue(Queue<T>*q, string queueName, int oc)
{
    srand(time(NULL));
    clock_t start1 = clock();
    for(int i = 0; i < oc; i++)
        q->push(rand());
    for(int i = 0; i < oc; i++)
        q->pop();
    assert(q->size() == 0);
    assert(q->empty() == true);
    clock_t end1 = clock();
    cout << queueName << "  take " << (double)(end1 - start1) / CLOCKS_PER_SEC << " s  "  << endl;
}
int main(void)
{

    cout << "test queue " << endl;
    Queue<Student>* q1;
    int size = 10;


    q1 = new ArrayQueue<Student>;
    testQueue(q1, "ArrayQueue", size);

    q1 = new ListQueue<Student>;
    testQueue(q1, "ListQueue", size);

    q1 = new LoopQueue<Student>;
    testQueue(q1, "LoopQueue", size);



    Queue<int>* q2;
    size = 100000;

    q2 = new ArrayQueue<int>;
    compareQueue(q2, "ArrayQueue", size);

    q2 = new ListQueue<int>;
    compareQueue(q2, "ListQueue", size);

    q2 = new LoopQueue<int>;
    compareQueue(q2, "LoopQueue", size);
    
    return 0; 
}
