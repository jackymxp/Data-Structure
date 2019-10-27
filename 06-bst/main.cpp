#include "bst.hpp"
#include <ctime>

int main(void)
{
    BST<int> bst;
    srand(time(NULL));
    for(int i = 0; i < 10; i++)
    {
        int t= rand() % 20;
        cout << t << "  ";
        bst.add(i);
    }



    cout << "bst.size() = " << bst.size() << endl;
    cout << "inOrder" << endl;
    bst.inOrder();
    cout << endl;
#if 1  
    cout << "preOrderNoRec" << endl;
    bst.preOrderNoRec();
    cout << endl;

    cout << "preOrder" << endl;
    bst.preOrder();
    


    cout << "postOrder" << endl;
    bst.postOrder();

    cout << "levelOrder" << endl;
    bst.levelOrder();
#endif

    cout << "bst.minimum()---->" << bst.minimum() << endl;
    cout << "bst.maximum()---->" << bst.maximum() << endl;


    cout << "bst.removeMax()---->" << bst.removeMax() <<  endl;
    bst.inOrder();
    cout << endl;
    cout << "bst.removeMin()---->" <<bst.removeMin() <<  endl;
    bst.inOrder();
    cout << endl;

    cout << "contain(7)" << endl;
    if(bst.contain(7) == true)
        cout << "contain 7" << endl;

    cout << "bst.size() = " << bst.size() << endl;
    cout << "remove(7)" << endl;
    bst.remove(7);
    cout << "bst.size() = " << bst.size() << endl;
    bst.inOrder();
    cout << endl;

    return 0;
}