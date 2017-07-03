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
#include "ShortestPath/Dijkstra.h"
#include "ShortestPath/BellmanFord.h"

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
    cout<<endl;
    int s = 0;
    Dijkstra<SparseGraph<double>, double> dijkstra(sparseGraph, s);
    for (int i = 0; i < n; ++i) {
        if(i == s) continue;
        dijkstra.showPath(i);
    }
    cout<<endl;
    BellmanFord<SparseGraph<double>, double> bellmanFord(sparseGraph, s);
    if(bellmanFord.negativeCycle()) {
        cout<<"含有负权环"<<endl;
    } else {
        for (int i = 0; i < n; ++i) {
            if(i == s) continue;
            bellmanFord.showPath(i);
        }
    }
}


int main() {
    srand(time(NULL));
    int exit = 0;
    string fileName1 = "/Users/gongyidong/learn/back/c++/algorithm/MinumumSpanTree/graph1.txt";
    string fileName2 = "/Users/gongyidong/learn/back/c++/algorithm/ShortestPath/graph2.txt";
    while (!exit) {
        testRead(fileName2, 5, true);



        exit = 1;
//        cout << "是否退出? 1/0 1=退出 0=不退出 ";
//        cin >> exit;
        cout << endl;
    }
}

