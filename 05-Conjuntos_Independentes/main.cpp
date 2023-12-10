#include <bits/stdc++.h>

#include "gml.hpp"
#include "graph.hpp"
#include "queens.hpp"

using namespace std;

int main(int argc, char** argv) {
    if (argc != 2) {
        cout << "Correct way to run the program: '<program> <gml_file_path>'\n";
        return 1;
    }

    Graph board = readGraph(argv[1]);
    Queens queens = Queens(board, 8);

    queens.getSolution().print();
    queens.printSolution();

    return 0;
}