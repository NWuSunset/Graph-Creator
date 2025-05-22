
#include "Graph.h"
#include <iostream>
#include <cstring>
#include <limits>
using namespace std;
/*
Implementation:
Create a program which can create graphs (we are using weighted edge, directed graphs), and it can search for the shortest path in the graph using Dijkstra's Algorithm (this is a famous algorithm you can go look up).
Use an adjacency table for the graph, which can be printed out. (You may assume that no more than 20 vertices will be in the table.) I HIGHLY recommend that you have the ability to print out the adjacency table, for debugging purposes.

Add Vertex: Enter a label for a vertex. Add it to the graph. (5 points)

Add Edge: Enter two node names and a weight (number). Add an edge between them, from the first node to the second node. (5 points)

Remove Vertex: Enter a vertex label and remove it from the graph. Remove all edges to that vertex.  (5 points)

Remove Edge: Enter two vertex labels, and remove an edge between them.  (5 points)

Find Shortest Path: Enter two vertex labels. Starting at the first label, use Dijkstra's algorithm to find a path between the first vertex and the last vertex.
Return the shortest path (and total) if it exists, or return that no path exists.  (5 points)
   */

bool userSelection(Graph* graph);

int main() {
  Graph* graph = new Graph();
  
  while (!userSelection(graph)) {
  }
   
  return 0;
}


bool userSelection(Graph* graph) {
    char userInput[20];
    cout <<
        "Type ADD VERTEX to add a vertex to the graph. Type ADD EDGE to add an edge to the graph. Type REMOVE VERTEX to remove a vertex. Type REMOVE EDGE to remove an edge. Type SHORTEST PATH to find the shortest path between two vertices. Type QUIT to quit"
        << endl;
    cin.getline(userInput, 20);

    //in case more than 12 characters are entered (so it won't break the program)
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Input Error. Input is too long" << endl;
    }

    if (strcasecmp(userInput, "ADD VERTEX") == 0) {
      char label;
      cout << "Enter the label of the vertex. It must be a single character" << endl;
      cin >> label;
      cout << label << endl;
      graph->addVertex(label);
      cin.ignore();
    } else if (strcasecmp(userInput, "ADD EDGE") == 0) {
      char source, dest;
      int len;

      cout << "Enter the SOURCE, DESINATION, LENGTH of the edge (separated by spaces)" << endl;
      cin >> source;
      cin >> dest;
      cin >> len;

      Vertex* v1 = graph->getVertex(source);
      Vertex* v2 = graph->getVertex(dest);
      
      graph->addEdge(v1, v2, len);
      cin.ignore();
    } else if (strcasecmp(userInput, "REMOVE VERTEX") == 0) {
      cout << "Enter the label of the vertex you want to remove" << endl;
      char label;
      cin >> label;
      graph->removeVertex(label);
      cin.ignore();
    } else if (strcasecmp(userInput, "REMOVE EDGE") == 0) {
      char source, dest;
      cout << "Enter the SOURCE and DESTINATION vertices of the edge you want to remove (separated by spaces)" << endl;
      cin >> source;
      cin >> dest;
      
      Vertex* v1 = graph->getVertex(source);
      Vertex* v2 = graph->getVertex(dest);
      
      graph->removeEdge(v1, v2);
      cin.ignore();
    } else if (strcasecmp(userInput, "SHORTEST PATH") == 0) {
      char label_1, label_2;
      cout << "Enter the label of VERTEX 1 followed by VERTEX 2 (separated by spaces)" << endl;
      cin >> label_1;
      cin >> label_2;
      Vertex* v1 = graph->getVertex(label_1);
      Vertex* v2 = graph->getVertex(label_2);
      cin.ignore();
      graph->findShortestPath(v1, v2); //from v1 to v2
    } else if (strcasecmp(userInput, "PRINT") == 0) {
      graph->printMatrix();
    }
    else if (strcasecmp(userInput, "QUIT") == 0) {
      return true;
    } else {
      cout << "Invalid input." << endl;
    }
    return false;
}
