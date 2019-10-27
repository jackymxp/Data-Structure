#include "avl_tree.hpp"
#include "file_ops.hpp"
#include "../07-set/bst_map.hpp"

#include <ctime>
#include <string> 
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> words;

template<typename MAP>
void testMap(MAP map, string mapName, int removeSize, string findStr)
{
    cout << "start test " << mapName << endl;
    clock_t start1 = clock();
    for(auto i : words)
    {
        if(map.contain(i) == true)
            map.set(i, map.get(i)+1);
        else
            map.add(i, 1);
    }
    for(string word : words)
        map.contain(word);
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    for(int i = 0 ; i < removeSize ; i++)
    {
        map.remove(words[i]);
    }
    
    clock_t end1 = clock();

    cout << mapName << " takes " << (double)(end1-start1) / CLOCKS_PER_SEC << "  s" << endl;
    cout << mapName << " total word size = " << map.size() << endl;
    cout << mapName << "  find  " << findStr << "  " << map.get(findStr) << "  times" << endl;
    cout << "test " << mapName << " finished !" << endl;
}



int main(void)
{
    // 我们使用文本量更小的共产主义宣言进行试验:)
    string filename = "communist.txt";
    //string filename = "pride-and-prejudice.txt";
    //string filename = "a-tale-of-two-cities.txt";


    if( FileOps::readFile(filename, words) ) { 
        cout << "words size = " << words.size() << endl;
        //sort(words.begin(), words.end());
    }


    string findStr = "the";
    int removeSize = 10;
    AVLTree<string, int> atree;
    BSTMap<string, int> bmap;


    testMap(atree, "AVLTree", removeSize, findStr);
    cout << "=================" << endl;
    testMap(bmap, "BSTMap", removeSize, findStr);
    cout << "###################" << endl;
    return 0;
}