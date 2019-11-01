#include "hash_table.hpp"
#include "file_ops.hpp"
#include <ctime>

vector<string> words;
int main()
{
    cout << "test hash" << endl;

    // 我们使用文本量更小的共产主义宣言进行试验:)
    //string filename = "communist.txt";
    string filename = "pride-and-prejudice.txt";
    //string filename = "a-tale-of-two-cities.txt";

    if( FileOps::readFile(filename, words) ) { 
        cout << "words size = " << words.size() << endl;
    }
    
    HashTable<string, int>* s = new HashTable<string, int>();

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
    cout << "hash-table" << " takes " << (double)(end1-start1) / CLOCKS_PER_SEC << "  s" << endl;
    cout << "hash-table" << " count = " << s->size() << endl;
    cout << "#################################################" << endl;


    return 0;
}
