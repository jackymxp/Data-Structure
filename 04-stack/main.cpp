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

    ArrayStack<Student> s2(100);
    
    for(int i = 0; i < 50; i++)
    {   
        Student t(i, i * 10);
        s2.push(t);
    }

    cout << s2 << endl; 
    cout << "--------test pop and top---------" << endl;    
   
     while(!s2.empty())
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
    cout << s2 << endl;
    cout << "--------test pop and top---------" << endl;    
    while(!s2.empty())
    {
        Student ss = s2.top();
        s2.pop();
        cout << ss << endl;
    }
}

void compare(int oc)
{
    ArrayStack<int> s1;
    srand(time(NULL));
    clock_t start1 = clock();
    for(int i = 0; i < oc; i++)
         s1.push(rand());
    for(int i = 0; i < oc; i++)
        s1.pop();
    clock_t end1 = clock();
    cout << "take arraystack take " << double(end1 - start1) / CLOCKS_PER_SEC << "  s" << endl;
    
    ListStack<int> s2;
    
    clock_t start2 = clock();
    for(int i = 0; i < oc; i++)
         s2.push(rand());
    for(int i = 0; i < oc; i++)
        s2.pop();
    clock_t end2 = clock();
    cout << "test liststack take " << double(end2 - start2) / CLOCKS_PER_SEC << "  s" << endl;

}


int main(void)
{
    test_array_stack();
    test_list_stack();
    compare(100000000);
    return 0;
}
