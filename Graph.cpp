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
    const vector<int> prev = DijkstraAlgorithm(source, vertices.size());

    vector<int> path;
    int curr = dest->index; //start at the destination's index

    //If previous has not been updated in the algorithm function
    if (prev[curr] == -1 && curr != source->index) {
        cout << "NO path exists" << source->label << "and " << dest->label << endl;
        return;
    }

    //Build the path (from the destination index going backward).
    while (curr != -1) {
        path.push_back(curr);
        curr = prev[curr];
    }

    //Reverse the path to show it going forward.
    reverse(path.begin(), path.end());

    int pathLength = 0;

    //then go through the path and display it.
    for (auto i = 0; i < path.size(); i++) {
        cout << vertices[path[i]]->label;

        //update distance
        if (i < path.size() - 1) {
            int nextIndex = path[i+1];
            pathLength += adjMatrix[path[i]][nextIndex];
            cout << "->";
        }
    }
    cout << endl;
    cout << "Total path length: " << pathLength << endl;
}

vector<int> Graph::DijkstraAlgorithm(Vertex* source, int numV) {
    auto compare = [](Vertex* a, Vertex* b) //Comparison for priority queue
    {
        return a->priority > b->priority; //if first vertex priority > second vertex priority.
    };

    priority_queue<Vertex*, vector<Vertex*>, decltype(compare)> pq(compare); //stores vertex priority (integer)
    vector<int> dist(numV, INT_MAX); //vector of distances with values starting at 'infinity'
    vector<int> prev(numV, -1); //previous vertex in path (represented by -1)
   // vector<bool> visited(numV, false); //tracked the visited vertices

    //set source priority and add it to the queue
    source->priority = 0;
    pq.push(source);
    dist[source->index] = 0; //also update it in the distance vector


    //loop through queue and let min = first vertex in queue
    //Loop until we get to the destination node.
    while (!pq.empty()) {
        //get the first vertex
        Vertex* curr = pq.top();
        pq.pop(); //then pop it from the queue

        const int u = curr->index; //easier to keep track

        //Then loop through all adjacent vertices to min
        for (int v = 0; v < tIndex; v++) {
            if (adjMatrix[u][v] != 0) { //if there is adjacency (distance != 0)
                //alt = distance to min + distance from min to the adjacent node
                const int alt = dist[u] + adjMatrix[u][v];

                //if alt distance < distance to destination then we found a better path
                if (alt < dist[v]) {
                    //Then update the distance to the adjacent node in the distance vector (index represented by a)
                    dist[v] = alt;
                    prev[v] = u;

                    vertices[v]->priority = alt;
                    pq.push(vertices[v]); //also update the priority queue with the new info (decrease priority of v)
                }
            }
        }
    }
    return prev; //return the prev vector (so we can go backwards), it's indices should match with the vertices vector
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
