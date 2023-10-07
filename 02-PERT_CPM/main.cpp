#include <bits/stdc++.h>

#include "graph.hpp"
#include "pert_cpm.hpp"

using namespace std;

int main() {
    Graph graph;

    // Receives all tasks from terminal
    Vertex origin;
    Vertex destination;
    Length length;
    while (cin >> origin >> destination >> length) {
        graph.addEdge(origin, destination, length);
    }

    Pert pert = Pert(graph);
    pert.print();

    CPM cpm = CPM(pert);
    cpm.print();

    return 0;
}
