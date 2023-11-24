#include <bits/stdc++.h>

#include <set>

#include "gml.hpp"
#include "graph.hpp"
#include "vertex_cover.hpp"

using namespace std;

int main(int argc, char** argv) {
    if (argc != 2) {
        cout << "Correct way to run the program: '<program> <gml_file_path>'\n";
        return 1;
    }

    Graph graph = readGraph(argv[1]);
    VertexCover vertexCover = VertexCover(graph);

    cout << "Vertex | ( Neighbors )\n";
    for (Vertex v : vertexCover.getVertexCover().getVertexes()) {
        cout << v << " | ( ";
        for (Vertex u : graph.getOutGroup(v).getVertexes()) {
            cout << u << " ";
        }
        cout << ")\n";
    }

    return 0;
}
