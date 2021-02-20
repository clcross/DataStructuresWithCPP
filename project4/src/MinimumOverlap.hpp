#ifndef MinimumOverlap_HPP
#define MinimumOverlap_HPP

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <set>
#include <queue>
#include <iterator>

class Student{
    private:
        int sID;
    public:
        std::vector<std::vector<int> > groupsUsed;
        void set_ID(int id) {sID = id;}
        int get_ID() {return sID;}
        // void add_vec(const std::vector<int> &rover) {groupsUsed.push_back(rover);}
        // std::vector<int> get_vecRow(int index) {return groupsUsed[index];}
        // std::vector<int> get_vecColumn(int index) {return groupsUsed[index];}
};
class MinimumOverlap {
    private:
        std::vector<std::vector<int> > setVector;
        std::vector<std::vector<int> > Used;
        std::vector<Student> studentVec;
        std::vector<int> common;
        int coverSize;
    public:
        // Passes in a string pointing to the set/group file.
        // Make sure you store all the sets/groups!
        MinimumOverlap(const std::string &setFile);

        // Returns the minimum number of overlaps possible given a cover.
        // If print is true, it prints the set(s).
        unsigned int findMinimumOverlap(const std::vector<int> &cover, const bool &print);

        unsigned int findMinimumOverlap(const std::vector<Student> &REMAIN, std::vector<int> &TOTAL, const std::vector<int> &INPUT, std::vector<std::vector<int> > SOFAR, const bool &print);

        void printSet();

        void printStu();

        bool Compare(std::vector<std::vector<int> > b, std::vector<int> c) {
            if (b.size() == 0) {
                return false;
            }
            bool match = false;
            for (int i = 0; i < b.size(); i++) {
                if (b[i] == c) {
                    match = true;
                }
            }
            return match;
        };

        std::vector<int> Subtract(const std::vector<int> &INPUT, const std::vector<int> S) {
            std::vector<int> temp = INPUT;
            if (INPUT.size() == 0) {
                return temp;
            }
            for (int i = 0; i < S.size(); i++){
                std::vector<int>::iterator it = temp.begin();
                while (it != temp.end()) {
                    if (*it == S[i]) {
                        it = temp.erase(it);
                    }
                    else {
                        ++it;
                    }
                }
            }
            return temp;
        };

        std::vector<int> Add(std::vector<int> &TOTAL, std::vector<int> S) {
            std::vector<int> temp = TOTAL;
            temp.insert(temp.end(), S.begin(), S.end());
            return temp;
        };

        ~MinimumOverlap();
};

#endif
