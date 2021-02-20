#include "robot.hpp"

Robot::Robot(const std::string sound) {
    mSound = sound;
}

void Robot::make_sound() {
    std::cout << mSound << "\n";
}

Robot Robot::operator +(const Robot &robot) {
    Robot ret(mSound + robot.mSound);
    return ret;
}
