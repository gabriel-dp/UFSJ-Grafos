#include <bits/stdc++.h>

#include "coloring.hpp"
#include "gml.hpp"
#include "graph.hpp"

using namespace std;

void printBoard(int size, map<int, VertexGroup> colors) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << "[";
            for (auto color : colors) {
                int position = i * 8 + j;
                if (color.second.find(position)) {
                    std::cout << std::setw(2) << color.first;
                    break;
                }
            }
            std::cout << "]";
        }
        std::cout << "\n";
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        cout << "Correct way to run the program: '<program> <gml_file_path>'\n";
        return 1;
    }

    Graph board = readGraph(argv[1]);
    Coloring coloring = Coloring(board);

    coloring.printColors();

    cout << "\n";

    printBoard(8, coloring.getColors());

    return 0;
}