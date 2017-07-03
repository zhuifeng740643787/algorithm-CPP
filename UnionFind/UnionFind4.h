//
// Created by 宫宜栋 on 2017/6/23.
//

#ifndef ALGORITHM_UNIONFIND4_H
#define ALGORITHM_UNIONFIND4_H


#include <iostream>
#include <cassert>

using namespace std;

/**
 * 并查集优化
 * 判断是否含有相同的父节点
 * 基于rank(树高)优化，防止退化成O(n)
 */
class UnionFind4 {
private:
    int *parent;//父节点
    int *rank;//树高
    int count;

public:
    UnionFind4(int n) {
        count = n;
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            rank[i] = 1;
        }

    }

    ~UnionFind4() {
        delete[] parent;
        delete[] rank;
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

        if(rank[pRoot] < rank[qRoot]) {
            parent[pRoot] = qRoot;
            rank[qRoot] += rank[pRoot];
        } else if(rank[pRoot] > rank[qRoot]){
            parent[qRoot] = pRoot;
            rank[pRoot] += rank[qRoot];
        } else {
            parent[pRoot] = qRoot;
            rank[qRoot]++;
        }

    }

    friend ostream &operator<<(ostream &output, UnionFind4 *uf) {
        if(uf->count <= 100) {
            for (int i = 0; i < uf->count; ++i) {
                output << uf->find(i) << " ";
            }
            output << endl;
        }
        return output;
    }

};

#endif //ALGORITHM_UNIONFIND4_H
