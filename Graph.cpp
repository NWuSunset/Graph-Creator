#include <iostream>
#include <algorithm>
#include "Graph.h"

using namespace std;

Graph::Graph() = default;

void Graph::addVertex(char label) {
  if (tIndex == 19) {
    cout << "No more than 20 vertices" << endl;
    return;
  }
  
  Vertex* v = new Vertex(label);
  v->index = tIndex; //set it's respective index
  vertices.push_back(v);
  //adjMatrix[tIndex][tIndex]; //add to adjacency matrix (distance between node and itself is 0)
  tIndex++;
}

void Graph::addEdge(Vertex* source, Vertex* dest, int len) {
  adjMatrix[source->index][dest->index] = len;
}

void Graph::removeVertex(const char label) {
  Vertex* toRemove = getVertex(label);

  //erase that from the vector
  vertices.erase(remove(vertices.begin(), vertices.end(), toRemove), vertices.end());
  delete toRemove;
}

void Graph::removeEdge(Vertex* source, Vertex* dest) {
  adjMatrix[source->index][dest->index] = 0;
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

void Graph::printMatrix() {
  cout << "  ";
  for (auto it = vertices.begin(); it != vertices.end(); it++) {
    cout << (*it)->label << " ";
  }
  cout << endl;

  
  for (int i = 0; i < tIndex; i++) {
    cout << vertices[i]->label << " ";
    for (int j = 0; j < tIndex; j++) {
      if (adjMatrix[i][j] != 0) {
	cout << adjMatrix[i][j] << " ";
      } else {
	cout << "  ";
      }
    }
    cout << endl;
  }
}
