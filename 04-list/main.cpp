#include "list.hpp"

int main(void)
{
    cout << "test list" << endl;
    
    List<int> l;
    for(int i = 0; i < 10; i++) 
        l.addFirst(i);


    l.add(1,1000);
    l.addLast(3000);

    
    cout << l << endl;


    return 0;
}
