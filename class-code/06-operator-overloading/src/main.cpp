#include <iostream>
#include "robot.hpp"

int main(int argc, char *argv[]) {
    Robot r("Bun dun be dum!");
    Robot r2d2("AHHHHHHHHHHHH");
    Robot r3 = r + r2d2;
    r3.make_sound();
    r.make_sound();
    r2d2.make_sound();
    (r + r2d2).make_sound();

    std::cout << r2d2 << "\n";
    return 0;
}

