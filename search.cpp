//
// Created by 宫宜栋 on 2017/6/20.
//

#include <iostream>
#include "Tree/BinarySearchMethod.h"
#include "Sort/InsertionSort.h"
#include "Tree/BinarySearchTree.h"

#include "Helper/TestHelper.h"

using namespace std;


int main() {
//    int n = 20;
//    int *arr = TestHelper::generateRandomArr(n, 0, n);
//    srand(time(NULL));
//    int k = arr[rand()%n];
//    InsertionSort::runOptimize(arr, n);
//    TestHelper::printArr(arr, n);
//    cout<<k<<"="<<"arr["<<BinarySearchMethod::run(arr, n, k)<<"]"<<endl;
//    cout<<endl;

    BinarySearchTree<int, int> *binarySearchTree = new BinarySearchTree<int, int>();
    int keys[] = {10, 8, 25, 17, 3, 6, 30, 9};
    for (int i = 0; i < 8; ++i) {
        binarySearchTree->insert(keys[i], i);
    }

//    cout<<"前序遍历-------------------"<<endl;
//    binarySearchTree->preOrder();
//    cout<<"中序遍历-------------------"<<endl;
//    binarySearchTree->inOrder();
//    cout<<"后序遍历-------------------"<<endl;
//    binarySearchTree->postOrder();
    cout << "广度优先遍历-------------------" << endl;
//    binarySearchTree->breadthFirstOrder();
//    binarySearchTree->remove(10);
//    cout<<endl;
    binarySearchTree->breadthFirstOrder();
//    int key = 10;
//    int *val = binarySearchTree->search(key);
//    if (val == NULL) {
//        cout << "not found" << endl;
//    } else {
//        cout << "key=" << key << " val=" << *val << endl;
//    }
//    binarySearchTree->remove(10);
//    binarySearchTree->remove(25);
//    binarySearchTree->breadthFirstOrder();

    int exit = 0;
    int k;
    while(!exit) {
        cout<<"输入查询的Key: ";
        cin>>k;
        int *floor = binarySearchTree->floor(k);
        cout<<"floor("<<k<<")="<<(floor == NULL ? -1 : *floor)<<endl;
        int *ceil = binarySearchTree->ceil(k);
        cout<<"ceil("<<k<<")="<<(ceil == NULL ? -1 : *ceil)<<endl;
        int rank = binarySearchTree->rank(k);
        cout<<"rank("<<k<<")="<<rank<<endl;

        int select;
        cout<<"输入排名：";
        cin>>select;
        int *rankKey = binarySearchTree->select(select);
        cout<<"select("<<select<<")="<<(rankKey== NULL ? -1 : *rankKey)<<endl;

        cout<<"是否退出? 1/0 1=退出 0=不退出 ";
        cin>>exit;
        cout<<endl;
    }
}

