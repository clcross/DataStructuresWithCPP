#ifndef GRAPHAM_H
#define GRAPHAM_H

#include <limits.h>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
/* This class represents a weighted directed graph via an adjacency matrix.
 * Vertices are given an index, starting from 0 and ascending
 * Class W : W represent the weight that can be associated with an edge.
 * We will not weight the vertices.
 */

template<class W>
class GraphAM {
    private:
        std::vector<std::vector<int> > am;
    public:
        /* Initialize an empty graph. */
        GraphAM();

        /* Initialize the Graph with a fixed number of vertices. */
        GraphAM(const int vertices);

        /* Deconstructor shall free up memory */
        ~GraphAM();

        /* Adds amt vertices to the graph. */
        int addVertices(int amt);

        /* Removes a vertex. 
         * return whether successful or not
         */
        bool removeVertex(int idx);

        /* Adds an edge with weight W to the graph. */
        bool addEdge(const int start, const int end, const W &weight);

        void fill(int size) {
            for (int i = 0; i < size; i++) {
                am[i].resize(size);
                for (int j = 0; j < size; j++) {
                    am[i][j] = INT_MAX;
                }
                am[i][i] = 0;
            }
        };

        bool commonChecks(const int start, const int end) {
            if (start >= 0 && start < am.size() && end >= 0 && end < am[start].size()) {
                return true;
            }
            return false;
        };

        int minD(int dist[], bool sptSet[]) { 
            int min = INT_MAX, min_index; 
        
            for (int v = 0; v < am.size(); v++) {
                if (sptSet[v] == false && dist[v] <= min) {
                    min = dist[v], min_index = v; 
                }
            }
            return min_index; 
        };

        int printSolution(int dist[]) { 
            printf("Vertex \t\t Distance from Source\n"); 
            for (int i = 0; i < am.size(); i++) 
                printf("%d \t\t %d\n", i, dist[i]); 
        };

        /* 
         * Remove edge from graph.
         */
        bool removeEdge(const int start, const int end);

        void depthFirstTraversal(void (*visit)(const int node), std::set<int> &visited, int vertex);

        void depthFirstTraversal(void (*visit)(const int node));
        void breadthFirstTraversal(void (*visit)(const int node));

        /*
         * Return adjacent weight from start to end (or -1 if they are
         * not adjacent.
         */
        W adjacent(const int start, const int end);

        /* Run Dijkstra's Shortest Path to find the shortest path from start
         * to end and returning that smallest weight.
         * return -1 if a path does not exist!
         */
        W dijkstraShortestPath(const int start, const int end);

        /* Print out the Graph */
        void print() const;

};

#include "grapham.cpp"

#endif
