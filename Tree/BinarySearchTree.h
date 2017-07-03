//
// Created by 宫宜栋 on 2017/6/21.
//

#ifndef ALGORITHM_BINARYSEARCHTREE_H
#define ALGORITHM_BINARYSEARCHTREE_H

#include <iostream>
#include <queue>

using namespace std;

/**
 * 二叉搜索树
 * 1.二叉树
 * 2.每个节点的值 >左子节点的值 <右子节点的值
 * 3.以左右子节点为根节点的树也为二叉搜索树
 * 4.不一定是一棵完全二叉树
 */
template<typename Key, typename Value>
class BinarySearchTree {
private:
    struct Node {
        Key key;//
        Value value;//节点的值
        Node *leftNode;//左子节点
        Node *rightNode;//右子节点
        int nodeCount = 1;//以该节点为根节点的树的节点个数

        Node(Key key, Value value) {
            this->key = key;
            this->value = value;
            this->leftNode = NULL;
            this->rightNode = NULL;
        }

        Node(Node *node) {
            this->key = node->key;
            this->value = node->value;
            this->leftNode = node->leftNode;
            this->rightNode = node->rightNode;
        }

        //重载Node输出操作
        friend ostream &operator<<(ostream &output, Node *node) {
            output << node->key << " - " << node->value << " - " << node->nodeCount << endl;
            return output;
        }

    };

    int count;//节点个数
    Node *root;//根节点

    //插入以root为根节点的二叉搜索树
    //返回插入后的根节点
    Node *_insert(Node *root, Key key, Value value) {
        if (root == NULL) {
            //节点个数加一
            count++;
            return new Node(key, value);
        }
        if (key == root->key) {
            root->value = value;
        } else if (key > root->key) {
            root->nodeCount++;
            root->rightNode = _insert(root->rightNode, key, value);
        } else {
            root->nodeCount++;
            root->leftNode = _insert(root->leftNode, key, value);
        }
        return root;
    }

    //前序遍历树
    void _preOrder(Node *root) {
        if (root == NULL) {
            return;
        }
        //做事情
        cout << root;
        //前序遍历左子树
        _preOrder(root->leftNode);
        //前序遍历右子树
        _preOrder(root->rightNode);
    }

    //中序遍历树
    void _inOrder(Node *root) {
        if (root == NULL) {
            return;
        }
        //中序遍历左子树
        _inOrder(root->leftNode);
        //做事情
        cout << root;
        //中序遍历右子树
        _inOrder(root->rightNode);
    }

    //后序遍历树
    void _postOrder(Node *root) {
        if (root == NULL) {
            return;
        }
        //后序遍历左子树
        _postOrder(root->leftNode);
        //后序遍历右子树
        _postOrder(root->rightNode);
        //做事情
        cout << root;
    }

    //广度优先遍历
    void _breadthFirstOrder(Node *root) {
        if (root == NULL) {
            return;
        }
        queue<Node *> q;
        q.push(root);
        while (!q.empty()) {
            Node *node = q.front();
            cout << node;
            q.pop();
            if (node->leftNode != NULL) {
                q.push(node->leftNode);
            }
            if (node->rightNode != NULL) {
                q.push(node->rightNode);
            }
        }
    }

    //销毁以root为根节点的二叉搜索树
    void _destroy(Node *root) {
        if (root == NULL) {
            return;
        }
        //销毁左子树
        _destroy(root->leftNode);
        //销毁右子树
        _destroy(root->rightNode);
        //销毁自己
        delete root;
    }

    Value *_search(Node *root, int key) {
        //1.递归写法
        if (root == NULL) {
            return NULL;
        }

        if (root->key == key) {
            return &root->value;
        } else if (key < root->key) {
            return _search(root->leftNode, key);
        } else {
            return _search(root->rightNode, key);
        }

        //2.非递归写法
//        while (root != NULL) {
//            if (root->key == key) {
//                return &root->value;
//            } else if (key < root->key) {
//                root = root->leftNode;
//            } else {
//                root = root->rightNode;
//            }
//        }
//        return NULL;
    }

    bool _contain(Node *root, Key key) {
        if (root == NULL) {
            return false;
        }
        if (key == root->key) {
            return true;
        } else if (key < root->key) {
            return _contain(root->leftNode, key);
        } else {
            return _contain(root->rightNode, key);
        }
    }


    //以root为根节点的最小子节点
    Node *_minNode(Node *root) {
        while (root != NULL) {
            if (root->leftNode != NULL) {
                root = root->leftNode;
            } else {
                return root;
            }
        }
        return root;
    }

    //以root为根节点的最大子节点
    Node *_maxNode(Node *root) {
        while (root != NULL) {
            if (root->rightNode != NULL) {
                root = root->rightNode;
            } else {
                return root;
            }
        }
        return root;
    }

    //删除以root为根节点的二叉搜索树中最小的节点
    //返回删除后的根节点
    Node *_removeMinNode(Node *root) {

        if (root == NULL) {
            return NULL;
        }

        if (root->leftNode != NULL) {
            root->nodeCount--;
            root = _removeMinNode(root->leftNode);
            return root;
        } else {
            //删除
            Node *rightNode = root->rightNode;
            delete root;
            count--;
            return rightNode;
        }

    }

