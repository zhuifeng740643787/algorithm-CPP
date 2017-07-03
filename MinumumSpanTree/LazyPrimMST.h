//
// Created by 宫宜栋 on 2017/6/27.
//

#ifndef ALGORITHM_LAZYPRIMMST_H
#define ALGORITHM_LAZYPRIMMST_H

#include <iostream>
#include <vector>
#include "MinHeap.h"
#include "Edge.h"

using namespace std;

/**
 * LazyPrim最小生成树算法
 */
template<typename Graph, typename Weight>
class LazyPrimMST {
private:
    Graph &G;
    MinHeap<Edge<Weight>> pq;
    bool *marked;
    Weight mstWeight;
    vector<Edge<Weight>> mst;

    //访问某个顶点，并把相邻边放入最小堆中
    void visit(int v) {
        if(marked[v]) {
            return;
        }
        marked[v] = true;
        typename Graph::adjIterator adj(G, v);
        for (Edge<Weight>* edge = adj.begin(); !adj.end() ; edge = adj.next()) {
            if(!marked[edge->other(v)]) {
                pq.insert(*edge);
            }
        }
    }

public:
    LazyPrimMST(Graph &graph) : G(graph), pq(MinHeap<Edge<Weight>>(graph.E())) {
        marked = new bool[G.V()];
        mstWeight = Weight();
        for (int i = 0; i < G.V(); ++i) {
            marked[i] = false;
        }

        //LazyPrim算法
        visit(0);

        while (!pq.empty()) {
            Edge<Weight> e = pq.extract();
            int v = e.getV();
            int w = e.getW();
            if(marked[v] && marked[w]) {
                continue;
            }
            mst.push_back(e);
            mstWeight += e.wt();
            if(marked[v]) {
                visit(w);
            } else {
                visit(v);
            }
        }
    }

    ~LazyPrimMST() {
        delete[] marked;
    }

    Weight getMSTWeight() {
        return mstWeight;
    }
    void showMST() {
        cout<<"最小权值为:"<<mstWeight<<endl;
        for (int i = 0; i < mst.size(); ++i) {
            cout<<&mst[i]<<endl;
        }
        cout<<endl;
    }
};

#endif //ALGORITHM_LAZYPRIMMST_H
