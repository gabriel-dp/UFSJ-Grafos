#include <bits/stdc++.h>

using namespace std;

// Sets all data types
#define VERTEX char
#define VERTEX_GROUP set<VERTEX>
#define GRAPH map<VERTEX, set<VERTEX>>

// Uses Deep-First-Search to find closures
void closureDFS(VERTEX vertex, GRAPH &graph, VERTEX_GROUP &group) {
    for (auto neighbor : graph.at(vertex)) {
        if (group.find(neighbor) == group.end()) {
            group.insert(neighbor);
            closureDFS(neighbor, graph, group);
        }
    }
}

// Returns the intersection of two vertex groups
VERTEX_GROUP intersectionVertexes(VERTEX_GROUP &group1, VERTEX_GROUP &group2) {
    VERTEX_GROUP intersection;

    for (VERTEX v : group1) {
        if (group2.find(v) != group2.end()) {
            intersection.insert(v);
        }
    }

    return intersection;
}

// Returns a graph with the reversed connections
GRAPH generateReverseGraph(GRAPH &graph) {
    GRAPH reverse;
    for (auto vertex : graph) {
        for (auto neighbor : vertex.second) {
            reverse[neighbor].insert(vertex.first);
            reverse[vertex.first];
        }
    }
    return reverse;
}

// Return all strong connected components from a graph
set<VERTEX_GROUP> getStrongConnectedComponents(GRAPH &graph) {
    set<VERTEX_GROUP> result;
    GRAPH reverse = generateReverseGraph(graph);

    for (auto vertex : graph) {
        VERTEX_GROUP graphClosure, reverseClosure, intersection;
        closureDFS(vertex.first, graph, graphClosure);
        closureDFS(vertex.first, reverse, reverseClosure);

        intersection = intersectionVertexes(graphClosure, reverseClosure);
        if (!intersection.empty()) {
            result.insert(intersection);
        }
    }

    return result;
}

// Prints all components
void printComponents(set<VERTEX_GROUP> &components) {
    for (auto component : components) {
        cout << "{ ";
        for (auto vertex : component) {
            cout << vertex << " ";
        }
        cout << "}\n";
    }
}

int main() {
    GRAPH graph;

    // Receives the graph from file
    VERTEX origin, destination;
    while (cin >> origin >> destination) {
        graph[origin].insert(destination);
        graph[destination];  // Initializes destination vertex as empty if necessary
    }

    // Get and print all strong connected components
    set<VERTEX_GROUP> components = getStrongConnectedComponents(graph);
    printComponents(components);

    return 0;
}