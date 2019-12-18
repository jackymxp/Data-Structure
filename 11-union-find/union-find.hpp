#include <iostream>
#include <vector>
#include "../01-array/array.hpp"
#include <cassert>

using namespace std;

class UnionFind
{
public:
    virtual int size() const = 0;
    virtual void unionElement(int p, int q) = 0 ;
    virtual bool isConnect(int p, int q) const  = 0 ;
};

class UF1 : public UnionFind
{
private:
    //vector<int> id;
    Array<int> id;
    int find(int p) const
    {
        assert(p >= 0 && p < id.size());
        return id[p];
    }
    
public:
    UF1(int size)
    {
        //id = vector<int>(size, 0);
        id = Array<int>(size, 0);
        for(int i = 0; i < size; i++)
            id[i] = i;
    }
    int size() const {return id.size();}

    bool isConnect(int p, int q) const
    {
        return find(p) == find(q);
    }
    void unionElement(int p, int q)
    {
        int pID = find(p);
        int qID = find(q);
        if(pID == qID)
            return ;
        int len = id.size();
        for(int i = 0; i < len; i++)
        {
            if(id[i] == qID)
                id[i] = pID;
        }
    }
};


class UF2 : public UnionFind
{
private:
    //vector<int> parent;
    Array<int> parent;
    int find(int index) const
    {
        assert(index >= 0 && index < parent.size());
        while(index != parent[index])
            index = parent[index];
        return index;
    }
public:
   UF2(int size)
   {
       //parent = vector<int>(size, 0);
       parent = Array<int>(size, 0);
       for(int i = 0; i < size; i++)
            parent[i] = i;
   }
   int size() const {return parent.size();}
   bool isConnect(int p, int q) const 
   {
        return find(p) == find(q);
   }
   //O(h),h是树的高度
   void unionElement(int p, int q)
   {
        int pID = find(p);
        int qID = find(q);
        if(pID == qID)
            return ;
        parent[pID] = qID;
   }
};


class UF3 : public UnionFind // 基于size的优化
{
private:
    //vector<int> parent;
    //vector<int> height;
    Array<int> parent;
    Array<int> count;
    int find(int index) const
    {
        assert(index >= 0 && index < parent.size());
        while(index != parent[index])
            index = parent[index];
        return index;
    }
public:
    UF3(int size)
    {
        //parent = vector<int>(size, 0);
        //height = vector<int>(size, 1);
        parent = Array<int>(size, 0);
        count = Array<int>(size, 1);
        for(int i = 0; i < size; i++)
            parent[i] = i;
    }
    int size() const {return parent.size();}
    bool isConnect(int p, int q) const
    {
        return find(p) == find(q);
    }
    void unionElement(int p, int q)
    {
        int pID = find(p);
        int qID = find(q);
        if(pID  ==  qID)
            return ;
        if(count[pID] < count[qID])
        {
            parent[pID] = qID;
            count[qID] += count[pID];
        }
        else 
        {
            parent[qID] = pID;
            count[pID] += count[qID];
        }
    }
};

class UF4 : public UnionFind  //基于height的优化策略
{
private:
    Array<int> parent;
    Array<int> height;
    int find(int index) const
    {
        assert(index >= 0 && index < parent.size());
        while(index != parent[index])
            index = parent[index];
        return index;
    }
public:
    UF4(int size)
    {
        parent = Array<int>(size, 0);
        for(int i = 0; i < size; i++)
            parent[i] = i;
        height = Array<int>(size, 1);
    }
    int size() const {return parent.size();}
    bool isConnect(int p, int q) const
    {
        return find(p) == find(q);
    }
    void unionElement(int p, int q)
    {
        int pID = find(p);
        int qID = find(q);
        if(pID == qID)
            return ;
        if(height[pID] < height[qID])
            parent[pID] = qID;
        else if(height[qID] < height[pID])
            parent[qID] = pID;
        else if(height[pID] == height[qID])
        {
            parent[pID] = qID;
            height[qID] += 1;
        }
        else
        {
            cout << "fuck this error" << endl;
        }
        
    }
};

class UF5 : public UnionFind  //基于路径压缩的优化策略
{
private:
    Array<int> parent;
    Array<int> height;
    int find(int index) const
    {
        assert(index >= 0 && index < parent.size());
        while(index != parent[index])
        {
            parent[index] = parent[parent[index]]; //只增加这一行代码
            index = parent[index];
        }
        return index;
    }
public:
    UF5(int size)
    {
        parent = Array<int>(size, 0);
        for(int i = 0; i < size; i++)
            parent[i] = i;
        height = Array<int>(size, 1);
    }
    int size() const {return parent.size();}
    bool isConnect(int p, int q) const
    {
        return find(p) == find(q);
    }
    void unionElement(int p, int q)
    {
        int pID = find(p);
        int qID = find(q);
        if(pID == qID)
            return ;
        if(height[pID] < height[qID])
            parent[pID] = qID;
        else if(height[qID] < height[pID])
            parent[qID] = pID;
        else if(height[pID] == height[qID])
        {
            parent[pID] = qID;
            height[qID] += 1;
        }
        else
        {
            cout << "fuck this error" << endl;
        }
        
    }
};


class UF6 : public UnionFind  //基于路径压缩的优化策略
{
private:
    vector<int> parent;
    vector<int> height;
    int find(int index)
    {
        assert(index >= 0 && index < parent.size());
        if(index != parent[index])
            parent[index] = find(parent[index]);
        return index;
    }
    bool isConnect(int p, int q) const{return true;} //为了继承父类中的纯虚函数，加上这个才不报错
public:
    UF6(int size)
    {
        parent = vector<int>(size, 0);
        for(int i = 0; i < size; i++)
            parent[i] = i;
        height = vector<int>(size, 1);
    }
    int size() const {return parent.size();}
    bool isConnect(int p, int q)
    {
        return find(p) == find(q);
    }
    void unionElement(int p, int q)
    {
        int pID = find(p);
        int qID = find(q);
        if(pID == qID)
            return ;
        if(height[pID] < height[qID])
            parent[pID] = qID;
        else if(height[qID] < height[pID])
            parent[qID] = pID;
        else if(height[pID] == height[qID])
        {
            parent[pID] = qID;
            height[qID] += 1;
        }
        else
        {
            cout << "fuck this error" << endl;
        }
        
    }
};
