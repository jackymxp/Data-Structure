#include "stack.hpp"

int main(void)
{
    Stack<int> s(30);
    for (int i = 0; i < 10; ++i)
        s.push(i);
    cout << s << endl;
    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s << endl;
    return 0;
}