#include <iostream>
#include <vector>

using namespace std;

template <typename K, typename V>
class AVLTree
{
private:
    struct Node
    {
        int height;
        K key;
        V value;
        Node* left;
        Node* right;
        Node(K key, V value) : height(1), key(key), value(value), left(NULL), right(NULL){}
    };
    Node* root;
    int count;
public:
    AVLTree() : root(NULL), count(0){}
    ~AVLTree(){destroy(root);}
    int size() const{return count;}
    bool empty(){return count == 0;}
    void add(K key, V value) { root = add(root, key, value);}
    bool contain(K key){return getNode(root, key) != NULL;}
    V get(K key){
        Node* node = getNode(root, key);
        return node == NULL ? NULL : node->value;
    }
    void set(K key, V value)
    {
        Node* node = getNode(root, key);
        if(node != nullptr)
            node->value = value;
    }
    V remove(K key)
    {
        Node* node = getNode(root, key);
        if(node != NULL)
        {
            root = remove(root, key);
            return node->value;
        }
        return NULL;
    }
    bool isBST()
    {
        vector<K> inRes;
        inOrder(root, inRes);
        int len = inRes.size();
        for(int i = 1; i < len; ++i)
            if(inRes[i-1] > inRes[i])
                return false;
        return true;
    }
    bool isBalance()
    {
        //return isBalance(root);
        return isBalance(root) >= 0;
    }
private:
#if 0
    //O(n^2)
    bool isBalance(Node* node)
    {
        if(node == NULL)
            return true;
        int balanceFactor = getBalanceFactor(node);
        if(abs(balanceFactor) > 1)
            return false;
        return isBalance(node->left) && isBalance(node->right);
    }
#else
    //O(n)
    int isBalance(Node* node)
    {
        if(node == NULL)
            return 0;
        int leftHight = isBalance(node->left);
        if(leftHight < 0)
            return leftHight;
        int rightHight = isBalance(node->right);
        if(rightHight < 0)
            return rightHight;
        if(abs(leftHight - rightHight) < 2)
            return max(leftHight, rightHight) + 1;
        else
            return -1;
    }
#endif 
    void inOrder(Node* node, vector<K>& inRes)
    {
        if(node == NULL)
            return;
        inOrder(node->left, inRes);
        inRes.push_back(node->key);
        inOrder(node->right, inRes);
    }
    int getHeight(Node* node)
    {
        return node == NULL ? 0 : node->height;
    }
    //获得平衡因子
    int getBalanceFactor(Node* node)
    {
        if(node == NULL)
            return 0; 
        return getHeight(node->left) - getHeight(node->right);
    }
    Node* remove(Node* node, K key)
    {
        if(node == nullptr)
            return nullptr;
        Node* retNode;
        if(node->key > key)
        {
            node->left = remove(node->left, key);
            retNode = node;
        }
        else if(node->key < key)
        {
            node->right = remove(node->right, key);
            retNode = node;
        }
        else if(node->key == key)
        {
            if(node->left == NULL)
            {
                Node* rightNode = node->right;
                delete node;
                count--;
                retNode = rightNode;
            }
            else if(node->right == NULL)
            {
                Node* leftNode = node->left;
                delete node;
                count--;
                retNode = leftNode;
            }
            else
            {
                Node* successor = minimum(node->right);
                successor->left = node->left;
                //由于在removeMin中可能导致失去平衡，所以可以在removeMin中，添加平衡的调整，或者，复用remove函数，这里面有平衡调整
                //successor->right = removeMin(node->right);
                successor->right = remove(node->right, successor->key);
                delete node;
                retNode = successor;
            }
        }
        if(retNode == NULL)
            return NULL;
        //维护 retNode 平衡
        //先更新高度
        retNode->height = max(getHeight(retNode->left), getHeight(retNode->right)) + 1;
        int balanceFactor = getBalanceFactor(retNode);
        if(abs(balanceFactor) > 1)
        {
           // cout << "retNode balanceFactor = " << balanceFactor <<  endl;
        }

        //平衡维护
        //        y      
        //       / \     
        //      x   T4   
        //     / \       
        //    z   T3     
        //   / \
        // T1   T2
        if(balanceFactor > 1 && getBalanceFactor(retNode->left) >= 0)  // LL 情况
        {
            return rightRotate(retNode);
        }
        //    y     
        //  /  \    
        // T1   x   
        //     / \  
        //   T2   z  
        //       / \
        //      T3 T4
        if(balanceFactor < -1 && getBalanceFactor(retNode->right) <= 0) // RR 情况
        {
            return leftRotate(retNode);
        }
        //        y      
        //       / \     
        //      x   T4   
        //     / \       
        //    T3  z   
        //        / \
        //      T1   T2
        if(balanceFactor > 1 && getBalanceFactor(retNode->left) < 0) // LR 情况
        {
            retNode->left = leftRotate(retNode->left);
            return rightRotate(retNode);
        }
        //   y     
        //  /  \    
        // T1   x   
        //     / \  
        //     z  T2
        //    / \
        //    T3 T4 
        //      
        //      
        if(balanceFactor < -1 && getBalanceFactor(retNode->right) > 0) // RL 情况
        {
            retNode->right = rightRotate(retNode->right);
            return leftRotate(retNode);
        }

        return retNode;
    }
    Node* minimum(Node* node)
    {
        if(node->left == NULL)
            return node;
        return minimum(node->left);
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
    Node* getNode(Node* node, K key)
    {
        if(node == nullptr)
            return node;
        if(node->key == key)
            return node;
        else if(key < node->key)
            return getNode(node->left, key);
        else if(key > node->key)
            return getNode(node->right, key);
        return nullptr;        
    }

    //RR
    // 对节点y进行向左旋转操作，返回旋转后新的根节点x
    //    y                             x
    //  /  \                          /   \
    // T1   x      向左旋转 (y)       y     z
    //     / \   - - - - - - - ->   / \   / \
    //   T2  z                     T1 T2 T3 T4
    //      / \
    //     T3 T4
    Node* leftRotate(Node* y)
    {
        Node* x = y->right;
        Node* T2 = x->left;

        //左旋转
        x->left = y;
        y->right = T2;

        //更新 x y 的值，因为y 在下面，所以先更新 y 的高度值，后更新x的高度值
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        return x;
    }

    //LL
    // 对节点y进行向右旋转操作，返回旋转后新的根节点x
    //        y                              x
    //       / \                           /   \
    //      x   T4     向右旋转 (y)        z     y
    //     / \       - - - - - - - ->    / \   / \
    //    z   T3                       T1  T2 T3 T4
    //   / \
    // T1   T2
    // x->right = y
    //y->left = T3
    Node* rightRotate(Node* y)
    {
        Node* x = y->left;
        Node* T3 = x->right;
        //右旋转
        x->right = y;
        y->left = T3;
        //更新 x y 的值，因为y 在下面，所以先更新 y 的高度值，后更新x的高度值
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        return x;
    }


    Node* add(Node* node, K key, V value) {
        if(node == NULL)
        {
            count++;
            return new Node(key, value);
        }
        if(node->key < key)
        {
            node->right = add(node->right, key, value);
        }
        else if(node->key > key)
        {
            node->left = add(node->left, key, value);
        }
        else
        {
             node->key = key;
        }

        //先更新高度
        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        int balanceFactor = getBalanceFactor(node);
        if(abs(balanceFactor) > 1)
        {
           // cout << "balanceFactor = " << balanceFactor <<  endl;
        }

        //平衡维护
        //        y      
        //       / \     
        //      x   T4   
        //     / \       
        //    z   T3     
        //   / \
        // T1   T2
        if(balanceFactor > 1 && getBalanceFactor(node->left) >= 0)  // LL 情况
        {
            return rightRotate(node);
        }
        //    y     
        //  /  \    
        // T1   x   
        //     / \  
        //   T2   z  
        //       / \
        //      T3 T4
        if(balanceFactor < -1 && getBalanceFactor(node->right) <= 0) // RR 情况
        {
            return leftRotate(node);
        }
        //        y      
        //       / \     
        //      x   T4   
        //     / \       
        //    T3  z   
        //        / \
        //      T1   T2
        if(balanceFactor > 1 && getBalanceFactor(node->left) < 0) // LR 情况
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        //   y     
        //  /  \    
        // T1   x   
        //     / \  
        //     z  T2
        //    / \
        //    T3 T4 
        //      
        //      
        if(balanceFactor < -1 && getBalanceFactor(node->right) > 0) // RL 情况
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }



    void destroy(Node* node)
    {
        if(node == NULL)
            return;
        destroy(node->left);
        destroy(node->right);
        destroy(node);
    }
};