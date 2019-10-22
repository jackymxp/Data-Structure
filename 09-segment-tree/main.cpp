#include "segment_tree.hpp"


int merge(int a, int b)
{
    return a + b;
}
int main(void)
{
    vector<int> arr {1,2,3,4,5,6,7};
    SegmentTree<int> st(arr, merge);

    cout << st << endl;
    return 0;
}