#include <string>
#include <iostream>

class Robot {
    public:
        Robot(const std::string sound);
        void make_sound();
        Robot operator +(const Robot &robot);
        friend std::ostream& operator <<(std::ostream& cout, const Robot &r) {
            cout << r.mSound;
            return cout;
        }
    private:
        std::string mName;
        std::string mSound;

};
