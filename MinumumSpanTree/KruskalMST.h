//
// Created by 宫宜栋 on 2017/6/28.
//

#ifndef ALGORITHM_KRUSKALMST_H
#define ALGORITHM_KRUSKALMST_H

#include <vector>
#include "Edge.h"
#include "UnionFind.h"
#include "MinHeap.h"

/**
 * Kruskal最小生成树算法
 * 1.将所有边进行排序
 * 2.由小到大取出边，判断边的两个顶点是否构成环（使用并查集）,构成环的话将该边舍弃
 */
template<typename Graph, typename Weight>
class KruskalMST {
private:
    vector<Edge<Weight>> mst;
    Weight mstWeight;
    bool *marked;
public:
    KruskalMST(Graph &graph) {
        mstWeight = Weight();
        MinHeap<Edge<Weight>> pq(graph.E());//对边进行排序
        //将图的所有边入堆
        for (int v = 0; v < graph.V(); ++v) {
            typename Graph::adjIterator adj(graph, v);
            for (Edge<Weight> *edge = adj.begin(); !adj.end(); edge = adj.next()) {
                //去重边
                if (edge->getV() < edge->getW()) {
                    pq.insert(*edge);
                }
            }
        }

        UnionFind uf(graph.V());//并查集判断顶点是否构成环
        //出堆
        while (!pq.empty() && mst.size() < graph.V() - 1) {
            Edge<Weight> edge = pq.extract();
            int v = edge.getV();
            int w = edge.getW();
            if (uf.isConnected(v, w)) {
                continue;
            }

            mst.push_back(edge);
            uf.unionElements(v, w);
            mstWeight += edge.wt();
        }
    }

    ~KruskalMST() {}

    void showMST() {
        cout << "权值总和为：" << mstWeight << endl;
        for (int i = 0; i < mst.size(); ++i) {
            cout << &mst[i] << endl;
        }
    }

};

#endif //ALGORITHM_KRUSKALMST_H
