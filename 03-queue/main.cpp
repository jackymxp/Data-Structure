#include "array_queue.hpp"
#include "loopqueue.hpp"
#include <ctime>
#include <stdlib.h>

class Student
{
public:
    Student(){age = 10;score = 10;}
    Student(int age, int score):age(age), score(score){}
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

void testQueue()
{
    Queue<int> q1;
    for(int i = 0; i < 20; i++)
        q1.push(i);

    cout << q1 << endl;
    cout << q1.front() << endl;
    cout << q1.pop() << endl;
    cout << q1 << endl;

    Queue<Student> s2;
    for(int i = 0; i < 50; i++)
    {   
        Student t(i, i*10);
        s2.push(t);
    }
    
    while(!s2.isEmpty())
    {
        Student ss = s2.front();
        s2.pop();
        cout << ss << endl;
    }
}
void testLoopQueue()
{
    LoopQueue<int> q1;
    for(int i = 0; i < 20; i++)
        q1.push(i);

    cout << q1 << endl;
    cout << q1.front() << endl;
    cout << q1.pop() << endl;
    cout << q1 << endl;

    LoopQueue<Student> s2;
    for(int i = 0; i < 50; i++)
    {   
        Student t(i, i*10);
        s2.push(t);
    }
    
    while(!s2.isEmpty())
    {
        Student ss = s2.front();
        s2.pop();
        cout << ss << endl;
    }
}
void compare(int oc)
{
    Queue<int> q1;
    srand(time(NULL));
    clock_t start1 = clock();
    for(int i = 0; i < oc; i++)
        q1.push(rand());
    for(int i = 0; i < oc; i++)
        q1.pop();
    clock_t end1 = clock();
    cout << "queue take " << (double)(end1 - start1) / CLOCKS_PER_SEC << " s  "  << endl;
    
    LoopQueue<int> q2;
    clock_t start2 = clock();
    for(int i = 0; i < oc; i++)
        q2.push(rand());
    for(int i = 0; i < oc; i++)
        q2.pop();
    clock_t end2 = clock();
    cout << "loopqueue take " << (double)(end2 - start2) / CLOCKS_PER_SEC << " s  "  << endl;
}
int main(void)
{
    cout << "test queue " << endl;
    testQueue();
    
    cout << "test loopqueue  " << endl; 
    testLoopQueue();
    
 //   compare(1000000);
    return 0; 
}
