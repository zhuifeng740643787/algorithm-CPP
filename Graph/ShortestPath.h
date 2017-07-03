//
// Created by 宫宜栋 on 2017/6/26.
//

#ifndef ALGORITHM_SHORTESTPATH_H
#define ALGORITHM_SHORTESTPATH_H

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cassert>

using namespace std;

/**
 * 单源最短路径（无权图）
 * 广度优先遍历
 * 时间复杂度：稀疏图: O(V+E) 稠密图: O(V^2)
 */
template<typename Graph>
class ShortestPath {

private:
    Graph &G;
    bool *visited;
    int source;//源点
    int *from;
    int *ord;//路径长度

    //对顶点广度优先遍历
    void bfs(int v) {
        visited[v] = true;
        queue<int> q;
        q.push(v);
        ord[v] = 0;
        while (!q.empty()) {
            int p = q.front();
            q.pop();
            typename Graph::adjIterator adj(G, p);
            for (int w = adj.begin(); !adj.end(); w = adj.next()) {
                if(!visited[w]) {
                    visited[w] = true;
                    from[w] = p;
                    ord[w] = ord[p] + 1;
                    q.push(w);
                }
            }
        }
    }

public:
    ShortestPath(Graph &graph, int source) : G(graph) {
        assert(source >= 0 && source < G.V());
        this->source = source;
        visited = new bool[G.V()];
        from = new int[G.V()];
        for (int i = 0; i < G.V(); ++i) {
            visited[i] = false;
            from[i] = -1;
            ord[i] = -1;
        }

        //寻址算法
        //广度优先遍历
        bfs(source);
    }

    ~ShortestPath() {
        delete[] visited;
        delete[] from;
        delete[] ord;
    }

    bool hasPath(int v) {
        assert(v >= 0 && v < G.V());
        return visited[v];
    }

    void path(int v, vector<int> &vec) {
        if (!hasPath(v)) {
            cout << "无法到达该点" << endl;
            return;
        }

        stack<int> s;
        int p = v;
        while(p != -1) {
            s.push(p);
            p = from[p];
        }
        vec.clear();
        while (!s.empty()) {
            int w = s.top();
            s.pop();
            vec.push_back(w);
        }
    }

    void showPath(int v) {
        vector<int> vec;
        path(v, vec);

        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i];
            if (i == vec.size() - 1) {
                cout << endl;
            } else {
                cout << "->";
            }
        }
    }


};

#endif //ALGORITHM_SHORTESTPATH_H
