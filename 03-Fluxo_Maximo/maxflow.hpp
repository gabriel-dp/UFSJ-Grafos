#ifndef MAXFLOW_H
#define MAXFLOW_H

#include <limits.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>

#include "./graph.hpp"

class MaxFlow {
   private:
    Length maxFlow;

    bool bfs(Graph& rGraph, Vertex s, Vertex t, std::map<Vertex, Vertex>& parent) {
        std::map<Vertex, bool> visited;

        std::queue<Vertex> q;
        q.push(s);
        visited[s] = true;

        while (!q.empty()) {
            Vertex u = q.front();
            q.pop();

            for (Vertex v : rGraph.getOutGroup(u).getVertexes()) {
                Edge* reverse;
                rGraph.searchEdge(parent[v], v, &reverse);
                if (visited.find(v) == visited.end() && reverse->getLength() > 0) {
                    q.push(v);
                    parent[v] = u;
                    visited[v] = true;
                }
            }
        }

        return visited[t];
    }

   public:
    MaxFlow(Graph& graph, Vertex origin, Vertex destination) {
        Graph rGraph = graph.generateCopy();

        std::map<Vertex, Vertex> parent;

        while (bfs(rGraph, origin, destination, parent)) {
            Length path_flow = INT_MAX;

            for (Vertex v = destination; v != origin; v = parent[v]) {
                Edge* returnEdge;
                rGraph.searchEdge(parent[v], v, &returnEdge);
                path_flow = std::min(path_flow, returnEdge->getLength());
            }

            for (Vertex v = destination; v != origin; v = parent[v]) {
                Edge **normal, **reverse;
                rGraph.searchEdge(v, parent[v], normal);
                rGraph.searchEdge(parent[v], v, reverse);
                (*normal)->setLength((*normal)->getLength() + path_flow);
                (*reverse)->setLength((*reverse)->getLength() - path_flow);
            }

            maxFlow += path_flow;
        }

        for (Edge e : rGraph.getEdges()) {
            Edge* originalEdge;
            graph.searchEdge(e.getOrigin(), e.getDestination(), &originalEdge);
            Length elementarFlow = originalEdge->getLength() - e.getLength();
            printf("Edge (%d -> %d) flow: %d\n", e.getOrigin(), e.getDestination(), e.getLength());
        }
    }

    Length getMaxFlow() {
        return maxFlow;
    }
};

#endif