#ifdef GRAPHAL_H

template<class W>
GraphAL<W>::GraphAL() {
    aGraph.resize(0);
}

template<class W>
GraphAL<W>::GraphAL(const int vertices) {
    aGraph.resize(vertices);
}

/* Adds an edge with weight W to the graph. */
template<class W>
bool GraphAL<W>::addEdge(const int start, const int end, const W &weight) {
    if (commonChecks(start, end)) {
        if (aGraph.size() == 0) {
            return false;
        }
        if (start < 0 || end >= aGraph.size()) {
            return false;
        }
        if(aGraph.size() > end) {
            std::pair<W, int> to_add(weight, end);
            aGraph[start].push_front(to_add);
            aGraph[start].sort(compareFunc);
        }
        //aGraph[start].push_front(std::pair<W, int>(weight, end));
        return true;
    }
    return false;
}

template<class W>
bool GraphAL<W>::removeEdge(const int start, const int end) {
    if (commonChecks(start, end)) {    
        if (aGraph.size() == 0) {
            return false;
        }
        if (start < 0 || end >= aGraph.size()) {
            return false;
        }
        for(auto i = aGraph[start].begin(); i != aGraph[start].end(); i++) {
            if (i->second == end) {
                aGraph[start].erase(i);
                return true;
            }
        }
    }
    return false;
}

/* Adds amt vertices to the graph. */
template<class W>
void GraphAL<W>::addVertices(int amt) {
	aGraph.resize(aGraph.size() + amt);

	// for (int i = 0; i < aGraph.size(); i++) {
	// 	aGraph[i].resize(aGraph[i].size());
	// }
}

template<class W>
W GraphAL<W>::adjacent(const int start, const int end) {
    if (commonChecks(start, end)) {
        if (start == end) {
            return 0;
        }

        for(auto i = aGraph[start].begin(); i != aGraph[start].end(); i++) {
            if ( i->second == end) {
                return i->first;
            }
        }
    }
    return -1;
}

template<class W>
void GraphAL<W>::breadthFirstTraversal(void (*visit)(const int node)) {
    std::queue<int> to_visit;
    std::set<int> visited;

    // Make sure we visit each node starting at 0.
    for (int i = 0; i < aGraph.size(); i++) {

        // Breadth first search
        to_visit.push(i);
        while(!to_visit.empty()) {
            int vertex = to_visit.front();
            to_visit.pop();

            // if we have already visited, then continue the loop
            if (visited.find(vertex) != visited.end()) {
                continue;
            }

            (*visit)(vertex);
            visited.insert(vertex);

            for(auto i = aGraph[vertex].begin(); i != aGraph[vertex].end(); i++) {
                to_visit.push(i->second);
            }
        }
        
    }
}

template<class W>
void GraphAL<W>::depthFirstTraversal(void (*visit)(const int node), std::set<int> &visited, int vertex) {
    if (visited.find(vertex) == visited.end()) {
        visit(vertex);
        visited.insert(vertex);
        for (auto i = aGraph[vertex].begin(); i != aGraph[vertex].end(); i++) {
            depthFirstTraversal(visit, visited, i->second);
        }
    }
}

template<class W>
void GraphAL<W>::depthFirstTraversal(void (*visit)(const int node)) {
    std::set<int> visited;
    if (aGraph.size() <= 0) {
        return;
    }
    for (unsigned int i = 0; i < aGraph.size(); i++) {
        depthFirstTraversal(visit, visited, i);
    }
}

/* Removes a vertex. 
 * return wheter sucessful or not
 */
template<class W>
bool GraphAL<W>::removeVertex(int idx) {
    if (aGraph.size() == 0) {
		return false;
	}
	if (idx < 0 || idx >= aGraph.size()) {
		return false;
	}

    for(int i = 0; i < aGraph.size(); i++) {
        for(auto j = aGraph[i].begin(); j != aGraph[i].end(); j++) {
            if(j->second == idx) {
                removeEdge(i, idx);
            }
            if(j->second > idx) {
                j->second = j->second - 1;
            }
        }
    }
    for(int i = idx; i < aGraph.size() - 1; i++) {
        aGraph[i] = aGraph[i + 1];
    }
    aGraph.pop_back();
	
	// aGraph.resize(aGraph.size() - 1);
	// for (int i = 0; i < aGraph.size(); i++) {
	// 	aGraph[i].resize(aGraph[i].size() - 1);
	// }
	return true;
}

template <class W>
void GraphAL<W>::print() {
    for(auto i = 0; i < aGraph.size(); i++) {
        std::cout << i << "-->";
        for(auto j = aGraph[i].begin(); j != aGraph[i].end(); j++) {
            if (!aGraph[i].empty()) {
                std::cout << "(" << j->first << ", " << j->second << ") ";
            }
        }
        std::cout << "\n";
    }
}

/* Returns the TOTAL weight of the minimum spanning tree with the
* given starting node.
* You must use Prim’s MST.
*/
template <class W>
W GraphAL<W>::prims(const int start) {
}

template<class W>
GraphAL<W>::~GraphAL() {
    std::vector<std::list<std::pair<W, int> > >().swap(aGraph);
}

#endif
