#ifndef _RB_TREE_H_
#define _RB_TREE_H_


#include <iostream>

using namespace std; 

template<typename K, typename V>
class RBTree 
{
private:
    static const bool RED = true;
    static const bool BLACK = false;
    struct Node
    {
        K key;
        V value;
        Node* left;
        Node* right;
        bool color;
        //由于在2-3树中添加元素的时候总是要和其他节点进行融合，在转换为红黑树拆分的时候，将其标记为红色，所以默认为红色就可以
        Node(K k, V v) : key(k), value(v), color(RED), left(NULL), right(NULL){}
        Node() {}
    };
    Node* root;
    int count;
public:
    RBTree() : root(NULL), count(0){}
    ~RBTree(){destroy(root);}
    int size() const{return count;}
    bool empty() const {return count == 0;}
    void add(K key, V value)
    {
        root = add(root, key, value);
        root->color = BLACK;
    }
    bool contain(K key){return getNode(root, key) != NULL;}
    V get(K key){
        Node* node = getNode(root, key);
        if(node != NULL){return node->value;}
        else return NULL;
    }
    void set(K key, V value){
        Node* node = getNode(root, key);
        if(node != NULL){node->value = value;}
    }
    V remove(K key){
        Node* node = getNode(root, key);
        if(node != NULL){
            root = remove(root,key);
            return node->value;
        }
        return NULL;
    }
private:
    Node* minimum(Node* node)
    {
        if(node == NULL)
            return NULL; 
        if(node->left == NULL)
            return node;
        return minimum(node->left);
    }
    Node* removeMin(Node* node)
    {
        if(node == NULL)    return NULL;
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
    Node* remove(Node* node, K key){
        if(node == NULL)
            return NULL;
        if(node->key < key)
        {
            node->right = remove(node->right,key);
            return node;
        }
        else if(node->key > key)
        {
            node->left = remove(node->left,key);
            return node;
        }
        else if(node->key == key)
        {
            if(node->right == NULL)
            {
                Node* leftNode = node->left;
                delete node;
                count--;
                return leftNode;
            }
            if(node->left == NULL)
            {
                Node* rightNode = node->right;
                delete node;
                count--;
                return rightNode;
            }
            Node* successor = minimum(node->right);
            successor->left = node->left;
            successor->right = removeMin(node->right);
            delete node;
            return successor;
        }
        return node;
    }

    Node* getNode(Node* node, K key)
    {
        if(node == NULL) return NULL;
        if(node->key == key) return node;
        else if(node->key > key) return getNode(node->left, key);
        else if(node->key < key) return getNode(node->right, key);
        return NULL;
    }
    //   node                     x
    //  /   \     左旋转         /  \
    // T1   x   --------->   node   T3
    //     / \              /   \
    //    T2 T3            T1   T2
    Node* leftRotate(Node* node)
    {
        Node* x = node->right;

        node->right = x->left;
        x->left = node;

        x->color = node->color;
        node->color = RED;

        return x;
    }
    //颜色翻转
    void filpColor(Node* node)
    {
        node->color = RED;
        node->left->color = BLACK;
        node->right->color = BLACK;
    }
    //     node                   x
    //    /   \     右旋转       /  \
    //   x    T2   ------->   y   node
    //  / \                       /  \
    // y  T1                     T1  T2
    Node* rightRotate(Node* node)
    {
        Node* x = node->left;

        node->left = x->right;
        x->right = node;

        x->color = node->color;
        node->color = RED; // 表示要和父亲融合在一起

        return x;
    }
    bool isRed(Node* node)
    {
        return node == NULL ? BLACK : node->color == RED;
    }
    Node* add(Node* node, K key, V value)
    {
        if(node == NULL)
        {
            count++;
            return new Node(key, value); //默认为红色
        }
        if(node->key < key)
            node->right = add(node->right, key, value);
        else if(node->key > key)
            node->left = add(node->left, key, value);
        else if(node->key == key)
            node->key = key;
        //在这里维护红黑树的性质
        if(isRed(node->right) && !isRed(node->left))
            node = leftRotate(node);
        
        if(isRed(node->left) && isRed(node->left->left))
            node = rightRotate(node);
        
        if(isRed(node->right) && isRed(node->left))
            filpColor(node);
        

        return node;
    }
    void destroy(Node* node)
    {
        if(node == NULL)
            return ;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
};






#endif /* _RB_TREE_H_ */


