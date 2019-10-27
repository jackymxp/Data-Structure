#include "trie.hpp"

int main(void)
{
    cout << "test trie " << endl;

    Trie t;
    t.add("hello");
    t.add("world");
    t.add("hello");
    t.add("he");
    cout << t.size() << endl;

    cout << t.contain("he") << endl;
    cout << t.contain("hello") << endl;
    cout << t.contain("world") << endl;
    cout << t.contain("hahah") << endl;
    return 0;
}