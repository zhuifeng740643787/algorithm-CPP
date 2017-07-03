//
// Created by 宫宜栋 on 2017/6/26.
//

#ifndef ALGORITHM_READGRAPH_H
#define ALGORITHM_READGRAPH_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;

template<typename Graph>
class ReadGraph {
public:
    ReadGraph(Graph &graph, const string &fileName) {
        ifstream file(fileName);
        string line;

        int V, E;
        assert(file.is_open());
        assert(getline(file, line));

        stringstream ss(line);
        ss >> V >> E;
        assert(graph.V() == V);
        for (int i = 0; i < E; i++) {
            assert(getline(file, line));
            int v, w;
            stringstream ss(line);
            ss >> v >> w;
            assert(v >= 0 && v < graph.V());
            assert(w >= 0 && w < graph.V());
            graph.addEdge(v, w);
        }

    }

    ~ReadGraph() {}
};

#endif //ALGORITHM_READGRAPH_H
