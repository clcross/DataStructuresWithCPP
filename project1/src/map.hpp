#ifndef MAP_H
#define MAP_H
#include <vector>

class person{
    public:
        int mVal;
        const char *mName;

        void set_val(int val){
            mVal = val;
        }

        void set_name(const char *name){
            mName = name;
        }
};

class Map{
    public:
        Map();
        /* Adds (inserts) val with the associated key.
         * Returns if successful or not.  (It is not successful if we are out of
         * memory, or if the key already exists.)
         */
        bool add(const char *key, int val);

        void print();

        void sort();
    
        /* Searches for the key.  If found it sets ret to the correct val and
         * returns true.  Otherwise this function returns false.
         */
        bool get(const char *key, int &ret);

        int bSearch(std::vector<person> vec, int begin, int end, const char *key);
    
        /* Returns the size (memory consumed) by this data structure. */
        int size();
    
        /* Removes the current value from the Map AND frees up any memory that
         * it can.
         * Returns true if there was something to remove, false otherwise.
         */
        bool remove(const char *key);
    
        /* Returns the number of names with a given prefix.
        * EX: If we have {John, Jonathan, Paul, Mark, Luke, Joanna} then
        * howMany("Jo") == 3
        */
        int howMany(const char *prefix);
    
        /* Frees all memory */
        ~Map();
    private:
        std::vector<person> mMap;
        // std::vector<std::pair<const char*, int> > mMap;
};

#endif
