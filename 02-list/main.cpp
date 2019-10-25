//#include "list.hpp"
#include "dummyList.hpp"
int main(void)
{
    cout << "test list" << endl;
    
    List<int> l;
    for(int i = 0; i < 10; i++) 
        l.addFirst(i);

    cout << l << endl;

    cout << l.contain(1000) << " " << endl;
    cout << l.contain(11) << " " << endl;
    
    l.remove(1);
    cout << l << endl;
    l.removeFirst();
    cout << l << endl;
    l.removeFirst();
    cout << l << endl;
    l.removeLast();
    cout << l << endl;
    return 0;
}
