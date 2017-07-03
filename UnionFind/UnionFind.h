//
// Created by 宫宜栋 on 2017/6/23.
//

#ifndef ALGORITHM_UNIONFIND_H
#define ALGORITHM_UNIONFIND_H


#include <iostream>
#include <cassert>

using namespace std;

/**
 * 并查集
 * 解决连接问题
 * 通过比较id的值
 */
class UnionFind {
private:
    int *id;
    int count;

public:
    UnionFind(int n) {
        count = n;
        id = new int[n];
        for (int i = 0; i < n; ++i) {
            id[i] = i;
        }

    }

    ~UnionFind() {
        delete[]id;
    }

    //查找
    int find(int p) {
        assert(p >= 0 && p < count);
        return id[p];
    }

    bool isConnected(int p, int q) {
        return find(p) == find(q);
    }

    //合并
    void unionElements(int p, int q) {
        int pID = find(p);
        int qID = find(q);

        if (pID == qID) {
            return;
        }
        for (int i = 0; i < count; ++i) {
            if (id[i] == pID) {
                id[i] = qID;
            }
        }
    }

    friend ostream &operator<<(ostream &output, UnionFind *uf) {
        if (uf->count <= 100) {
            for (int i = 0; i < uf->count; ++i) {
                output << uf->id[i] << " ";
            }
        }
        output << endl;
        return output;
    }

};

#endif //ALGORITHM_UNIONFIND_H
