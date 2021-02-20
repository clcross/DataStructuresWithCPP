#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <functional>

void vector_fun1() {
    int array[] = {5, 15, 19, 32, 6};
    std::vector<int> vec(array, array + 5);
    for (unsigned int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << ", ";
    }
    std::cout << "\n";
    vec.pop_back();
    for (unsigned int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << ", ";
    }
    std::cout << "\n";
    vec.push_back(27);
    for (unsigned int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << ", ";
    }
    std::cout << "\n";
}

void vector_fun2() {
    int array[] = {5, 15, 19, 32, 6};
    std::vector<int> vec(array, array + 5);
    while (!vec.empty()) {
        std::cout << vec.back() << ", ";
        vec.pop_back();
    }
    std::cout << "\n";
}

void vector_fun3() {
    int array[] = {5, 15, 19, 32, 6};
    std::vector<int> vec(array, array + 5);
    for (std::vector<int>::iterator i = vec.begin(); i != vec.end(); i++) {
        std::cout << *i << ", ";
    }
    std::cout << "\n";
    for (std::vector<int>::iterator i = vec.end()-1; i != vec.begin() - 1; i--) {
        std::cout << *i << ", ";
    }
    std::cout << "\n";
}

void show(int n) {
    std::cout << n << ",";
}

void vector_fun4() {
    int array[] = {5, 15, 19, 32, 6};
    std::vector<int> vec(array, array + 5);
    for_each(vec.begin(), vec.end(), show);
    std::cout << "\n";
}

void vector_fun5() {
    int array[] = {5, 15, 19, 32, 6};
    std::vector<int> vec(array, array + 5);
    std::vector<int>::iterator pos = find(vec.begin(), vec.end(), 19);
    if (pos == vec.end()) {
        std::cout << "NOT FOUND!\n";
    } else {
        std::cout << "FOUND!";
    }
}

bool in_range(int val) {
    return val > 10 && val < 16;
}

void vector_fun6() {
    int array[] = {5, 15, 19, 32, 6};
    std::vector<int> vec(array, array + 5);
    std::vector<int>::iterator pos = find_if(vec.begin(), vec.end(), in_range);
    if (pos == vec.end()) {
        std::cout << "NOT FOUND!\n";
    } else {
        std::cout << "FOUND!";
    }
}

class squared_sum {
    public:
        int operator() (int sum, int val) {
            return sum + (sum * val);
        }
};

// First call: 1, 5
// Second call: 6, 15
// Third call: 
void vector_fun7() {
    int array[] = {5, 15, 19, 32, 6};
    std::vector<int> vec(array, array + 5);
    int amt = accumulate(vec.begin(), vec.end(), 1, squared_sum());
    std::cout << "amt = " << amt << "\n";
}

void set_fun1() {
    std::string array[] = {"Batman", "Superman", "Mario", "Superwoman", "Supermario", "Toad"};
    std::set<std::string, std::less<std::string>> name_set(array, array + 6);
    name_set.insert("Superbatman");
    //std::set<std::string, std::less<std::string>>::iterator iter = name_set.find("Superwoman");
    auto iter = name_set.find("Superwoman");
    std::cout << ((iter != name_set.end()) ? "" : "NOT ") << "FOUND\n";
}

void map_fun1() {
    std::string names[] = {"Batman", "Superman", "Mario", "Superwoman", "Supermario", "Toad"};
    int power_level[] = {  9001,      5,          2000000, 9002,         2000000000,  1};
    std::map<std::string, int> power_map;
    for (int i = 0; i < 6; i++) {
        power_map[names[i]] = power_level[i];
    }
    for (auto iter = power_map.begin(); iter != power_map.end(); iter++) {
        std::cout << (*iter).first << " = " << (*iter).second << "\n";
    }
    std::cout << power_map["Superman"] << "\n";
}

int main(int argc, char *argv[]) {
    //vector_fun1();
    //vector_fun2();
    //vector_fun3();
    //vector_fun4();
    //vector_fun5();
    //vector_fun6();
    //vector_fun7();
    //set_fun1();
    map_fun1();
    return 0;
}
