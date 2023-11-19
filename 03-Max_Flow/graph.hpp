#ifndef GRAPH_H
#define GRAPH_H

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

typedef int Vertex;
typedef int Length;

class Edge {
   private:
    Vertex origin, destination;
    Length length;

   public:
    Edge(Vertex origin, Vertex destination) : origin(origin), destination(destination) {}
    Edge(Vertex origin, Vertex destination, Length length) : origin(origin), destination(destination), length(length) {}

    Vertex getOrigin() {
        return origin;
    }

    Vertex getDestination() {
        return destination;
    }

    Length getLength() {
        return length;
    }

    void setLength(Length length) {
        this->length = length;
    }

    bool operator==(const Edge& e) const {
        return origin == e.origin && destination == e.destination;
    }
};

class VertexGroup {
   private:
    std::set<Vertex> vertexes;

   public:
    std::set<Vertex> getVertexes() {
        return vertexes;
    }

    void insert(Vertex v) {
        vertexes.insert(v);
    }

    void remove(Vertex v) {
        vertexes.erase(v);
    }

    bool find(Vertex v) {
        return vertexes.find(v) != vertexes.end();
    }

    void clear() {
        vertexes.clear();
    }

    bool contains(VertexGroup group) {
        for (Vertex v : group.getVertexes()) {
            if (!find(v)) return false;
        }
        return true;
    }
};

class Graph {
   private:
    std::set<Vertex> vertexes;
    std::vector<Edge> edges;

   public:
    std::set<Vertex> getVertexes() {
        return vertexes;
    }

    std::vector<Edge> getEdges() {
        return edges;
    }

    bool searchEdge(Vertex origin, Vertex dest, Edge** edge) {
        auto found = std::find(edges.begin(), edges.end(), Edge(origin, dest));
        if (found != edges.end()) {
            *edge = &(*found);
            return true;
        }
        return false;
    }

    void addVertex(Vertex v) {
        vertexes.insert(v);
    }

    void addEdge(Vertex origin, Vertex destination, Length length) {
        addVertex(origin);
        addVertex(destination);
        edges.push_back(Edge(origin, destination, length));
    }

    std::vector<Edge> getOutEdges(Vertex v) {
        std::vector<Edge> outEdges;
        for (Edge e : edges) {
            if (e.getOrigin() == v) {
                outEdges.push_back(e);
            }
        }
        return outEdges;
    }

    VertexGroup getOutGroup(Vertex v) {
        VertexGroup outVertexes;
        for (Edge e : getOutEdges(v)) {
            if (e.getOrigin() == v) {
                outVertexes.insert(e.getDestination());
            }
        }
        return outVertexes;
    }

    Graph generateReverseGraph() {
        Graph reverse;
        for (Edge edge : edges) {
            reverse.addEdge(edge.getDestination(), edge.getOrigin(), edge.getLength());
        }
        return reverse;
    }

    Graph generateCopy() {
        Graph copy;
        for (Edge edge : edges) {
            copy.addEdge(edge.getOrigin(), edge.getDestination(), edge.getLength());
        }
        return copy;
    }
};

#endif