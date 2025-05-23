#include <iostream>
#include <algorithm>
#include "Graph.h"
#include <climits>

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
    tIndex--;
}

void Graph::removeEdge(Vertex* source, Vertex* dest) {
    adjMatrix[source->index][dest->index] = 0;
}

void Graph::findShortestPath(Vertex* source, Vertex* dest) {
    int pathLength = 0;
    vector<int> path = DijkstraAlgorithm(source, tIndex + 1);
    for (int i = 0; i < dest->index; i++) { //print a path until destination
        cout << vertices[path[i]] << " "; //print out the labels
        pathLength += path[i]; //add to path lenght
    }
    cout << endl;
    cout << "Total path length: " << pathLength << endl;
}

vector<int> Graph::DijkstraAlgorithm(Vertex* source, int numV) {
    priority_queue<Vertex*, vector<Vertex*>, greater<Vertex*>> pq; //stores vertex priority (integer)
    vector<int> dist(numV, INT_MAX); //vector of distances with values starting at 'infinity'

    //set source priority and add it to the queue
    source->priority = 0;
    pq.push(source);
    dist[source->index] = 0; //also update it in the distance vector


    //loop through queue and let min = first vertex in queue
    //Loop until we get to the destination node.
    while (!pq.empty()) {
        //get the first vertex
        Vertex* min = pq.top();
        pq.pop(); //then pop it from the queue

        //Then loop through all adjacent vertices to min
        for (int a = 0; a < tIndex; a++) {
            if (adjMatrix[min->index][a] != 0) { //if there is adjacency (distance != 0)
                //alt = distance to min + distance from min to the adjacent node
                const int alt = dist[min->index] + adjMatrix[min->index][a];

                //if alt distance < distance to destination (neighbor to min)
                if (alt < dist[a]) {
                    //Then update the distance to the adjacent node in the distance vector (index represented by a)
                    dist[a] = alt;
                    pq.push(vertices[a]); //also update the priority queue with the new info
                }
            }
        }
    }
    return dist; //return the distance vector, it's indices should match with the vertices vector
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
