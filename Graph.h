
#ifndef GRAPH_H
#define GRAPH_H
#include <vector>

//weighted edge-directed graphs
struct Node { //also known as a vertex in graph

};


class Graph {
    public:
        Graph();

        void addVertex();
        void addEdge();

        void removeVertex();
        void removeEdge();

        void findShortestPath(); //use Dijkstra's algorithm

private:
    int adjMatrix[20][20]{};
    //        If there is an edge from vertex i to j, mark adjMat[i][j] as 1.
    //        If there is no edge from vertex i to j, mark adjMat[i][j] as 0.
    std::vector<Node> vertices; //vector of verticies (nodes)
};


#endif //GRAPH_H
