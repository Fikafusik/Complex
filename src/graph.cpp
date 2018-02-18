
#include "graph.hpp"

Graph::Graph(int vertex_count) {
    v = new vertex[vertex_count + 1];
    e = new vertex[vertex_count + 1];
}

Graph::~Graph() {
    delete[] v;
    delete[] e;
}