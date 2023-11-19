#include <bits/stdc++.h>

#include "graph.hpp"
#include "maxflow.hpp"

using namespace std;

int main() {
    Graph graph;

    // Receives all edges from terminal
    Vertex origin, destination;
    Length flow;
    while (cin >> origin >> destination >> flow) {
        graph.addEdge(origin, destination, flow);
    }

    MaxFlow mf = MaxFlow(graph, *(graph.getVertexes().begin()), *(graph.getVertexes().rbegin()));

    cout << "Max Flow = " << mf.getMaxFlow() << "\n";

    return 0;
}
