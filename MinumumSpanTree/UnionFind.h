//
// Created by 宫宜栋 on 2017/6/28.
//

#ifndef ALGORITHM_UNIONFIND_H
#define ALGORITHM_UNIONFIND_H

/**
 * 并查集
 */
class UnionFind {

private:
    int capacity;
    int count;
    int *rank;
    int *parent;
public:
    UnionFind(int n) {
        capacity = n;
        count = n;
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    ~UnionFind() {
        delete[] parent;
        delete[] rank;
    }

    //查找元素
    int find(int p) {
        while (p != parent[p]) {
            p = parent[p];
        }
        return p;
    }

    //合并元素
    void unionElements(int p, int q) {
        int pRoot = find(p);
        int qRoot = find(q);
        if (pRoot == qRoot) {
            return;
        }

        if (rank[pRoot] > rank[qRoot]) {
            parent[qRoot] = pRoot;
        } else if (rank[pRoot] < rank[qRoot]) {
            parent[pRoot] = qRoot;
        } else {
            parent[qRoot] = pRoot;
            rank[pRoot]++;
        }
    }

    //判断是否连接
    bool isConnected(int p, int q) {
        return find(p) == find(q);
    }
};

#endif //ALGORITHM_UNIONFIND_H
