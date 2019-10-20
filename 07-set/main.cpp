#include "bst_set.hpp"
#include "list_set.hpp"
#include "list_map.hpp"

#include "file_ops.hpp"

#include <vector>
#include <set>

int main(void)
{
    cout << "test bst_set_hpp" << endl;

      // 我们使用文本量更小的共产主义宣言进行试验:)
    //string filename = "communist.txt";
    //string filename = "pride-and-prejudice.txt";
    string filename = "a-tale-of-two-cities.txt";
    vector<string> words;


    if( FileOps::readFile(filename, words) ) { 
        cout << "words size = " << words.size() << endl;
    }

    BSTSet<string> bset;
    ListSet<string> lset;
    set<string> s;
    clock_t start1 = clock();
    for(auto i : words)
    {
        s.insert(i);
    }
    clock_t end1 = clock();
    cout << "set takes " << (double)(end1-start1) / CLOCKS_PER_SEC << "  s" << endl;
    cout << "s count = " << s.size() << endl;

    clock_t start2 = clock();
    for(auto i : words)
    {
        bset.add(i);
    }
    clock_t end2 = clock();
    cout << "bset takes " << (double)(end2-start2) / CLOCKS_PER_SEC << "  s" << endl;
    cout << "bset count = " << bset.size() << endl;
    
    clock_t start3 = clock();
    for(auto i : words)
    {
        lset.add(i);
    }
    clock_t end3 = clock();
    cout << "lset takes " << (double)(end3-start3) / CLOCKS_PER_SEC << "  s" << endl;
    cout << "lset count = " << lset.size() << endl;


    ListMap<string, int> lmap;
    clock_t start4 = clock();
    for(auto i : words)
    {
        if(lmap.contain(i) == true)
            lmap.set(i, lmap.get(i)+1);
        else
            lmap.add(i, 1);
    }
    clock_t end4 = clock();
    cout << "lmap takes " << (double)(end4-start4) / CLOCKS_PER_SEC << "  s" << endl;
    cout << "lmap  count = " << lmap.size() << endl;
    return 0;
}
