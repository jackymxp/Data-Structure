#include "array.hpp"

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
    cout << "test array " << endl;
    Array<int> a;
    for(int i = 0; i < 20; i++)
        a.add(0, i);
    cout << a << endl;
    cout << a.remove(10) << endl;
    cout << a << endl;
    cout << a.removeFirst() << endl;
    cout << a << endl;
    cout << a.removeLast() << endl;
    cout << a << endl;
    cout <<"a[2] = " << a[2] << endl;


    Array<Student> s;
    for(int i = 0; i < 50; i++)
    {   
        Student t(i*10, i * 10);
        s.add(0, t);
    }
    cout << s << endl;
    Student t = s[0];
    cout << t << endl;

    const Array<int> b;
    cout << b.size() << endl;
    cout << b.empty() << endl;



}
