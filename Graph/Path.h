//
// Created by 宫宜栋 on 2017/6/26.
//

#ifndef ALGORITHM_PATH_H
#define ALGORITHM_PATH_H

#include <iostream>
#include <cassert>
#include <vector>
#include <stack>

using namespace std;

/**
 * 单源到其他点的路径
 * 深度优先遍历
 */
template<typename Graph>
class Path {
private:
    Graph &G;
    bool *visited;
    int *from;//路径
    int s;//源点

    //深度优先遍历
    void dfs(int v) {
        visited[v] = true;
        typename Graph::adjIterator adj(G, v);
        for (int w = adj.begin(); !adj.end(); w = adj.next()) {
            if (!visited[w]) {
                from[w] = v;
                dfs(w);
            }
        }
    }

public:
    Path(Graph &graph, int source) : G(graph) {
        assert(source >= 0 && source < G.V());

        s = source;
        visited = new bool[G.V()];
        from = new int[G.V()];
        for (int i = 0; i < G.V(); ++i) {
            visited[i] = false;
            from[i] = -1;
        }

        //寻址算法
        dfs(s);
    }

    ~Path() {
        delete[] visited;
        delete[] from;
    }

    //判断源点到该点是否有路径
    bool hasPath(int v) {
        assert(v >= 0 && v < G.V());
        return visited[v];
    }

    //获取两点的路径
    void path(int v, vector<int> &vec) {
        if (!hasPath(v)) {
            cout << "无法到达该点" << endl;
            return;
        }

        stack<int> s;
        int p = v;
        while (p != -1) {
            s.push(p);
            p = from[p];
        }
        vec.clear();
        while (!s.empty()) {
            int q = s.top();
            vec.push_back(q);
            s.pop();
        }

    }

    //显示路径
    void showPath(int v) {
        vector<int> vec;
        path(v, vec);
        if (vec.size() == 0) {
            return;
        }
        for (int i = 0; i < vec.size(); ++i) {
            cout<< vec[i];
            if(i == vec.size() - 1) {
                cout<<endl;
            } else {
                cout << "->";
            }
        }
    }


};

#endif //ALGORITHM_PATH_H
