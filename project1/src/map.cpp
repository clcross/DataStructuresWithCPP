#include "map.hpp"
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <string.h>

Map::Map() {
    std::vector<person> mMap;
}

/* Adds (inserts) val with the associated key.
* Returns if successful or not.  (It is not successful if we are out of
* memory, or if the key already exists.)
*/
bool Map::add(const char *key, int val) {
    this->sort();
    if(this->get(key, val) == false){
        person* rover = new person;
        rover->set_name(key);
        rover->set_val(val);
        mMap.push_back(*rover);
        delete rover;
        return true;
    }
    else{
        return false;
    }
}

void Map::print(){
    for (int i = 0; i < mMap.size(); i++){
        std::cout << "(" << mMap.at(i).mName << ", " << mMap.at(i).mVal << ")\n";
    }
    std::cout << "\n";
}

/* Searches for the key.  If found it sets ret to the correct val and
* returns true.  Otherwise this function returns false.
*/
bool Map::get(const char *key, int &ret) {
    int pos = bSearch(mMap, 0, mMap.size()-1, key);
    if (pos == -1){
        return false;
    }
    else{
        ret = mMap.at(pos).mVal;
        return true;
    }
}

void Map::sort() {
    int mSize = mMap.size();
    for (int i = 0; i < mSize; i++){
        for (int j = 0; j < mSize - 1; j++){
            if (strcmp(mMap.at(j).mName, mMap.at(j+1).mName) > 0){
                person temp = mMap.at(j);
                mMap.at(j) = mMap.at(j+1);
                mMap.at(j+1) = temp;
            }
        }
    }
}

int Map::bSearch(std::vector<person> vec, int begin, int end, const char *key){
    // this->sort();
    if(begin > end){
        return -1;
    }

    const int middle = begin + ((end - begin) / 2);

    if(strcmp(vec[middle].mName, key) == 0){
        return middle;
    }
    else if(strcmp(vec[middle].mName, key) > 0){
        return bSearch(vec, begin, middle - 1, key);
    }
    else{
        return bSearch(vec, middle + 1, end, key);
    }
}

/* Returns the size (memory consumed) by this data structure. */
int Map::size() {
    return mMap.capacity();
}

/* Removes the current value from the Map AND frees up any memory that
* it can.
* Returns true if there was something to remove, false otherwise.
*/
bool Map::remove(const char *key) {
    // this->sort();
    int pos = this->bSearch(mMap, 0, mMap.size()-1, key);
    if(pos == -1){
        return false;   
    }
    else{
        mMap.erase(mMap.begin()+pos);
        return true;
    }
}

/* Returns the number of names with a given prefix.
* EX: If we have {John, Jonathan, Paul, Mark, Luke, Joanna} then
* howMany("Jo") == 3
*/
int Map::howMany(const char *prefix) {
    this->sort();
    int match = 0;
    for(int i = 0; i < mMap.size()-1; i++){
        const char* pch = strstr(mMap.at(i).mName, prefix);
        if(pch != NULL){
            match++;
        }
        else if(match != 0 && pch == NULL){
            return match;
        }
    }
    return match;
}

/* Frees all memory */
Map::~Map() {
    // mMap.clear();
    std::vector<person>().swap(mMap);
    // std::cout << "empty? " << mMap.capacity() << "\n";
}
