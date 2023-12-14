#include <bits/stdc++.h>

#include "file.hpp"
#include "graph.hpp"
#include "tsp.hpp"

using namespace std;

int main(int argc, char** argv) {
    if (argc != 2) {
        cout << "Correct way to run the program: '<program> <gml_file_path>'\n";
        return 1;
    }

    Graph graph = readGraph(argv[1]);

    TSP tsp(graph);
    cout << "(" << tsp.getBestPath().getDistance() << ")\n";
    tsp.getBestPath().print();

    return 0;
}