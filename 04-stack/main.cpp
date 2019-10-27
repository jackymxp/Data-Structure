#include "array_stack.hpp"
#include "list_stack.hpp"
#include <ctime>
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
void testStack(Stack<T>* s, string stackName, int oc)
{
    cout << "start test " << stackName << endl;
    for(int i = 0; i < oc; i++)
    {   
        Student t(i, i);
        cout << "push   " << t << endl;
        s->push(t);
    }
    cout << "--------test pop and top---------" << endl;    
    while(!s->empty())
    {
        Student ss = s->top();
        assert(ss == s->pop());
        cout << "pop   " << ss << endl;
    }
    cout << "test " << stackName << "successed !" << endl;
}

template<typename T>
void compareStack(Stack<T>* s, string stackString, int oc)
{
    clock_t start2 = clock();
    for(int i = 0; i < oc; i++)
         s->push(rand());
    for(int i = 0; i < oc; i++)
        s->pop();
    clock_t end2 = clock();
    cout << "test liststack take " << double(end2 - start2) / CLOCKS_PER_SEC << "  s" << endl;
}

int main(void)
{

    int size = 10;
    Stack<Student>* s1;

    s1 = new ArrayStack<Student>();
    testStack(s1, "ArrayStack", size);

    s1 = new ListStack<Student>();
    testStack(s1, "ListStack", size);



    Stack<int>* s2;
    size = 10000000;

    s2 = new ArrayStack<int>();
    compareStack(s2, "ArrayStack", size);

    s2 = new ListStack<int>();
    compareStack(s2, "ListStack", size);

    return 0;
}
