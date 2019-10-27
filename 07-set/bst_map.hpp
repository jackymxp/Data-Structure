#include <iostream>
#include "map.hpp"

using namespace std;

template<typename K, typename V>
class BSTMap : public Map<K, V>
{
private:
    class Node
    {
    public:
        K k;
        V v;
        Node* left;
        Node* right;
        Node(K k, V v):k(k), v(v), left(NULL), right(NULL){}
        Node(K k, V v, Node* n):k(k), v(v), left(NULL), right(NULL){}
    };
    Node* root;
    int count;
public:
    BSTMap():root(nullptr), count(0){}
    ~BSTMap()
    {
        destroy(root);
    }
    int size(){return count;}
    bool empty(){return count == 0;}
    void add(K k, V v)
    {
        root = add(root, k, v);
    }
    bool contain(K k)
    {
        return getNode(root, k) != NULL;
    }
    V get(K k)
    {
        Node* node = getNode(root, k);
        return node == NULL ? NULL : node->v;
    }
    void set(K k, V v)
    {
        Node* node = getNode(root, k);
        if(node != NULL)
            node->v = v;
    }
    V remove(K k)
    {
        Node* node = getNode(root, k);
        if(node != NULL)
        {
            root = remove(root, k);
            return node->v;
        }
        return NULL;
    }
private:
    Node* remove(Node* node, K k)
    {
        if(node == NULL)
            return NULL;
        if(node->k > k)
        {
            node->left = remove(node->left, k);
        }
        else if(node->k < k)
        {
            node->right = remove(node->right, k);
        }
        else if(node->k == k)
        {
            if(node->left == NULL)
            {
                Node* rightNode = node->right;
                delete node;
                count--;
                return rightNode;
            }
            if(node->right == NULL)
            {
                Node* leftNode = node->left;
                delete node;
                count--;
                return leftNode;
            }
            Node* successor = minimum(node->right);
            successor->right = removeMin(node->right);
            successor->left = node->left;
            delete node;
            return successor;
        }
        return node;
    }
    Node* removeMin(Node* node)
    {
        if(node->left == NULL)
        {
            Node* rightNode = node->right;
            delete node;
            count--;
            return rightNode;
        }
        node->left = removeMin(node->left);
        return node;
    }
    Node* minimum(Node* node)
    {
        if(node->left == NULL)
            return node;
        return minimum(node->left);
    }
    Node* getNode(Node* node, K k)
    {
        if(node == NULL)
            return NULL;
        if(k == node->k)
            return node;
        else if(k < node->k)
            return getNode(node->left, k);
        else if(k > node->k)
            return getNode(node->right, k);
        return NULL;
    }
    Node* add(Node* node, K k, V v)
    {
        if(node == nullptr)
        {
            count++;
            return new Node(k, v);
        }
        if(node->k < k)
            node->right = add(node->right, k, v);
        else if(node->k > k)
            node->left = add(node->left, k, v);
        else
            node->v = v;
        return node;
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


