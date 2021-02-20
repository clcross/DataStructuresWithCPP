#include <limits.h>
#include <iostream>
#include <vector>
#include <set>

const int INFINITY = INT_MAX;

// our weight is an int
std::vector<std::vector<int>> am;

void print(std::vector<std::vector<int>> &am) {
    for (unsigned int i = 0; i < am.size(); i++) {
        for (unsigned int j = 0; j < am[i].size(); j++) {
            if (am[i][j] == INFINITY) {
                std::cout << "I ";
            } else {
                std::cout << am[i][j] << " ";
            }
        }
        std::cout << "\n";
    }
}

void print(int node) {
    std::cout << "I have maybe possibly visited node #" << node << ", but I don't know... for reals...\n";
}

void depth_traversal_rec(void (*visit)(int node), std::vector<std::vector<int>> &am, std::set<int> &visited, int vertex) {
    // If the vertex has already been visited, exit!
    if (visited.find(vertex) != visited.end()) {
        return;
    }
    visited.insert(vertex);
    (*visit)(vertex);
    // Find any other nodes we can visit.
    for (unsigned i = 0; i < am[vertex].size(); i++) {
        if (am[vertex][i] > 0 && am[vertex][i] < INFINITY) {
            depth_traversal_rec(visit, am, visited, i);
        }
    }
}

void depth_traversal(void (*visit)(int node), std::vector<std::vector<int>> &am) {
    std::set<int> visited;
    for (unsigned int i = 0; i < am.size(); i++) {
        depth_traversal_rec(visit, am, visited, i);
    }
}

int main(int argc, char *argv[]) {
    int size = 10;
    am.resize(size);
    for (int i = 0; i < size; i++) {
        am[i].resize(size);
        for (int j = 0; j < size; j++) {
            am[i][j] = INFINITY;
        }
        am[i][i] = 0;
    }
    print(am);

    // We want to add edges:
    am[0][1] = 45;
    am[0][2] = 100;
    am[1][0] = 35;
    am[1][3] = 160;
    am[1][4] = 140;
    am[2][5] = 500;
    am[2][6] = 60;
    am[3][2] = 120;
    am[4][2] = 100;
    am[5][1] = 360;
    am[6][0] = 220;

    print(am);
    depth_traversal(&print, am);
    // let add 3 vertices
    am.resize(am.size() + 3);
    for (unsigned int i = 0; i < am.size(); i++) {
        am[i].resize(am[i].size() + 3);
    }

    // You get to fix that....
    // No problem!
    print(am);
    return 0;
}
