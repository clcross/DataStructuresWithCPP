#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "map.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    Map map;
    // int ret;
    map.add("john", 1234);
    map.add("paul", 912);
    map.add("cam", 11111);
    map.add("amber", 568);
    map.add("dave", 9012);
    map.add("burb", 55390);
    map.add("andrew", 564738);
    map.add("zach", 999);
    map.add("ram", 2836);
    map.add("cameron", 109274);
    map.add("ramsey", 663927);
    map.add("cam cross", 5678);
    // map.add("cam cam", 5678);
    // map.add("cam bam", 5678);
    // map.add("cam ram", 5678);
    // map.add("cam dam", 5678);
    // map.add("cam ko", 5678);
    
    
    // std::cout << map.size() << "\n";
    map.print();
    // map.remove("dave");
    // // map.sort();
    // // map.print();
    // map.add("amber", 1111);
    // map.get("cam", ret);
    // std::cout << ret << "\n";
    // map.print();
    // std::cout << "howMany: " << map.howMany("cam") << "\n";
    // // map.~Map();


    // FILE *fnames = fopen("firstnames.txt", "r");
    // FILE *lnames = fopen("lastnames.txt", "r");
    // std::vector<std::string> first;
    // std::vector<std::string> last;
    // char line[1024];

    // while(fgets(line, 1024, fnames) != NULL) {
    //     line[strlen(line)-1] = '\0';
    //     first.push_back(line);
    // }

    // printf("\n");

    // while(fgets(line, 1024, lnames) != NULL) {
    //     line[strlen(line)-1] = '\0';
    //     line[strlen(line)-1] = '\0';
    //     last.push_back(line);
    // }

    // fclose(fnames);
    // fclose(lnames);


    // printf("Number of first names:%ld\n", first.size());
    // printf("Number of last names:%ld\n", last.size());
    // for (int i = 0; i < 1000; i++) {
    //     for (int j = 0; j < 1000; j+= 50) {
    //         // sprintf(line, "%s %s", first[i].c_str(), last[j].c_str());
    //         map.add(first[j].c_str(), (i*last.size() + j +1));
    //         std::cout << j << " " << first[j] << "\n";
    //         // printf("%s %ld\n", line, i*last.size() + j +1);
    //     }
    // }
    // map.print();
    // std::cout << map.size() << "\n";
}

