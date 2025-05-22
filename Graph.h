
#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <cstring>
#include <queue>

//weighted edge-directed graphs
struct Vertex { //also known as a nodes in graph
  char label;
  int index; //index of the number in the adjacency table
  int priority;
  
  Vertex(char label) {
    this->label = label;
  }
};


class Graph {
public:
  Graph();
  
  void addVertex(char label);

  //source = 1st node ('from' node). dest = 2nd to ('to node). len = edge length
  void addEdge(Vertex* source, Vertex* dest, int len); 
  
  void removeVertex(char label);
  void removeEdge(Vertex* source, Vertex* dest);

  
  void findShortestPath(Vertex* source, Vertex* dest, int numV); //use Dijkstra's algorithm
  
  Vertex* getVertex(char label);

  void printMatrix();

  int tIndex = 0;
private:
  //note: distance of 0 means no connection (won't be displayed in print out)
  int adjMatrix[20][20]{}; //in format [source][destination] / [from][to]. So 'x' axis is the from side, and the 'y' axis will be the to side. Ex: adjMatrix[1][3] = 1; //distance from 1 to 3 = 1
  
  //int tIndex = 0; //tracks index we are in the table
  std::vector<Vertex*> vertices; //vector of verticies (nodes)
};


#endif //GRAPH_H
