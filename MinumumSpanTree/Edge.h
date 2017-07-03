//
// Created by 宫宜栋 on 2017/6/26.
//

#ifndef ALGORITHM_EDGE_H
#define ALGORITHM_EDGE_H

#include <iostream>
#include <cassert>

using namespace std;

/**
 * 有权图的边
 */
template<typename Weight>
class Edge {
private:
    int v;
    int w;
    Weight weight;
public:
    Edge(){}
    Edge(int v, int w, Weight weight) {
        this->v = v;
        this->w = w;
        this->weight = weight;
    }

    ~Edge() {}

    //获取另一个顶点
    int other(int p) {
        assert(p == v || p == w);
        return p == v ? w : v;
    }

    Weight wt() {
        return weight;
    }

    int getV() {
        return v;
    }

    int getW() {
        return w;
    }

    friend ostream &operator<<(ostream &os, const Edge *edge) {
        os << edge->v << "->" << edge->w << ":" << edge->weight<<" ";
        return os;
    }

    //重载小于运算符
    bool operator<(Edge<Weight> &e) {
        return weight < e.wt();
    }
    //重载小于等于运算符
    bool operator<=(Edge<Weight> &e) {
        return weight <= e.wt();
    }
    //重载等于运算符
    bool operator==(Edge<Weight> &e) {
        return weight == e.wt();
    }

    //重载大于运算符
    bool operator>(Edge<Weight> &e) {
        return weight > e.wt();
    }
    //重载大于等于运算符
    bool operator>=(Edge<Weight> &e) {
        return weight >= e.wt();
    }
};

#endif //ALGORITHM_EDGE_H
