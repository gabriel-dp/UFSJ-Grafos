#ifndef QUEENS_H
#define QUEENS_H

#include "graph.hpp"

class Queens {
   private:
    Graph board;
    VertexGroup solution;
    int size;

   public:
    void findPositions(VertexGroup& selected, std::set<Vertex>::iterator actual) {
        for (auto it = actual; *it <= *(board.getVertexes().rbegin()); it++) {
            if (!board.getOutGroup(*it).containsOne(selected)) {
                selected.insert(*it);
                if (selected.getVertexes().size() == size) return;
                findPositions(selected, std::next(it));
                if (selected.getVertexes().size() == size) return;
                selected.remove(*it);
            }
        }
    }

    Queens(Graph& board, int size) : board(board), size(size) {
        VertexGroup selected;
        findPositions(selected, board.getVertexes().begin());
        solution = selected;
    }

    VertexGroup getSolution() {
        return this->solution;
    }

    void printSolution() {
        for (int i = 0; i < this->size; i++) {
            for (int j = 0; j < this->size; j++) {
                std::cout << "[" << (solution.find(i * size + j) ? "♛" : " ") << "]";
            }
            std::cout << "\n";
        }
    }
};

#endif