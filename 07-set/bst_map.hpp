#include <iostream>

using namespace std;

template<typename K, typename V>
class BSTMap
{
private:
    class Node
    {
    public:
        K k;
        V v;
        Node* next;
        Node(K k, V v):k(k), v(v), next(NULL){}
        Node(K k, V v, Node* n):k(k), v(v), next(n){}
        Node():next(NULL) {}
    };
    Node* root;
    int count;
public:
    BSTMap():root(nullptr), count(0){}
    ~BSTMap()
    {
        destroy(root);
    }
    void size(){return count;}
    void empty(){return count == 0;}
    void add(K k, V v)
    {
        root = add(root, k, v);
    }
private:
    Node* add(Node* node, K k, V v)
    {
        if(node == nullptr)
        {
            count++;
            return new Node(k, v);
        }
        if(node->k < k)
        {
            node->right = add(node->right, k, v);
            return node;
        }
        else
        {
            node->left = add(node->left, k, v);
            return node;
        }
    }
    
    void destroy(Node* node)
    {
        if(node == nullptr)
            return ;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

};


