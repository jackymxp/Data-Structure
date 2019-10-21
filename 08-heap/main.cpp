#include "heap.hpp"
#include "priority_queue.hpp"
#include <vector>


double testHeapift(vector<int> arr, bool isHeapify)
{
    clock_t start1 = clock();
    if(isHeapify)
    {
        MaxHeap<int> mp1(arr);
    }
    
    else
    {
        MaxHeap<int> mp2;
        for(auto i : arr)
            mp2.add(i);
    }
    clock_t end1 = clock();
    return (double)(end1 - start1) / CLOCKS_PER_SEC;
}

int main(void)
{
    int oc = 100000000;
#if 0
    MaxHeap<int> mp;
    srand(time(NULL));
    for(int i = 0; i < oc; i++)
        mp.add(rand() % INT_MAX);
    vector<int> arr;
    for(int i = 0; i < oc; i++)
        arr.push_back(mp.extractMax());
    
    for(int i = 0; i < arr.size()-1; i++)
        if(arr[i] < arr[i+1])
            cout << "heap error..." << endl;
    
    cout << "heap is right!!!" << endl;
#endif

    vector<int> tarr;
    for(int i = 0; i < oc; i++)
        tarr.push_back(rand() % INT_MAX);

    double time2 = testHeapift(tarr, false);
    cout << "Without Heapift take " << time2 << " s" << endl;


    double time1 = testHeapift(tarr, true);
    cout << "With Heapift take " << time1 << " s" << endl;

    return 0;
}