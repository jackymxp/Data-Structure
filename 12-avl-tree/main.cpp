#include "avl-tree.hpp"
#include "file_ops.hpp"
#include "../07-set/bst_map.hpp"
#include <ctime>
#include <string> 
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    cout << "test avl-tree" << endl;

    // 我们使用文本量更小的共产主义宣言进行试验:)
    string filename = "communist.txt";
    //string filename = "pride-and-prejudice.txt";
    //string filename = "a-tale-of-two-cities.txt";
    vector<string> words;

    if( FileOps::readFile(filename, words) ) { 
        cout << "words size = " << words.size() << endl;
        sort(words.begin(), words.end());
    }

    AVLTree<string, int> atree;
    clock_t start1 = clock();
    for(auto i : words)
    {
        if(atree.contain(i) == true)
            atree.set(i, atree.get(i)+1);
        else
            atree.add(i, 1);
    }
    for(string word : words)
        atree.contain(word);

    for(string word : words)
    {
        atree.remove(word);
        if(!atree.isBalance() || !atree.isBST())
            throw  "fuck this error !";
    }
        
    clock_t end1 = clock();
    assert(atree.size() == 0);

    cout << "atree-tree pride takes " << atree.get("pride") << "  times" << endl;
    cout << "atree-tree takes " << (double)(end1-start1) / CLOCKS_PER_SEC << "  s" << endl;
    cout << "atree-tree  count = " << atree.size() << endl;
    cout << "atree-tree  is or not bst = " << atree.isBST() << endl;
    cout << "atree-tree  is balance = " << atree.isBalance() << endl;
    cout << "test avl-tree finished !" << endl;

    BSTMap<string, int> bmap;
    clock_t start5 = clock();
    for(auto i : words)
    {
        if(bmap.contain(i) == true)
            bmap.set(i, bmap.get(i)+1);
        else
            bmap.add(i, 1);
    }
    for(string word : words)
        bmap.contain(word);


    for(string word : words)
    {
        bmap.remove(word);
    }
    clock_t end5 = clock();
    cout << "bmap pride takes " << bmap.get("pride") << "  times" << endl;
    cout << "bmap takes " << (double)(end5-start5) / CLOCKS_PER_SEC << "  s" << endl;
    cout << "bmap  count = " << bmap.size() << endl;
    
    return 0;
}