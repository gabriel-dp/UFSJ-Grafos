#ifndef VERTEX_COVER_H
#define VERTEX_COVER_H

#include <map>

#include "graph.hpp"

class VertexCover {
   private:
    Graph graph;
    VertexGroup vertexCover;

   public:
    // Verifies if a vertex can be added in the vertex cover
    bool canBeAdded(Vertex v) {
        bool canBeAdded = true;
        for (Vertex u : graph.getOutGroup(v).getVertexes()) {
            if (vertexCover.find(u)) {
                canBeAdded = false;
                break;
            }
        }
        return canBeAdded;
    }

    VertexCover(Graph& graph) : graph(graph) {
        // Divide vertexes by the number of neighbors
        std::map<int, VertexGroup> groupsVertex;
        for (Vertex v : graph.getVertexes()) {
            groupsVertex[graph.getOutEdges(v).size()].insert(v);
        }

        // Verifies vertexes with more than 1 neighbor (not equal) in ascending order
        for (auto it = groupsVertex.upper_bound(1); it != groupsVertex.end(); it++) {
            for (Vertex v : it->second.getVertexes()) {
                if (canBeAdded(v)) vertexCover.insert(v);
            }
        }

        // Verifies vertexes with exactly 1 neighbor
        for (Vertex v : groupsVertex[1].getVertexes()) {
            if (canBeAdded(v)) vertexCover.insert(v);
        }
    }

    VertexGroup getVertexCover() {
        return vertexCover;
    }
};

#endif