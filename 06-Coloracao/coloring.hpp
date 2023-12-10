#ifndef COLORING_H
#define COLORING_H

#include <map>

#include "graph.hpp"

class Coloring {
   private:
    Graph graph;
    std::map<int, VertexGroup> colors;  // colorId, vertexes

    void classHeuristic() {
        colors[0];

        for (Vertex v : graph.getVertexes()) {
            bool inserted = false;
            for (auto color : colors) {
                if (!graph.getOutGroup(v).containsOne(color.second)) {
                    colors[color.first].insert(v);
                    inserted = true;
                    break;
                }
            }
            if (!inserted) {
                colors[colors.rbegin()->first + 1].insert(v);
            }
        }
    }

   public:
    Coloring(Graph& graph) : graph(graph) {
        classHeuristic();
    }

    std::map<int, VertexGroup> getColors() {
        return this->colors;
    }

    void printColors() {
        for (auto color : colors) {
            std::cout << color.first << " { ";
            for (Vertex v : color.second.getVertexes()) {
                std::cout << v << " ";
            }
            std::cout << "}\n";
        }
    }
};

#endif