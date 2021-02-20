#ifdef GRAPHAM_H

#include <iostream>
#include <queue>
#include <algorithm>

template<class W>
GraphAM<W>::GraphAM() {
    am.resize(0);
}

template<class W>
GraphAM<W>::GraphAM(const int vertices) {
    am.resize(vertices);
    fill(vertices);
}

template<class W>
int GraphAM<W>::addVertices(int amt) {
    int rows = am.size();
	int columns = am[0].size();
	am.resize(rows + amt);

	for (int i = 0; i < rows + amt; i++) {
		am[i].resize(columns + amt);
	}

	for (int i = rows; i < am.size(); i++) {
		for (int j = 0; j < am[i].size(); j++) {
			am[i][j] = INT_MAX;
		}
		am[i][i] = 0;
	}
    
	for (int i = 0; i < am.size(); i++) {
		for (int j = columns; j < am[i].size(); j++) {
			am[i][j] = INT_MAX;
		}
		am[i][i] = 0;
	}
	return rows;
}

template<class W>
bool GraphAM<W>::removeVertex(int idx) {
    if (am.size() == 0) {
		return false;
	}
	if (idx < 0 || idx >= am.size()) {
		return false;
	}

    for (int i = idx; i < am.size() - 1; i++) {
		for (int j = 0; j < am.size() - 1; j++) {
			am[i][j] = am[i + 1][j + 1];
		}
		am[i][i] = am[i+1][i+1];
	}
	
	am.resize(am.size() - 1);
	for (int i = 0; i < am.size(); i++) {
		am[i].resize(am[i].size() - 1);
	}
	return true;
}

template<class W>
bool GraphAM<W>::addEdge(const int start, const int end, const W &weight) {
    if (am.size() == 0) {
		return false;
	}
	if (start == end) {
		return false;
	}
    if (commonChecks(start, end)) {
		if (am[start][end] != INT_MAX) {
			return false;	
		}
		am[start][end] = weight;
		return true;
	}
    
    return false;
}

template<class W>
bool GraphAM<W>::removeEdge(const int start, const int end) {
    if (am.size() == 0 || start == end || am[start][end] == INT_MAX) {
		return false;
	}
	
	if (commonChecks(start, end)) {
		am[start][end] = INT_MAX;
		return true;
	}

	return false;
}

template<class W>
W GraphAM<W>::adjacent(const int start, const int end) {
    if (commonChecks(start, end)) {
		if (am[start][end] != INT_MAX) {
			return am[start][end];
		}
	}
	return -1;
}

template<class W>
void GraphAM<W>::depthFirstTraversal(void (*visit)(const int node), std::set<int> &visited, int vertex) {
    if (visited.find(vertex) != visited.end()) {
        return;
    }
    visited.insert(vertex);
    (*visit)(vertex);
    for (unsigned i = 0; i < am[vertex].size(); i++) {
        if (am[vertex][i] > 0 && am[vertex][i] < INT_MAX) {
            depthFirstTraversal(visit, am, visited, i);
        }
    }
}

template<class W>
void GraphAM<W>::depthFirstTraversal(void (*visit)(const int node)) {
    std::set<int> visited;
    for (unsigned int i = 0; i < am.size(); i++) {
        depthFirstTraversal(visit, am, visited, i);
    }
}

// got this from lab 23
template<class W>
void GraphAM<W>::breadthFirstTraversal(void (*visit)(const int node)) {
    std::queue<int> to_visit;
    std::set<int> visited;

    for (int i = 0; i < am.size(); i++) {
        to_visit.push(i);
        while(!to_visit.empty()) {
            int vertex = to_visit.front();
            to_visit.pop();

            visit(vertex);
            visited.insert(vertex);

            for(int i = 0; i != am[vertex].size(); i++) {
                to_visit.push(i);
            }
        }
    }
}

// not exactly sure if this is right got it from combining lab 23 stuff 
template<class W>
W GraphAM<W>::dijkstraShortestPath(const int start, const int end) {
	std::set<int> visited;
	std::pair<W, int> tempPair;
    std::vector<std::pair<W, int> > to_visit;
	
	tempPair.first = 0;
	tempPair.second = start;
	to_visit.push_back(tempPair);

	while (!to_visit.empty()) {
		std::pair<W, int> rover = to_visit.front();
		int tempVert = rover.second;
		to_visit.erase(to_visit.begin());
        
		if (am[tempVert][end] > 0 && am[tempVert][end] != INT_MAX) {
			return (rover.first + am[tempVert][end]);
		}
        else {
            visited.insert(tempVert);
            for (int i = 0; i < am[tempVert].size(); i++) {
                if (am[tempVert][i] > 0 && am[tempVert][i] != INT_MAX) {
                    tempPair.first = am[tempVert][i] + rover.first;
                    tempPair.second = i;
                    to_visit.push_back(tempPair);
                }
            }
        }
	}
    return -1;
}

template<class W>
void GraphAM<W>::print() const {
    for (unsigned int i = 0; i < am.size(); i++) {
        for (unsigned int j = 0; j < am[i].size(); j++) {
            if (am[i][j] == INT_MAX) {
                std::cout << "I ";
            } else {
                std::cout << am[i][j] << " ";
            }
        }
        std::cout << "\n";
    }
}

template<class W>
GraphAM<W>::~GraphAM() {
    std::vector<std::vector<int> >().swap(am);
}

#endif
