#include <iostream>
#include "../02-stack/list_stack.hpp"
#include "../02-stack/array_stack.hpp"
#include "../03-queue/list_queue.hpp"
#include "../03-queue/array_queue.hpp"
#include "../03-queue/loop_queue.hpp"

using namespace std;

template<typename T>
class BST
{
private:
    struct Node
    {
    public:
        T data;
        Node* left;
        Node* right;
        Node(T e)
        {
            this->data = e;
            this->left = NULL;
            this->right = NULL;
        }
        Node(Node* e)
        {
            this->data = e->data;
            this->left = e->left;
            this->right = e->right;
        }
    };
    Node* root;
    int count;
public:
    void printNode(Node* p)
    {
        if(p != NULL)
        {
            cout << "p->data = " << p->data << endl;
        }
    }
    BST() : root(NULL), count(0)
    {}
    ~BST()
    {
        destroy(root);
    }
    int size() {return count;}
    int empty(){return count == 0;}
    void add(T e)
    {
        root = add(root, e);
    }
    bool contain(T e)
    {
        return contain(root, e);
    }
    void preOrder()
    {
        preOrder(root);
    }
    void inOrder()
    {
        inOrder(root);
    }
    void postOrder()
    {
        postOrder(root);
    }
    void preOrderNoRec()
    {
        //ListStack<Node*> s;
        ArrayStack<Node*> s;
        s.push(root);
        while(!s.empty())
        {
            Node* node = s.top();
            s.pop();
            cout << node->data << "  ";
            if(node->right)
                s.push(node->right);
            if(node->left)
                s.push(node->left);
        }
    }
    void levelOrder()
    {
        //ListQueue<Node*> q;
        //ArrayQueue<Node*> q;
        LoopQueue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node* node = q.front();
            printNode(node);
            q.pop();
            cout << node->data << "  ";
            if(node->left) 
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
    }
    T minimum()
    {
        assert(count > 0);
        return minimum(root)->data;
    }
    T maximum()
    {
        assert(count > 0);
        return maximum(root)->data;
    }
    T removeMin()
    {
        T ret = minimum();
        root = removeMin(root);
        return ret;
    }
    T removeMax()
    {
        T ret = maximum();
        root = removeMax(root);
        return ret;
    }
    void remove(T e)
    {
        root = remove(root, e);
    }
private:
    void destroy(Node* node)
    {
        if(node == NULL)
            return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
    // 删除掉以node为根的二分搜索树中键值为key的节点, 递归算法
    // 返回删除节点后新的二分搜索树的根
    Node* remove(Node* node, T e){

        if( node == NULL )
            return NULL;

        if( e < node->data ){
            node->left = remove( node->left , e );
            return node;
        }
        else if( e > node->data ){
            node->right = remove( node->right, e );
            return node;
        }
        else{   // key == node->key

            // 待删除节点左子树为空的情况
            if( node->left == NULL ){
                Node *rightNode = node->right;
                delete node;
                count --;
                return rightNode;
            }

            // 待删除节点右子树为空的情况
            if( node->right == NULL ){
                Node *leftNode = node->left;
                delete node;
                count--;
                return leftNode;
            }

            // 待删除节点左右子树均不为空的情况

            // 找到比待删除节点大的最小节点, 即待删除节点右子树的最小节点
            // 用这个节点顶替待删除节点的位置
            Node *successor = new Node(minimum(node->right));
            count ++;
            successor->right = removeMin(node->right);
            successor->left = node->left;
            delete node;
            count --;
            return successor;
        }
    }
    Node* removeMax(Node* node)
    {
        if(node->right == NULL)
        {
            Node* leftNode = node->left;
            delete node;
            count--;
            return leftNode;
        }
        node->right = removeMax(node->right);
        return node;
    }

    //删除最小节点，返回新的根节点
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

    Node* maximum(Node* node)
    {
        if(node->right == NULL)
            return node;
        return maximum(node->right);
    }
    Node* minimum(Node* node)
    {
        if(node->left == NULL)
            return node;
        return minimum(node->left);
        
    }
    void postOrder(Node* node)
    {
        if(node == NULL)
            return;
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << "  ";
    }
    void inOrder(Node* node)
    {
        if(node == NULL)
            return;
        inOrder(node->left);
        cout << node->data << "  ";
        inOrder(node->right);
    }
    void preOrder(Node* node)
    {
        if(node == NULL)
            return;
        cout << node->data << "  ";
        preOrder(node->left);
        preOrder(node->right);
    }
    bool contain(Node* node, T e)
    {
        if(node == NULL)
            return false;
        if(node->data == e)
            return true;
        if(node->data > e)
            return contain(node->left, e);
        if(node->data < e)
            return contain(node->right, e);
        return false;
    }
    Node* add(Node* node, T e)
    {
        if(node == NULL)
        {
            count++;
            return new Node(e);
        }
        if(node->data > e)
            node->left = add(node->left, e);
        else if(node->data < e)
            node->right = add(node->right, e);
        return node;
    }
};
