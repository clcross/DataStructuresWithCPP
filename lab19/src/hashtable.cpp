#ifdef HASH_TABLE_H

template<class K, class V>
HashTable<K, V>::HashTable(const int size, const float loadFactor) {
    hashTable.resize(size);
    load = loadFactor;
    mSize = 0;
}

template<class K, class V>
bool HashTable<K, V>::insert(const K &key, const V &val) {
    int index = hashcode(key);
    int modAfter = index % hashTable.size();

    // Now find an open spot
    while (!hashTable[modAfter].empty) {
        modAfter++;
        modAfter = modAfter % hashTable.size();
    }

    // modAfter is the open spot so set the value there.
    hashTable[modAfter].setKey(key);
    hashTable[modAfter].setValue(val);
    mSize++;
    hashTable[modAfter].empty = false;
    
    if (percentFull() > load) {
        // hashTable.resize(hashTable.size() * 2);
        //Rehash everything, you do it.
        reHash();
    }
    
    return true;
}

template<class K, class V>
void HashTable<K, V>::reHash() {
    std::vector<HashNode<K, V> > temp;
    temp = hashTable;

    hashTable.clear();

    hashTable.resize(temp.size() * 2);

    for (int i = 0; i < temp.size(); i++) {
        if (!temp[i].empty){
            // insert(temp[i].getKey(), temp[i].getValue());
            int index = hashcode(temp[i].getKey());
            int modAfter = index % hashTable.size();

            while (!hashTable[modAfter].empty) {
                modAfter++;
                modAfter = modAfter % hashTable.size();
            }

            hashTable[modAfter].setKey(temp[i].getKey());
            hashTable[modAfter].setValue(temp[i].getValue());
            hashTable[modAfter].empty = false;
        }
    }
    temp.clear();
}

template<class K, class V>
void HashTable<K, V>::print() const {
    for (int i = 0; i < hashTable.size(); i++) {
        std::cout << "[" << i << "]:";
        std::cout << hashTable[i].getKey() << " -> " << hashTable[i].getValue() << " ,";
        std::cout << "\n";
    }
}

template<class K, class V>
bool HashTable<K, V>::remove(const K &key) {
    int index = hashcode(key);
    int modAfter = index % hashTable.size();

    while(!hashTable[modAfter].empty){
        if (hashTable[modAfter].getKey() == key) {
            hashTable[modAfter] = HashNode<K, V>(0, 0);
            hashTable[modAfter].dirty = true;
            mSize--;
            return true;
        }
        modAfter++;
        modAfter = modAfter % hashTable.size();
    }
    return false;
}

template<class K, class V>
V& HashTable<K,V>::operator[](const K &key) {
    int index = hashcode(key);
    int modAfter = index % hashTable.size();
    //check for dirtiness
    while(!hashTable[modAfter].empty){
        if (hashTable[modAfter].getKey() == key) {
            return hashTable[modAfter].getValueRef();
        }
        modAfter++;
        modAfter = modAfter % hashTable.size();
    }

    return def;
}

template<class K, class V>
float HashTable<K, V>::percentFull() {
    return (float)mSize / (float)hashTable.size();
}

template<class K, class V>
HashTable<K, V>::~HashTable() {
    std::vector<HashNode<K, V> >().swap(hashTable);
}

int hashcode(int key) {
    return key;
}

int hashcode(const std::string &key) {
    // You need to do something else.
    return 0;
}

#endif
