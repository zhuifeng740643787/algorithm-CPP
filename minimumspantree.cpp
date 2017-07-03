//
// Created by 宫宜栋 on 2017/6/20.
//

#include <iostream>
#include <string>
#include "Helper/TestHelper.h"
#include "MinumumSpanTree/SparseGraph.h"
#include "MinumumSpanTree/DenseGraph.h"
#include "MinumumSpanTree/Edge.h"
#include "MinumumSpanTree/ReadGraph.h"
#include "MinumumSpanTree/Component.h"
#include "MinumumSpanTree/MinHeap.h"
#include "MinumumSpanTree/MinIndexHeap.h"
#include "Heap/MaxIndexHeap.h"
#include "MinumumSpanTree/LazyPrimMST.h"
#include "MinumumSpanTree/PrimMST.h"
#include "MinumumSpanTree/UnionFind.h"
#include "MinumumSpanTree/KruskalMST.h"

using namespace std;


void test(int n, int m, bool directed) {
    SparseGraph<double> sparseGraph(n, directed);
    DenseGraph<double> denseGraph(n, directed);
    for (int i = 0; i < m; ++i) {
        int v = rand() % n;
        int w = rand() % n;
        double weight = double(rand() % 100) / 100;
        cout << v << "-" << w << ":" << weight << endl;
        sparseGraph.addEdge(v, w, weight);
        denseGraph.addEdge(v, w, weight);
    }

    cout << "稀疏图：" << endl;
    for (int v = 0; v < n; ++v) {
        cout << v << ": ";
        SparseGraph<double>::adjIterator adj(sparseGraph, v);
        for (Edge<double> *w = adj.begin(); !adj.end(); w = adj.next()) {
            cout << w << " ";
        }
        cout << endl;
    }
    cout << "稠密图：" << endl;
    for (int v = 0; v < n; ++v) {
        cout << v << ": ";
        DenseGraph<double>::adjIterator adj(denseGraph, v);
        for (Edge<double> *w = adj.begin(); !adj.end(); w = adj.next()) {
            cout << w << " ";
        }
        cout << endl;
    }
}

void testRead(string fileName, int n, bool directed) {
    SparseGraph<double> sparseGraph(n, directed);
    ReadGraph<SparseGraph<double>> read1(sparseGraph, fileName);
    sparseGraph.show();
    DenseGraph<double> denseGraph(n, directed);
    ReadGraph<DenseGraph<double>> read2(denseGraph, fileName);
    denseGraph.show();
    Component<SparseGraph<double>, Edge<double>*> component(sparseGraph);
    cout<<"连通分量个数："<<component.count()<<endl;
    LazyPrimMST<DenseGraph<double>, double> lazyPrimMST(denseGraph);
    lazyPrimMST.showMST();
    PrimMST<DenseGraph<double>, double> primMST(denseGraph);
    primMST.showMST();
    KruskalMST<DenseGraph<double>, double> kruskalMSTM(denseGraph);
    kruskalMSTM.showMST();
}

void testMinHeap(int n) {
    int *arr = TestHelper::generateRandomArr(n, 0, n);
    TestHelper::printArr(arr, n);
    MinHeap<int> minHeap(n);
    for (int i = 0; i < n; ++i) {
        minHeap.insert(arr[i]);
    }
    while (!minHeap.empty()) {
        cout<<minHeap.extract()<<" ";
    }
    cout<<endl;
}

void testMinIndexHeap(int n) {
    int *arr = TestHelper::generateRandomArr(n, 0, 100);
//    int arr[] = {53,31,29,58,11,16,15,73,65,28 };
    for (int i = 0; i < n; ++i) {
        cout<<i<<"  ";
        if(i == n-1) {
            cout<<endl;
        }
    }
    TestHelper::printArr(arr, n);
    MinIndexHeap<int> minIndexHeap(n+10);
    MaxIndexHeap maxIndexHeap(n);
    for (int i = 0; i < n; ++i) {
        minIndexHeap.insert(i, arr[i]);
        maxIndexHeap.insert(i, arr[i]);
    }
    cout<<endl;
    minIndexHeap.change(3, 13);
    minIndexHeap.insert(11, 14);
    minIndexHeap.insert(2100, 40);
    minIndexHeap.insert(15, 17);
    minIndexHeap.showIndexes();
    minIndexHeap.showReverseIndexes();
    while (!minIndexHeap.empty()) {
        int item = minIndexHeap.extractItem();
        cout<<item<<" ";
    }
    cout<<endl;
}
void testUnionFind(int n) {
    UnionFind uf(n);
    for (int k = 0; k < n; ++k) {
        cout<<k<<" ";
    }
    cout<<endl;
    for (int i = 0; i < n; ++i) {
        int a = rand() % n;
        int b = rand() % n;
        cout<<a<<"-"<<b<<" ";
        uf.unionElements(a, b);
    }
    cout<<endl;
    cout<<uf.isConnected(1,2);
}
int main() {
    srand(time(NULL));
    int exit = 0;
    string fileName1 = "/Users/gongyidong/learn/back/c++/algorithm/MinumumSpanTree/graph1.txt";
    string fileName2 = "/Users/gongyidong/learn/back/c++/algorithm/MinumumSpanTree/graph2.txt";
    while (!exit) {
//        test(10, 10, false);
//        testRead(fileName1, 13, false);
        testRead(fileName2, 6, false);
//        testUnionFind(10);



        exit = 1;
//        cout << "是否退出? 1/0 1=退出 0=不退出 ";
//        cin >> exit;
        cout << endl;
    }
}

