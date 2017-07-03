//
// Created by 宫宜栋 on 2017/6/28.
//

#ifndef ALGORITHM_BELLMANFORD_H
#define ALGORITHM_BELLMANFORD_H

#include <stack>
#include <vector>
#include "../MinumumSpanTree/Edge.h"

/**
 * Bellman-Ford 算法(解决负权边问题)
 * 前提是不能有负权环
 * 原理：如果图中没有负权环，那么一个点到另一个点，最多经过图中所有的V个点，有V-1条边，否则，存在顶点经过了两次，即存在负权环
 */
template<typename Graph, typename Weight>
class BellmanFord {
private:
    Graph &G;//图
    int s;//源点
    vector<Edge<Weight> *> from;//存储最短路径的边
    Weight *distTo;//源点到各顶点的距离
    bool hasNegativeCycle;//图中是否存在负权环

    //判断是否有负权环
    bool detectNegativeCycle() {
        //再进行一次松弛操作，看有没有更小的距离
        for (int i = 0; i < G.V(); ++i) {
            typename Graph::adjIterator adj(G, i);
            for (Edge<Weight> *edge = adj.begin(); !adj.end(); edge = adj.next()) {
                int v = edge->getV();
                int w = edge->getW();
                //有未被访问过的点或者可以再次获得更小的距离
                if (from[w] == NULL || distTo[v] + edge->wt() < distTo[w]) {
                    return true;
                }
            }
        }
        return false;
    }

public:
    BellmanFord(Graph &graph, int source) : G(graph) {
        s = source;
        hasNegativeCycle = false;
        distTo = new Weight[G.V()];
        for (int i = 0; i < G.V(); ++i) {
            distTo[i] = Weight();
            from.push_back(NULL);
        }

        //Bellman-Ford算法
        distTo[s] = Weight();
        //进行V-1次松弛操作
        for (int pass = 1; pass < G.V() - 1; ++pass) {
            //松弛操作Relaxation
            for (int i = 0; i < G.V(); ++i) {
                typename Graph::adjIterator adj(G, i);
                for (Edge<Weight> *edge = adj.begin(); !adj.end(); edge = adj.next()) {
                    int v = edge->getV();
                    int w = edge->getW();
                    if (from[w] == NULL  || distTo[v] + edge->wt() < distTo[w]) {
                        distTo[w] = distTo[v] + edge->wt();
                        from[w] = edge;
                    }
                }
            }
        }

        hasNegativeCycle = detectNegativeCycle();

    }

    ~BellmanFord() {
        delete[] distTo;
    }

    bool negativeCycle() {
        return hasNegativeCycle;
    }


    //显示最短路径
    void showPath(int w) {
        assert(w >= 0 && w < G.V());
        assert(!hasNegativeCycle);
        cout << s << "->" << w << ": " << distTo[w] << "  ";
        vector<Edge<Weight> *> vec;
        shortestPath(w, vec);
        for (int j = 0; j < vec.size(); ++j) {
            cout << vec[j]->getV() << "->";
            if (j == vec.size() - 1) {
                cout << vec[j]->getW();
            }
        }
        cout << endl;
    }

    //获得最短路径
    void shortestPath(int w, vector<Edge<Weight> *> &vec) {
        assert(w >= 0 && w < G.V());
        assert(!hasNegativeCycle);
        stack<Edge<Weight> *> s;
        Edge<Weight> *e = from[w];
        while (e != NULL && e->getV() != this->s ) {
            s.push(e);
            e = from[e->getV()];
        }
        if(e != NULL) {
            s.push(e);
        }
        vec.clear();
        while (!s.empty()) {
            e = s.top();
            s.pop();
            vec.push_back(e);
        }
    }


};

#endif //ALGORITHM_BELLMANFORD_H
