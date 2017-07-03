//
// Created by 宫宜栋 on 2017/6/26.
//

#ifndef ALGORITHM_SPARSEGRAPH_H
#define ALGORITHM_SPARSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/**
 * 稀疏图
 * 采用邻接表
 */
class SparseGraph {

private:
    int n;//顶点个数
    int m;//边的个数
    bool directed;//是否为有向图
    vector<vector<int>> g;//图

public:
    SparseGraph(int n, bool directed) {
        this->n = n;
        this->directed = directed;
        this->m = 0;
        for (int i = 0; i < n; ++i) {
            g.push_back(vector<int>());
        }
    }

    ~SparseGraph() {}

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
        if (hasEdge(v, w)) {
            return;
        }
        //添加边
        g[v].push_back(w);
        //非自环边且为无向图
        if (!directed) {
            g[w].push_back(v);
        }
        m++;
    }

    //判断是否已存在该边
    bool hasEdge(int v, int w) {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);
        for (int i = 0; i < g[v].size(); ++i) {
            if (g[v][i] == w) {
                return true;
            }
        }
        return false;
    }

    //展示图
    void show() {

        for (int i = 0; i < n; ++i) {
            cout<<i<<": ";
            for (int j = 0; j < g[i].size(); ++j) {
                cout<<g[i][j]<<" ";
            }
            cout << endl;
        }
    }

    /**
     * 图的迭代器
     */
    class adjIterator {
    private:
        SparseGraph &G;//要迭代的图
        int v;//要迭代的图的顶点
        int index;//索引位置
    public:
        adjIterator(SparseGraph &graph, int v) : G(graph) {
            assert(v >= 0 && v < G.V());
            this->v = v;
            this->index = 0;

        }

        ~adjIterator() {}

        //首个元素
        int begin() {
            index = 0;
            if (G.g[v].size() <= 0) {
                return -1;
            }
            return G.g[v][index];
        }

        int next() {
            index++;
            if (index >= G.g[v].size()) {
                return -1;
            }
            return G.g[v][index];
        }

        bool end() {
            return index >= G.g[v].size();
        }


    };

};

#endif //ALGORITHM_SPARSEGRAPH_H