    //删除以root为根节点的二叉搜索树中最大的节点
    //返回删除后的根节点
    Node *_removeMaxNode(Node *root) {
        if (root == NULL) {
            return NULL;
        }

        if (root->rightNode != NULL) {
            root->nodeCount--;
            root->rightNode = _removeMaxNode(root->rightNode);
            return root;
        } else {
            //删除
            Node *leftNode = root->leftNode;
            delete root;
            count--;
            return leftNode;
        }

    }

    //删除以root为根节点的二叉搜索树中键值为key的节点
    //返回删除节点后的二分搜索树的根节点
    Node *_remove(Node *root, Key key) {
        if (root == NULL) {
            return NULL;
        }

        if (key == root->key) {
            //删除操作
            if (root->leftNode == NULL) {
                Node *rightNode = root->rightNode;
                delete root;
                count--;
                return rightNode;
            }
            if (root->rightNode == NULL) {
                Node *leftNode = root->leftNode;
                delete root;
                count--;
                return leftNode;
            }

            //到这说明root有左右子树
            //获取到左子树最大节点并备份到后继节点中，下一步会删除该左子树最大节点
            Node *successor = new Node(_maxNode(root->leftNode));
            //删除左子树最大节点，并返回该左子树的根节点作为新节点的左子节点
            successor->leftNode = _removeMaxNode(root->leftNode);
            successor->rightNode = root->rightNode;

            successor->nodeCount = 1;
            if (successor->leftNode != NULL) {
                successor->nodeCount += successor->leftNode->nodeCount;
            }
            if (successor->rightNode != NULL) {
                successor->nodeCount += successor->rightNode->nodeCount;
            }

            //删除root节点
            delete root;

            //返回新节点
            return successor;

        } else if (key < root->key) {
            root->nodeCount--;
            root->leftNode = _remove(root->leftNode, key);
        } else {
            root->nodeCount--;
            root->rightNode = _remove(root->rightNode, key);
        }
        return root;
    }


    //前驱值（小于key的最大的键值）
    Node *_floor(Node *root, Key key) {
        if (root == NULL) {
            return NULL;
        }

        if (key == root->key) {
            return _maxNode(root->leftNode);
        } else if (key < root->key) {
            return _floor(root->leftNode, key);
        } else {
            //遍历右边
            Node *node = _floor(root->rightNode, key);
            if (node == NULL) {
                return root;
            }
            return node;
        }

    }

    //后继值（大于key的最小的键值）
    Node *_ceil(Node *root, Key key) {
        if (root == NULL) {
            return NULL;
        }

        if (key == root->key) {
            return _minNode(root->rightNode);
        } else if (key > root->key) {
            return _ceil(root->rightNode, key);
        } else {
            Node *node = _ceil(root->leftNode, key);
            if (node == NULL) {
                return root;
            }
            return node;
        }
    }

    int _currentNodeRank(Node *node) {
        if(node == NULL) {
            return count + 1;
        }
        if(node->leftNode != NULL) {
            return node->leftNode->nodeCount + 1;
        }
        return 1;
    }
    //获取key在数组中的排名
    int _rank(Node *root, Key key) {
        if(root == NULL) {
            return count + 1;
        }
        if(key == root->key) {
            return _currentNodeRank(root);
        } else if (key < root->key) {
            return _rank(root->leftNode, key);
        } else {
            return _currentNodeRank(root) + _rank(root->rightNode, key);
        }
    }

    //获取排名为rank的节点
    Node * _select(Node *root, int rank) {
        if(root == NULL) {
            return NULL;
        }

        int currentNodeRank = _currentNodeRank(root);
        if(currentNodeRank == rank) {
            return root;
        } else if(currentNodeRank < rank){
            return _select(root->rightNode, rank - currentNodeRank);
        } else {
            return _select(root->leftNode, currentNodeRank - rank);
        }
    }

public:
    BinarySearchTree() {
        count = 0;
        root = NULL;
    }

    ~BinarySearchTree() {
        //销毁树（后序遍历）
        _destroy(root);
    }

    //插入节点
    void insert(Key key, Value value) {
        root = _insert(root, key, value);
    }

    //检索Key对应的Value值
    Value *search(Key key) {
        return _search(root, key);
    }

    //删除键值为key的节点
    bool *remove(Key key) {
        root = _remove(root, key);
    }

    //前序遍历树
    void preOrder() {
        _preOrder(root);
    }

    //中序遍历树
    void inOrder() {
        _inOrder(root);
    }

    //后序遍历树
    void postOrder() {
        _postOrder(root);
    }

    //深度优先遍历
    void depthFirstOrder() {
        _preOrder(root);
    }

    //广度优先遍历
    void breadthFirstOrder() {
        _breadthFirstOrder(root);
    }

    //检查是否包含key
    bool contain(Key key) {
        return _contain(root, key);
    }

    //获取一个key的前驱值
    Key *floor(Key key) {
        Node *node = _floor(root, key);
        if (node == NULL) {
            return NULL;
        }
        return &node->key;
    }

    //获取一个key的后继值
    Key *ceil(Key key) {
        Node *node = _ceil(root, key);
        if (node == NULL) {
            return NULL;
        }
        return &node->key;
    }

    //查看key排名第几
    int rank(Key key) {
        int rank = _rank(root, key);
        if(rank > count) {
            return -1;
        }
        return rank;
    }

    //查看排名第rank的元素的键值
    Key* select(int rank) {
        if(rank > count || rank < 1) {
            return NULL;
        }

        Node *node = _select(root, rank);
        return node != NULL ? &node->key : NULL;
    }

};

#endif //ALGORITHM_BINARYSEARCHTREE_H
