#ifndef TSP_H
#define TSP_H

#include <bits/stdc++.h>

#include "graph.hpp"

using namespace std;

#define ITERATIONS 10
#define RANDOM_PATH_TRIES 50
#define SELECTION_FACTOR 3
#define MUTATION_TRIES 1

#define INVALID_LENGTH -1

class Path {
   private:
    Graph& graph;
    vector<Vertex> path;
    set<Vertex> vertexes;
    Length distance = 0;

    void invalidate() {
        path.clear();
        distance = INVALID_LENGTH;
    }

   public:
    Path(Graph& graph) : graph(graph) {}

    vector<Vertex> getPath() const {
        return path;
    }

    Length getDistance() const {
        if (path.size() != graph.getVertexes().size() + 1) return INVALID_LENGTH;
        return this->distance;
    }

    bool insert(Vertex v) {
        if (distance == INVALID_LENGTH) return false;

        if (!path.empty()) {
            Edge* e;
            if (!graph.searchEdge(*path.rbegin(), v, &e)) {
                invalidate();
                return false;
            }

            if (vertexes.find(v) != vertexes.end()) {
                if (path.size() != graph.getVertexes().size() || *path.begin() != v) {
                    invalidate();
                    return false;
                }
            }

            this->distance += e->getLength();
        }

        path.push_back(v);
        vertexes.insert(v);

        return true;
    }

    bool swap(int index1, int index2, Path& newPath) {
        if (path.size() != graph.getVertexes().size() + 1) {
            newPath.invalidate();
            return false;
        }

        vector<Vertex> copy = this->path;

        // Swap vertexes
        Vertex aux = copy[index1];
        copy[index1] = copy[index2];
        copy[index2] = aux;

        // Deal with initial and final vertex changes
        if (path[index1] == *path.begin()) {
            copy.at(0) = path[index2];
            copy.at(copy.size() - 1) = path[index2];
        } else if (path[index2] == *path.begin()) {
            copy.at(0) = path[index1];
            copy.at(copy.size() - 1) = path[index1];
        }

        // Creates new path
        for (Vertex v : copy) {
            if (!newPath.insert(v)) {
                newPath.invalidate();
                return false;
            }
        }

        return true;
    }

    void print() const {
        for (auto it = path.begin(); it != path.end(); it++) {
            if (it != path.begin()) {
                cout << "-> ";
            }
            cout << *it << " ";
        }
        cout << "\n";
    }

    bool operator<(const Path& other) const {
        if (this->getDistance() != other.getDistance()) {
            if (this->getDistance() == INVALID_LENGTH) return false;
            if (other.getDistance() == INVALID_LENGTH) return true;
            return this->getDistance() < other.getDistance();
        }
        return this->getPath() < other.getPath();
    }

    bool operator==(const Path& other) const {
        return this->getDistance() == other.getDistance() && this->path == other.getPath();
    }
};

class TSP {
   private:
    Graph graph;
    set<Path> solutions;

    void selection(int factor) {
        // Select the new longest path distance allowed to be in the solutions
        int pivot = ceil(solutions.size() / factor);

        // Erase all elements after the pivot
        auto it = solutions.begin();
        advance(it, pivot);
        auto eraseStart = upper_bound(solutions.begin(), solutions.end(), *it);
        solutions.erase(eraseStart, solutions.end());
    }

    void generateRandomPaths(int tries) {
        for (int i = 0; i < tries; i++) {
            // Create a new
            vector<Vertex> vertexes;
            for (Vertex v : graph.getVertexes()) {
                vertexes.push_back(v);
            }

            // Shuffles the vertexes vector
            random_device rd;
            mt19937 g(rd());
            shuffle(vertexes.begin(), vertexes.end(), g);
            vertexes.push_back(*vertexes.begin());  // The destination is the same origin vertex

            // Attempt to create a new path with the random vertexes
            Path newPath(graph);
            for (Vertex v : vertexes) {
                if (!newPath.insert(v)) return;
            }
            solutions.insert(newPath);
        }
    }

    void mutate(int tries) {
        for (Path p : solutions) {
            for (int i = 0; i < tries; i++) {
                // Generate two random indexes
                random_device rd;
                mt19937 g(rd());
                uniform_int_distribution<std::size_t> distribution(0, p.getPath().size() - 1);
                int index1 = distribution(g);
                int index2 = distribution(g);

                // Attempt to swap the two elements in the indexes
                Path mutated(graph);
                if (p.swap(index1, index2, mutated)) {
                    solutions.insert(mutated);
                }
            }
        }
    }

   public:
    TSP(Graph& graph) : graph(graph) {
        generateRandomPaths(RANDOM_PATH_TRIES);

        for (int i = 0; i < ITERATIONS; i++) {
            selection(SELECTION_FACTOR);
            mutate(MUTATION_TRIES);
        }

        solutions.erase(next(solutions.begin()), solutions.end());
    }

    Path getBestPath() {
        if (solutions.empty()) {
            return Path(graph);  // Returns a invalid path
        }
        return *solutions.begin();
    }
};

#endif