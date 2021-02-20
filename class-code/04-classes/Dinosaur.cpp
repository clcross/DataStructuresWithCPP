#include <iostream>

class Dinosaur {
    public:
        Dinosaur() {
            amt_ran = 0;
            name = NULL;
        }
        Dinosaur(const std::string _name) {
            amt_ran = 0;
            set_name(_name);
        }
        void speak() {
            std::cout << "RAWR!\n";
        }
        void run(const int amt) {
            amt_ran += amt;
            std::cout << *name << " ran a total of " << amt_ran << ".\n";
        }
        void set_name(const std::string _name) {
            name = new std::string(_name);
        }
        ~Dinosaur() {
            if (name != NULL) {
                delete name;
            }
            name = NULL;
        }
    private:
        int amt_ran;
        std::string *name;
};

int main(int argc, char *argv[]) {
    Dinosaur dinos[20];
    Dinosaur *dino = new Dinosaur("T-Rex");
    //dino->set_name("T-Rex");
    dino->run(1024);

    delete dino;
    return 0;
}
