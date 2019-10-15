#include "array_stack.hpp"
#include "list_stack.hpp"

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


void test_array_stack()
{
    cout << "test_array_stack" << endl;
    ArrayStack<int> s1(30);
    for (int i = 0; i < 10; ++i)
        s1.push(i);
    cout << s1 << endl;
    cout << s1.top() << endl;
    cout << s1.pop() << endl;
    cout << s1 << endl;


    ArrayStack<Student> s2(100);
    
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
}
void test_list_stack()
{
    cout << "test_list_stack" << endl;
    ListStack<int> s1;
    for (int i = 0; i < 10; ++i)
        s1.push(i);
    cout << s1 << endl;
    cout << s1.top() << endl;
    cout << s1.pop() << endl;
    cout << s1 << endl;


    ArrayStack<Student> s2;
    
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
}
int main(void)
{
    test_array_stack();
    test_list_stack();

    return 0;
}
