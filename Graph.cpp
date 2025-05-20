#include <iostream>
#include <algorithm>
#include "Graph.h"

using namespace std;

Graph::Graph() = default;

void Graph::addVertex(char label) {
  Vertex* v = new Vertex(label);
  vertices.push_back(v);
  adjMatrix[tIndex][tIndex]; //add to adjacency matrix
  tIndex++;
}

void Graph::addEdge(Vertex* source, Vertex* dest, int len) {
  
}

void Graph::removeVertex(const char label) {

}

void Graph::removeEdge(int source, int dest) {

}

void Graph::findShortestPath(Vertex* v1, Vertex* v2) {
  
}

Vertex* Graph::getVertex(char label) {
  auto it = find_if(vertices.begin(), vertices.end(),
		    [label](const Vertex* v) { return v->label == label; });

  if (it != vertices.end()) {
    return (*it); //return the found vertex (as vertex pointer)
  } else {
    cout << "Vertex not found" << endl;
    return nullptr;
  } 
}
