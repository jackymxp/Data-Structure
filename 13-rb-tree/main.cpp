#include "rb_tree.hpp"
#include "file_ops.hpp"
#include <cassert>
#include <ctime>

vector<string> words;


int main(void)
{
    cout << "rb_tree" << endl;
    // 我们使用文本量更小的共产主义宣言进行试验:)
    //string filename = "communist.txt";
    string filename = "pride-and-prejudice.txt";
    //string filename = "a-tale-of-two-cities.txt";

    if( FileOps::readFile(filename, words) ) { 
        cout << "words size = " << words.size() << endl;
    }

    RBTree<string, int> rbtree;

    clock_t start1 = clock();
    for(auto word : words)
    {
        if(rbtree.contain(word) == false)
            rbtree.add(word, 1);
        else{
            rbtree.set(word, rbtree.get(word) + 1);
        }
    }

    for(auto i : words)
        assert(rbtree.contain(i) == true);

    clock_t end1 = clock();
    cout << "rbtree" << " takes " << (double)(end1-start1) / CLOCKS_PER_SEC << "  s" << endl;
    cout << "rbtree" << " count = " << rbtree.size() << endl;
    cout << "#################################################" << endl;
}