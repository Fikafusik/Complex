
#ifndef __GRAPH_HPP__
#define __GRAPH_HPP__

typedef int vertex;

struct vertex_pair {
    vertex v;
    vertex u;
}

typedef vertex_pair edge;

// Граф. Тривиальный вариант, вершины представляют из себя целые числа.
class Graph {
private:
    vertex * v;
    edge * e;
public:
    Graph(int);
    
    ~Graph()

    // TODO
    void add_edge(vertex, vertex);

    bool is_connectivity();
    bool is_tree();
    bool is_complete();
    bool is_bipartite();
};

#endif