#include "union-find.hpp"
#include <ctime>

void testUnionFind(UnionFind* uf, int size, string ufName)
{
    srand(time(NULL));
    clock_t start = clock();

    for(int i = 0; i < size; i++)
    {
        int a = rand() % size;
        int b = rand() % size;
        uf->unionElement(a, b);
    }
    for(int i = 0; i < size; i++)
    {
        int a = rand() % size;
        int b = rand() % size;
        uf->isConnect(a, b);
    } 

    clock_t end = clock();
    cout << "test " << uf->size() << "   " << ufName << "  take  " << (double)(end-start) / CLOCKS_PER_SEC << "  s" << endl;
}


int main(void)
{
    cout << "test union-find" << endl;

    int size = 100000000 / 30;
    UnionFind* uf;

    // uf = new UF1(size);
    // testUnionFind(uf, size, "UF1");

    // uf = new UF2(size);
    // testUnionFind(uf, size, "UF2");

    uf = new UF3(size);
    testUnionFind(uf, size, "UF3");

    uf = new UF4(size);
    testUnionFind(uf, size, "UF4");

    uf = new UF5(size);
    testUnionFind(uf, size, "UF5");

    uf = new UF6(size);
    testUnionFind(uf, size, "UF6");
    return 0;
}