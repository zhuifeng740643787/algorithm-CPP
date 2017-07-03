//
// Created by 宫宜栋 on 2017/6/28.
//

#ifndef ALGORITHM_DIJKSTRA_H
#define ALGORITHM_DIJKSTRA_H

#include <stack>
#include <vector>
#include "../MinumumSpanTree/MinIndexHeap.h"
#include "../MinumumSpanTree/Edge.h"

/**
 * dijkstra单源最短路径算法
 * O(ElogV)
 */
template<typename Graph, typename Weight>
class Dijkstra {

private:
    Graph &G;//图
    Weight *distTo;//顶点到源点的距离
    MinIndexHeap<Weight> ipq;//维护顶点到源点距离的最小索引堆
    vector<Edge<Weight> *> from;//存储路径
    bool *marked;//存储顶点是否被标记
    int s;//源点


    void visit(int v) {
        if (marked[v]) {
            return;
        }
        marked[v] = true;
        typename Graph::adjIterator adj(G, v);
        for (Edge<Weight> *edge = adj.begin(); !adj.end(); edge = adj.next()) {
            int w = edge->other(v);
            if (marked[w]) {
                continue;
            }
            if (distTo[w] == Weight()) {
                distTo[w] = edge->wt();
                ipq.insert(w, edge->wt());
                from[w] = edge;
                continue;
            }
            //松弛操作
            if (edge->wt() + distTo[v] < distTo[w]) {
                distTo[w] = edge->wt() + distTo[v];
                ipq.change(w, edge->wt() + distTo[v]);
                from[w] = edge;
            }
        }
    }

public:
    Dijkstra(Graph &graph, int source) : G(graph), ipq(MinIndexHeap<Weight>(graph.V())) {
        s = source;
        distTo = new Weight[G.V()];
        marked = new bool[G.V()];
        for (int i = 0; i < G.V(); ++i) {
            distTo[i] = Weight();
            marked[i] = false;
            from.push_back(NULL);
        }
        //方法1
//        visit(s);
//
//        while (!ipq.empty()) {
//            int v = ipq.extractIndex();
//            visit(v);
//        }

        //方法2
        //设置源点到源点的距离
        distTo[s] = Weight();
        marked[s] = true;
        ipq.insert(s, distTo[s]);

        while (!ipq.empty()) {
            int v = ipq.extractIndex();

            //distTo[v]就是s到v的最短距离
            marked[v] = true;

            //将v的邻边入堆
            typename Graph::adjIterator adj(G, v);
            for (Edge<Weight> *edge = adj.begin(); !adj.end(); edge = adj.next()) {
                //判断另一端的顶点是否被标记过
                int w = edge->other(v);
                if (marked[w]) {
                    continue;
                }

                //松弛操作
                //判断顶点有没有访问过
                if (from[w] == NULL || edge->wt() + distTo[v] < distTo[w]) {
                    from[w] = edge;
                    distTo[w] = distTo[v] + edge->wt();
                    if(!ipq.contain(w)) {
                        ipq.insert(w, distTo[w]);
                    } else {
                        ipq.change(w, distTo[w]);
                    }
                }

            }
        }


    }

    ~Dijkstra() {
        delete[] distTo;
        delete[] marked;
    }

    //显示最短路径
    void showPath(int w) {
        assert(w >= 0 && w < G.V());
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

    //判断是否有路径
    bool hasPath(int w) {
        assert(w >= 0 && w < G.V());
        return marked[w];
    }

    //获得最短路径
    void shortestPath(int w, vector<Edge<Weight> *> &vec) {
        assert(w >= 0 && w < G.V());
        stack<Edge<Weight> *> s;
        Edge<Weight> *e = from[w];
        while (e != NULL && e->getV() != this->s) {
            s.push(e);
            e = from[e->getV()];
        }
        if (e != NULL) {
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

#endif //ALGORITHM_DIJKSTRA_H
