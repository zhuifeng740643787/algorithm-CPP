//
// Created by 宫宜栋 on 2017/6/23.
//

#ifndef ALGORITHM_UNIONFIND2_H
#define ALGORITHM_UNIONFIND2_H


#include <iostream>
#include <cassert>

using namespace std;

/**
 * 并查集优化
 * 判断是否含有相同的父节点
 */
class UnionFind2 {
private:
    int *parent;//父节点
    int count;

public:
    UnionFind2(int n) {
        count = n;
        parent = new int[n];
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }

    }

    ~UnionFind2() {
        delete[] parent;
    }

    //查找
    int find(int p) {
        assert(p >= 0 && p < count);
        while (p != parent[p]) {
            p = parent[p];
        }
        return p;
    }

    bool isConnected(int p, int q) {
        return find(p) == find(q);
    }

    //合并
    void unionElements(int p, int q) {
        int pRoot = find(p);
        int qRoot = find(q);

        if (pRoot == qRoot) {
            return;
        }

        parent[pRoot] = qRoot;

    }

    friend ostream &operator<<(ostream &output, UnionFind2 *uf) {
        if(uf->count <= 100) {
            for (int i = 0; i < uf->count; ++i) {
                output << uf->find(i) << " ";
            }
            output << endl;
        }
        return output;
    }

};

#endif //ALGORITHM_UNIONFIND2_H
