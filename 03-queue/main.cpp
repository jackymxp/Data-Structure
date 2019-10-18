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

void testArrayQueue()
{
    ArrayQueue<int> q1;
    for(int i = 0; i < 20; i++)
        q1.push(i);

    cout << q1 << endl;
    cout << q1.front() << endl;
    cout << q1.pop() << endl;
    cout << q1 << endl;

    ArrayQueue<Student> s2;
    for(int i = 0; i < 50; i++)
    {   
        Student t(i, i*10);
        s2.push(t);
    }
    cout << s2 << endl;    
    while(!s2.empty())
    {
        Student ss = s2.front();
        s2.pop();
        cout << ss << endl;
    }
}
void testListQueue()
{
    ListQueue<int> q1;
    for(int i = 0; i < 20; i++)
        q1.push(i);

    cout << q1 << endl;
    cout << q1.front() << endl;
    cout << q1.pop() << endl;
    cout << q1 << endl;

    ListQueue<Student> s2;
    for(int i = 0; i < 50; i++)
    {   
        Student t(i, i*10);
        s2.push(t);
    }
    cout << s2 << endl;    
    while(!s2.empty())
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
    
    while(!s2.empty())
    {
        Student ss = s2.front();
        s2.pop();
        cout << ss << endl;
    }
}
void compare(int oc)
{
    ArrayQueue<int> q1;
    srand(time(NULL));
    clock_t start1 = clock();
    for(int i = 0; i < oc; i++)
        q1.push(rand());
    for(int i = 0; i < oc; i++)
        q1.pop();
    clock_t end1 = clock();
    cout << "array_queue take " << (double)(end1 - start1) / CLOCKS_PER_SEC << " s  "  << endl;
    
    LoopQueue<int> q2;
    clock_t start2 = clock();
    for(int i = 0; i < oc; i++)
        q2.push(rand());
    for(int i = 0; i < oc; i++)
        q2.pop();
    clock_t end2 = clock();
    cout << "loopqueue take " << (double)(end2 - start2) / CLOCKS_PER_SEC << " s  "  << endl;
    
    ListQueue<int> q3;
    clock_t start3 = clock();
    for(int i = 0; i < oc; i++)
        q3.push(rand());
    for(int i = 0; i < oc; i++)
        q3.pop();
    clock_t end3 = clock();
    cout << "list_queue take " << (double)(end3 - start3) / CLOCKS_PER_SEC << " s  "  << endl;
}
int main(void)
{
  //  cout << "test array_queue " << endl;
  //  testArrayQueue();
    
    cout << "test list_queue " << endl;
    testListQueue();
    
   // cout << "test loopqueue  " << endl; 
   // testLoopQueue();
    
  // compare(100000);


    ListQueue<int> q;
    q.push(1);
    q.pop();
    q.push(2);
    cout << q.front() << endl;
    return 0; 
}
