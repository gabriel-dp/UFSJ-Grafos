#ifndef FILE_H
#define FILE_H

#include <bits/stdc++.h>

#include <fstream>

#include "graph.hpp"

using namespace std;

Graph readGraph(char* fileName) {
    Graph graph;

    ifstream GMLfile(fileName);

    string line;
    Length distance;
    Vertex i = 0, j = 0;
    while (getline(GMLfile, line)) {
        stringstream lineSplit(line);

        j = 0;
        while (lineSplit >> distance) {
            if (distance > 0) {
                graph.addEdge(i, j, distance);
            }
            j++;
        }
        i++;
    }

    return graph;
}

#endif