#ifdef HASH_TABLE_H
#define HASH_TABLE_H
#include <iostream>

template<class K, class V>
HashTable<K, V>::HashTable(const int size) {
    hashTable.resize(size);
}

template<class K, class V>
HashTable<K, V>::~HashTable() {
    std::vector<std::list<HashNode<K, V> > >().swap(hashTable);
}

template<class K, class V>
bool HashTable<K, V>::insert(const K &key, const V &val) {
    int index = hashcode(key);
    int modAfter = index % hashTable.size();
    HashNode<K, V> node(key, val);
    hashTable[modAfter].push_back(node);
    return true;
}

template<class K, class V>
V& HashTable<K, V>::operator[](const K &key) {
    // std::list<HashNode<K, V>>
    auto bucket = hashTable[(hashcode(key) % hashTable.size())];
    for(auto i = bucket.begin(); i != bucket.end(); i++){
        if(key == (*i).getKey()){
            return (*i).getValueRef();
        }
    }
    return def;
}

template<class K, class V>
void HashTable<K, V>::print() const {
    int index = 0;
    for (auto i = hashTable.begin(); i != hashTable.end(); i++) {
        std::cout << "[" << index << "]:";
        for (auto j = (*i).begin(); j != (*i).end(); j++) {
            std::cout << (*j).getKey() << " -> " << (*j).getValue() << " ,";
        }
        std::cout << "\n";
        index++;
    }
}

template<class K, class V>
bool HashTable<K, V>::remove(const K &key) {
    int index = hashcode(key);
    int modAfter = index % hashTable.size();
    for (auto i = hashTable[modAfter].begin(); i != hashTable[modAfter].end(); i++) {
        // std::cout << i->getKey() << "\n";
        if (i->getKey() == key) {
            // i can only get it to erase the entire entry
            // i dont know how to only access the values
            hashTable[modAfter].erase(i);
            return true;
        }
    }
    return false;
}

// whats the point of this
int hashcode(int key) {
    return key;
}

// what else to do
int hashcode(const std::string &key) {
    // You need to do something else.
    return 0;
}

#endif
