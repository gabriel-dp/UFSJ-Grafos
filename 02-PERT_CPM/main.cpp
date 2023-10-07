#include <bits/stdc++.h>

#include "graph.hpp"

using namespace std;

int main() {
    Graph graph;
    Vertex origin, destination;
    Length length;

    while (cin >> origin >> destination >> length) {
        graph.addEdge(origin, destination, length);
    }

    return 0;
}
