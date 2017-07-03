//
// Created by 宫宜栋 on 2017/6/27.
//

#ifndef ALGORITHM_PRIMMST_H
#define ALGORITHM_PRIMMST_H

#include <vector>
#include "MinIndexHeap.h"
#include "Edge.h"

/**
 * 优化后的Prim最小生成树
 */
template<typename Graph, typename Weight>
class PrimMST {
private:
    Graph &G;//图
    Weight mstWeight;//权值总和
    vector<Edge<Weight>*> edgeTo;//存储顶点的边
    vector<Edge<Weight>> mst;//最小生成树的最小横切边
    MinIndexHeap<Weight> ipq;//最小索引堆
    bool *marked;//标记顶点是否已被标记

    void visit(int v) {
        if (marked[v]) {
            return;
        }

        marked[v] = true;

        typename Graph::adjIterator adj(G, v);
        for (Edge<Weight> *e = adj.begin(); !adj.end(); e = adj.next()) {
            //判断顶点是否已被标记
            int w = e->other(v);
            if (marked[w]) {
                continue;
            }

            if (edgeTo[w] == NULL) {
                ipq.insert(w, e->wt());
                edgeTo[w] = e;
            } else if (e->wt() < edgeTo[w]->wt()) {
                ipq.change(w, e->wt());
                edgeTo[w] = e;
            }
        }
    }

public:
    PrimMST(Graph &graph) : G(graph), ipq(MinIndexHeap<Weight>(graph.V())) {
        mstWeight = Weight();
        marked = new bool[G.V()];
        for (int i = 0; i < G.V(); ++i) {
            marked[i] = false;
            edgeTo.push_back(NULL);
        }


        //优化的Prim算法
        visit(0);
        //最小横切边数为 顶点数-1
        while (!ipq.empty()) {
            int v = ipq.extractIndex();
            Edge<Weight> *edge = edgeTo[v];
            mst.push_back(*edge);
            mstWeight += edge->wt();
            visit(v);
        }

    }

    ~PrimMST() {
        delete[] marked;
    }


    void showMST() {
        cout << "权值总和为：" << mstWeight << endl;
        for (int i = 0; i < mst.size(); ++i) {
            cout << &mst[i] <<endl;
        }
    }


};


#endif //ALGORITHM_PRIMMST_H
