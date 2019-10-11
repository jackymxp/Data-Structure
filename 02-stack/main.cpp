#include "stack.hpp"

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
    Stack<int> s1(30);
    for (int i = 0; i < 10; ++i)
        s1.push(i);
    cout << s1 << endl;
    cout << s1.top() << endl;
    cout << s1.pop() << endl;
    cout << s1 << endl;


    Stack<Student> s2(100);
    
    for(int i = 0; i < 50; i++)
    {   
        Student t(i, i * 10);
        s2.push(t);
    }
    
    while(!s2.isEmpty())
    {
        Student ss = s2.top();
        s2.pop();
        cout << ss << endl;
    }
    return 0;
}
