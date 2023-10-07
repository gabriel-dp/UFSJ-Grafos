#ifndef PERT_CPM_H
#define PERT_CPM_H

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <utility>

#include "graph.hpp"

class Pert {
   private:
    std::map<Vertex, std::pair<Length, Length>> times;  // Earliest and Latest times

   public:
    std::map<Vertex, std::pair<Length, Length>> getTimes() {
        return times;
    }

    Pert(Graph& graph) {
        std::queue<Vertex> search;
        VertexGroup history;
        Graph reverse = graph.generateReverseGraph();

        // Stating vertexes
        for (Vertex vr : reverse.getVertexes()) {
            if (reverse.getOutEdges(vr).size() == 0) {
                search.push(vr);
                times[vr].first = 0;  // Sets Earliest time to 0
            }
        }

        // Defines all Earliest times
        while (search.size() > 0) {
            Vertex actual = search.front();
            search.pop();
            for (Edge e : graph.getOutEdges(actual)) {
                Vertex dest = e.getDestination();
                if (!history.find(dest)) {
                    search.push(dest);
                    times[dest].first = times[actual].first + e.getLength();
                    history.insert(dest);
                } else {
                    times[dest].first = std::max(times[dest].first, times[actual].first + e.getLength());
                }
            }
        }

        // Clear history to repeat the process returning to the start
        history.clear();

        // Get final vertexes
        for (Vertex v : graph.getVertexes()) {
            if (graph.getOutEdges(v).size() == 0) {
                search.push(v);
                times[v].second = times[v].first;  // Sets latest time to early
            }
        }

        // Defines all Latest times
        while (search.size() > 0) {
            Vertex actual = search.front();
            search.pop();
            for (Edge e : reverse.getOutEdges(actual)) {
                Vertex dest = e.getDestination();
                if (!history.find(dest)) {
                    search.push(dest);
                    times[dest].second = times[actual].second - e.getLength();
                    history.insert(dest);
                } else {
                    times[dest].first = std::min(times[dest].second, times[actual].second - e.getLength());
                }
            }
        }
    }

    void print() {
        printf("| ## | Min | Max | Slack |\n");
        for (auto t : times) {
            Vertex v = t.first;
            Length min = t.second.first;
            Length max = t.second.second;
            Length slack = max - min;

            printf("| %2d | %3d | %3d | %5d |\n", v, min, max, slack);
        }
        printf("\n");
    }
};

class CPM {
   private:
    std::set<Vertex> vertexes;

   public:
    std::set<Vertex> getVertexes() {
        return vertexes;
    }

    CPM(Pert& pert) {
        for (auto t : pert.getTimes()) {
            if (t.second.first == t.second.second) {
                vertexes.insert(t.first);
            }
        }
    }

    void print() {
        printf("Critical path:\n");
        for (Vertex v : vertexes) {
            printf("(%2d)", v);
            if (*(vertexes.rbegin()) != v) {
                printf(" -> ");
            }
        }
        printf("\n");
    }
};

#endif