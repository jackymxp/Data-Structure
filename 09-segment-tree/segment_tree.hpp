#include <iostream>
#include <vector>

using namespace std;


template<typename T>
class SegmentTree
{
private:
    T (*merge)(T, T);
    vector<T> data;
    vector<T> tree;
    inline int leftChild(int index){return index * 2 + 1;}
    inline int rightChild(int index){return index * 2 + 2;}
    void buildSegmentTree(int index, int left, int right)
    {
        if(left == right)
        {
            tree[index] = data[left];
            return;
        }
        int leftIndex = leftChild(index);
        int rightIndex = rightChild(index);
        
        int mid = ((right - left) >> 1) + left;
        //[left, mid]
        //[mid+1, right]
        buildSegmentTree(leftIndex, left, mid);
        buildSegmentTree(rightIndex, mid +1, right);

        tree[index] = merge(tree[leftIndex], tree[rightIndex]);
    }
public:
    SegmentTree(vector<T> arr, T (*merge)(T, T))
    {
        data = arr;
        tree = vector<T>(4 * arr.size(), NULL); //使用线段树，需要开4倍的空间
        this->merge = merge;
        buildSegmentTree(0, 0, arr.size() - 1);
    }
    int size(){return data.size();}
    T get(int index)
    {
        assert(index >= 0 && index < data.size());
        return data[index];
    }
    T query(int queryL, int queryR)
    {
        assert(queryL >= 0 && queryL < data.size());
        assert(queryR >= 0 && queryR < data.size());
        assert(queryL <= queryR);
        return query(0, 0, data.size() - 1, queryL, queryR);
    }
private:
    //在index,[left, right]中查找  [queryL, queryR]
    T query(int index, int left, int right, int queryL, int queryR)
    {
        if(left == queryL && right == queryR)
            return tree[index];
        int leftIndex = leftChild(index);
        int rightIndex = rightChild(index);
        int mid = ((right - left) >> 1) + left;
        if(queryL >= mid+1)
            return query(rightIndex, mid+1, right, queryL, queryR);
        else if(queryR <= mid)
            return query(leftIndex, left, mid, queryL, queryR);
        else
        {
            T leftRes = query(leftIndex, left, mid, queryL, mid);
            T rightRes = query(rightIndex, mid+1, right, mid+1, queryR);
            return merge(leftRes, rightRes);
        }
    }
    template<typename T1>
    friend ostream& operator<<(ostream&os, SegmentTree<T1>& st);
};

    template<typename T>
    ostream& operator<<(ostream&os, SegmentTree<T>& st)
    {
        os << "[";
        for(int i = 0; i < st.tree.size(); i++)
        {
            if(st.tree[i] == NULL)
                os << "NULL";
            else
                os << st.tree[i] ;
            if(i != st.tree.size() - 1)
                os << ",  ";
        }
        os << "]";
        return os;
    }