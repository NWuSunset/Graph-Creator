
#ifndef GRAPH_H
#define GRAPH_H
#include <vector>

//weighted edge-directed graphs
struct Vertex { //also known as a nodes in graph
  const char label;
};


class Graph {
public:
  Graph();
  
  void addVertex(char label);

  //source = 1st node ('from' node). dest = 2nd to ('to node). len = edge length
  void addEdge(int source, int dest, int len); 
  
  void removeVertex(char label);
  void removeEdge(int source, int dest);
  
  void findShortestPath(Vertex* v1, Vertex* v2); //use Dijkstra's algorithm
  
private:
  int adjMatrix[20][20]{}; //in format [source][destination] / [from][to]. So 'x' axis is the from side, and the 'y' axis will be the to side. Ex: adjMatrix[1][3] = 1; //distance from 1 to 3 = 1
  
  std::vector<Vertex> vertices; //vector of verticies (nodes)
};


#endif //GRAPH_H
