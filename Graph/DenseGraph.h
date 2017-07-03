//
// Created by 宫宜栋 on 2017/6/26.
//

#ifndef ALGORITHM_DENSEGRAPH_H
#define ALGORITHM_DENSEGRAPH_H


#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/**
 * 稠密图
 * 采用邻接矩阵
 */
class DenseGraph {

private:
    int n;//顶点个数
    int m;//边的个数
    bool directed;//是否为有向图
    vector<vector<bool>> g;//图

public:
    DenseGraph(int n, bool directed) {
        this->n = n;
        this->m = 0;
        this->directed = directed;
        for (int i = 0; i < n; ++i) {
            g.push_back(vector<bool>(n, false));
        }
    }

    ~DenseGraph() {}

    //顶点个数
    int V() { return n; }

    //边的个数
    int E() { return m; }

    //添加边顶点v-顶点w
    void addEdge(int v, int w) {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);


        //去掉自环边
        if (v == w) {
            return;
        }
        //判断是否有平行边，或者已添加了该边
        if (hasEdge(v, w)) {
            return;
        }
        //添加边
        g[v][w] = true;
        if (!directed) {
            g[w][v] = true;
        }
        m++;
    }

    //判断是否已存在该边
    bool hasEdge(int v, int w) {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);
        return g[v][w];
    }

    //展示图
    void show() {
        for (int i = 0; i < n; ++i) {
            cout << i << ": ";
            for (int j = 0; j < n; ++j) {
                if (g[i][j]) {
                    cout << j << " ";
                }
            }
            cout << endl;
        }
    }


    /**
     * 图的迭代器
     */
    class adjIterator {
    private:
        DenseGraph &G;
        int v;
        int index;

    public:
        adjIterator(DenseGraph &graph, int v) : G(graph) {
            this->v = v;
            this->index = 0;
        }

        ~adjIterator() {}

        int begin() {
            index = -1;
            return next();
        }

        int next() {
            for (index++; index <= G.V(); index++) {
                if (G.g[v][index] != 0) {
                    return index;
                }
            }
            return -1;
        }

        bool end() {
            return index >= G.V();
        }
    };
};


#endif //ALGORITHM_DENSEGRAPH_H
