#include <iostream>

// In your header file
void print(int);
void print_neg(int);
void print_sq(int);
// End of header file

void print(int val) {
    std::cout << val << "\n";
}

void print_neg(int val) {
    std::cout << -val << "\n";
}

void print_sq(int val) {
    std::cout << (val * val) << "\n";
}

void run_function(void (*func) (int), int val) {
    // func is a pointer to a function!
    (*func)(val);
}

int main(int argc, char *argv[]) {
    run_function(&print, 5);
    run_function(&print_neg, 5);
    run_function(&print_sq, 5);
    return 0;
}
