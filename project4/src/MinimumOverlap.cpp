#include "MinimumOverlap.hpp"

MinimumOverlap::MinimumOverlap(const std::string &setFile) {
    // std::cout << "setFile: " << setFile << "\n";
    std::ifstream fileIn;
    fileIn.open(setFile);
    int groupCount = 0;
    int member, maxID = -1;
    std::vector<int> tempVec;
    
    if (fileIn.is_open()){
        while (!fileIn.eof()){
            fileIn>>member;
            if (member > maxID) {
                maxID = member;
            }

            tempVec.push_back(member);

            if (fileIn.get() == '\n'){
                setVector.push_back(tempVec);
                tempVec.clear();
            }
        }      
        fileIn.close(); 
    }

    // sort the vectors by length

    studentVec.resize(maxID + 1);
    std::cout << "\n";
    // int studCount = 0;
    for (int i = 0; i <= maxID; i++) {
        studentVec[i].set_ID(i);
        for (int j = 0; j < setVector.size(); j++) {
            for (int k = 0; k < setVector[j].size(); k++) {
                if (setVector[j][k] == i) {
                    studentVec[i].groupsUsed.push_back(setVector[j]);
                }
            }
        }
    }

    // printStu();
}

void MinimumOverlap::printSet() {
    std::cout << "vector: \n";
    for (int i = 0; i < setVector.size(); i++) {
        for (int j = 0; j < setVector[i].size(); j++) {
            std::cout << "{" << setVector[i][j] << "}, ";
        }
        std::cout << "\n";
    }
}

void MinimumOverlap::printStu() {
    for (int i = 0; i < studentVec.size(); i++){
        std::cout << "\ngroups for student " << studentVec[i].get_ID() << ": ";
        for (int k = 0; k < studentVec[i].groupsUsed.size(); k++){
            std::cout << "{";
            for (int j = 0; j < studentVec[i].groupsUsed[k].size(); j++){
                std::cout << studentVec[i].groupsUsed[k][j] << ", ";
                // std::cout << "groups: " << studentVec[i].get_ID() << ", ";
            }
            std::cout << "}, ";
        }
    }
    std::cout << "\n";
}

unsigned int MinimumOverlap::findMinimumOverlap(const std::vector<int> &cover, const bool &print) {
    unsigned int min = UINT_MAX;

    unsigned int cmin = UINT_MAX;

    if (cover.empty() || cover.size() == 0){
        return min;
    }

    std::cout << "\n";

    coverSize = cover.size();

    // Attempt to make the algorithim faster by makeing it look for smaller groups

    std::vector<int> newCover = cover;
    
    int n = 2;

	// determine number of sub-vectors of size n
	int size = (newCover.size() - 1) / n + 1;

	// create array of vectors to store the sub-vectors
	std::vector<int> vec[size];

	// each iteration of this loop process next set of n elements
	// and store it in a vector at k'th index in vec
	for (int k = 0; k < size; ++k)
	{
		// get range for next set of n elements
		auto start_itr = std::next(newCover.cbegin(), k*n);
		auto end_itr = std::next(newCover.cbegin(), k*n + n);

		// allocate memory for the sub-vector
		vec[k].resize(n);

		// code to handle the last sub-vector as it might
		// contain less elements
		if (k*n + n > newCover.size()) {
			end_itr = newCover.cend();
			vec[k].resize(newCover.size() - k*n);
		}

		// copy elements from the input range to the sub-vector
		std::copy(start_itr, end_itr, vec[k].begin());
	}

	// print the sub-vectors
	for (int i = 0; i < size; i++) {
        coverSize = vec[i].size();
        // std::cout << "\n";
        findMinimumOverlap(studentVec, common, vec[i], Used, print);
        // min += findMinimumOverlap(studentVec, common, vec[i], print);
        
        // std::cout << "min at: " << i << " is: " << min << "\n";
	}

    for (int i = 0; i < Used.size(); i++) {
        min += Used[i].size();
        // std::cout << "min at: " << i << " is: " << min << "\n";
    }

    // min = findMinimumOverlap(studentVec, common, cover, print);
    
    common.clear();
    Used.clear();
    return min;
}

unsigned int MinimumOverlap::findMinimumOverlap(const std::vector<Student> &REMAIN, std::vector<int> &TOTAL, const std::vector<int> &INPUT, std::vector<std::vector<int> > SOFAR, const bool &print) {
    unsigned int min = UINT_MAX;

    for (int i = 0; i < INPUT.size(); i++) {
       for (int j = 0; j < REMAIN[INPUT[i]].groupsUsed.size(); j++) {
           if (min <= Add(TOTAL, REMAIN[INPUT[i]].groupsUsed[j]).size()) {
               continue;
            }
            std::vector<int> RESULT = Subtract(INPUT, REMAIN[INPUT[i]].groupsUsed[j]);
            std::vector<Student> newRemains = REMAIN;
            newRemains[INPUT[i]].groupsUsed.erase(newRemains[INPUT[i]].groupsUsed.begin() + j);
            if (RESULT.size() == 0) {
                // std::cout << "found: " << min << "\n";
                if (Add(TOTAL, REMAIN[INPUT[i]].groupsUsed[j]).size() < min) {
                    if (!Compare(SOFAR, REMAIN[INPUT[i]].groupsUsed[j])) {
                        SOFAR.push_back(REMAIN[INPUT[i]].groupsUsed[j]);
                    }
                    min = Add(TOTAL, REMAIN[INPUT[i]].groupsUsed[j]).size();
                    if (min == coverSize) {
                        return min;
                    }
                    // std::cout << "min: " << min << "\n";
                }
            }
            else {
                // std::cout << "else: " << RESULT[0] << "\n";
                TOTAL.insert(TOTAL.end(), REMAIN[INPUT[i]].groupsUsed[j].begin(), REMAIN[INPUT[i]].groupsUsed[j].end());
                // std::cout << "TOTAL: " << TOTAL.size() << "\n";
                int cmin = findMinimumOverlap(newRemains, TOTAL, RESULT, SOFAR, print);
                if (cmin < min) {
                    if (!Compare(SOFAR, REMAIN[INPUT[i]].groupsUsed[j])) {
                        SOFAR.push_back(REMAIN[INPUT[i]].groupsUsed[j]);
                    }
                    min = cmin;
                    if (min == coverSize) {
                        return min;
                    }
                    // std::cout << "after: " << min << "\n";
                }
                // TOTAL.pop_back();
                TOTAL.erase(TOTAL.end() - REMAIN[INPUT[i]].groupsUsed[j].size(), TOTAL.end());
            }
        }
    }
    // std::cout << "hello\n";
    for (int i = 0; i < SOFAR.size(); i++) {
        // std::cout << SOFAR[i].size() << "\n";
        if (!Compare(Used, SOFAR[i])) {
            // std::cout << SOFAR[i].size() << "\n";
            for (int j = 0; j < SOFAR[i].size(); j++) {
                std::cout << SOFAR[i][j] << ", ";
            }
            std::cout << "\n";
            Used.push_back(SOFAR[i]);
        }
    }

    if (!rePro) {
        min = findMinimumOverlap(Used, TOTAL, RESULT, SOFAR, print);
    }

    return min;
}

MinimumOverlap::~MinimumOverlap() {
    std::vector<std::vector<int> >().swap(setVector);
    std::vector<Student>().swap(studentVec);
    std::vector<int>().swap(common);
}
