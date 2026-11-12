#include "../include/position.h"
#include <iostream>

void setPosition(int x, int y) {
    std::cout << "\033[" << y << ";" << x << "H";
}