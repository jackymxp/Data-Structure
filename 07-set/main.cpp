#include "list_set.hpp"
#include "list_map.hpp"
#include "bst_set.hpp"
#include "bst_map.hpp"
#include "avl_set.hpp"
#include "avl_map.hpp"
#include "rbtree_map.hpp"
#include "rbtree_set.hpp"
#include "file_ops.hpp"

#include <vector>
#include <set>
#include <ctime>
#include <algorithm>

vector<string> words;


template<typename T>
void testSet(Set<T>* s, string setName)
{
    clock_t start1 = clock();

    for(auto i : words)
        s->add(i);
        
    for(auto i : words)
        assert(s->contain(i) == true);
    
    for(int i = 0; i < 10; i++)
        s->remove(words[i]);
    ///assert(s->size() == 0);
    ///assert(s->empty() == true);

    clock_t end1 = clock();
    cout << setName << " takes " << (double)(end1-start1) / CLOCKS_PER_SEC << "  s" << endl;
    cout << setName << " count = " << s->size() << endl;
    cout << "=================================================" << endl;
}

template<typename K, typename V>
void testMap(Map<K, V>* s, string mapName)
{
    clock_t start1 = clock();

    for(auto i : words)
    {
        if(s->contain(i) == true)
            s->set(i, s->get(i)+1);
        else
            s->add(i, 1);
    }

    for(auto i : words)
        assert(s->contain(i) == true);

    for(int i = 0; i < 30; i++)
        s->remove("words[i]");
    ///assert(s->size() == 0);
    ///assert(s->empty() == true);

    clock_t end1 = clock();
    cout << mapName << " takes " << (double)(end1-start1) / CLOCKS_PER_SEC << "  s" << endl;
    cout << mapName << " count = " << s->size() << endl;
    cout << "#################################################" << endl;

}
int main(void)
{

    // 我们使用文本量更小的共产主义宣言进行试验:)
    //string filename = "communist.txt";
    string filename = "pride-and-prejudice.txt";
    //string filename = "a-tale-of-two-cities.txt";

    if( FileOps::readFile(filename, words) ) { 
        cout << "words size = " << words.size() << endl;
    }

   // sort(words.begin(), words.end());

    Set<string>* s;

    //s = new ListSet<string>;
    //testSet(s, "ListSet");

    s = new BSTSet<string>;
   // testSet(s, "BSTSet");

    s = new AVLSet<string>;
    testSet(s, "AVLSet");

    s = new RBTreeSet<string>;
    testSet(s, "RBTreeSet");


    Map<string, int>* m;

    //m = new ListMap<string, int>;
    //testMap(m, "ListMap");

    m = new BSTMap<string, int>;
  //  testMap(m, "BSTMap");

    m = new AVLMap<string, int>;
    testMap(m, "AVLMap");
    
    m = new RBTreeMap<string, int>;
    testMap(m, "RBTreeMap");

    return 0;
}
