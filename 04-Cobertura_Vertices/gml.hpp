#ifndef GML_H
#define GML_H

#include <fstream>

#include "graph.hpp"

using namespace std;

// Generates the graph from a .gml file
Graph readGraph(char* fileName) {
    Graph graph;

    string line, text;
    ifstream GMLfile(fileName);

    while (getline(GMLfile, line)) {
        stringstream lineSplit(line);
        lineSplit >> text;

        // Verifies the first word
        if (text == "node") {
            int id;

            getline(GMLfile, line);
            lineSplit = stringstream(line);
            lineSplit >> text >> id;

            graph.addVertex(id);

            // Jump to next element
            getline(GMLfile, line);
            getline(GMLfile, line);

        } else if (text == "edge") {
            int origin, target;

            getline(GMLfile, line);
            lineSplit = stringstream(line);
            lineSplit >> text >> origin;

            getline(GMLfile, line);
            lineSplit = stringstream(line);
            lineSplit >> text >> target;

            graph.addEdge(origin, target);
            graph.addEdge(target, origin);

            // Jump to next element
            getline(GMLfile, line);
            getline(GMLfile, line);

        } else {
            continue;
        }
    }

    return graph;
}

#endif