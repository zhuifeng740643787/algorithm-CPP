//
// Created by 宫宜栋 on 2017/6/26.
//

#ifndef ALGORITHM_COMPONENT_H
#define ALGORITHM_COMPONENT_H

#include <iostream>
#include <cassert>

using namespace std;

/**
 * 获取图的连通分量
 */
template<typename Graph>
class Component {

private:
    Graph &G;
    int ccount;//连通分量个数
    bool *visited;//记录顶点是否被遍历过
    int *id;//使用并查集思想来判断两个顶点是否连通

    //对顶点v的边进行深度优先遍历
    void dfs(int v) {
        visited[v] = true;
        id[v] = ccount;
        typename Graph::adjIterator adj(G, v);
        for(int w = adj.begin(); !adj.end(); w = adj.next()) {
            if(!visited[w]) {
                dfs(w);
            }
        }
    }
public:
    Component(Graph &graph) : G(graph) {
        ccount = 0;
        id = new int[G.V()];
        visited = new bool[G.V()];
        for (int i = 0; i < G.V(); i++) {
            visited[i] = false;
            id[i] = -1;
        }

        //计算连通分量
        for (int v = 0; v < G.V() ; ++v) {
            if(!visited[v]) {
                ccount++;
                dfs(v);
            }
        }

    }

    ~Component() {
        delete[] visited;
        delete[] id;
    }

    int count() {
        return ccount;
    }

    //判断两个顶点是否连通
    bool isConnected(int v, int w) {
        assert(v >= 0 && v < G.V());
        assert(w >= 0 && w < G.V());
        return id[v] == id[w];
    }
};

#endif //ALGORITHM_COMPONENT_H
