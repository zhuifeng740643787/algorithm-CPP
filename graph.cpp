//
// Created by 宫宜栋 on 2017/6/20.
//

#include <iostream>
#include <string>
#include "Graph/SparseGraph.h"
#include "Graph/DenseGraph.h"
#include "Graph/ReadGraph.h"
#include "Graph/Component.h"
#include "Graph/Path.h"
#include "Graph/ShortestPath.h"

using namespace std;


void test(int n, int m, bool directed) {
    srand(time(NULL));
    SparseGraph sparseGraph(n, directed);
    DenseGraph denseGraph(n, directed);
    for (int i = 0; i < m; ++i) {
        int v = rand() % n;
        int w = rand() % n;
        cout << v << "-" << w << endl;
        sparseGraph.addEdge(v, w);
        denseGraph.addEdge(v, w);
    }

    cout << "稀疏图：" << endl;
    for (int v = 0; v < n; ++v) {
        cout << v << ": ";
        SparseGraph::adjIterator adj(sparseGraph, v);
        for (int w = adj.begin(); !adj.end(); w = adj.next()) {
            cout << w << " ";
        }
        cout << endl;
    }
    cout << "稠密图：" << endl;
    for (int v = 0; v < n; ++v) {
        cout << v << ": ";
        DenseGraph::adjIterator adj(denseGraph, v);
        for (int w = adj.begin(); !adj.end(); w = adj.next()) {
            cout << w << " ";
        }
        cout << endl;
    }
}

void testRead(string fileName, int n, bool directed) {
    SparseGraph sparseGraph(n, directed);
    ReadGraph<SparseGraph> read1(sparseGraph, fileName);
    sparseGraph.show();
//    DenseGraph denseGraph(n, directed);
//    ReadGraph<DenseGraph> read2(denseGraph, fileName);
//    denseGraph.show();
    Component<SparseGraph> component(sparseGraph);
    cout<<"连通分量个数："<<component.count()<<endl;
    Path<SparseGraph> path(sparseGraph, 0);
    path.showPath(5);
    ShortestPath<SparseGraph> sp(sparseGraph, 0);
    sp.showPath(5);
}



int main() {
    int exit = 0;
    string fileName1 = "/Users/gongyidong/learn/back/c++/algorithm/Graph/graph1.txt";
    string fileName2 = "/Users/gongyidong/learn/back/c++/algorithm/Graph/graph2.txt";
    while (!exit) {
        testRead(fileName1, 13, false);
//        testRead(fileName2, 6, false);






        cout << "是否退出? 1/0 1=退出 0=不退出 ";
        cin >> exit;
        cout << endl;
    }
}

