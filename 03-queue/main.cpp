#include "queue.hpp"

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
int main(void)
{
    cout << "test queue " << endl;
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
