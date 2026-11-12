#include "../include/menu.h"
#include "../include/color.h"
#include "../include/position.h"
#include <iostream>

using namespace std;

const string reset = "\033[0m";

void menu(string menuOptions[], int row, int currentIndex, string color) {
    for (int i = 0; i < row; i++) {
        setPosition(10, 5 + i);
        if (i == currentIndex) {
            setColor(color);
            cout << "-> " << menuOptions[i] << reset << endl;
        } else {
            setColor(reset);
            cout << "   " << menuOptions[i] << endl;
        }
    }
    setColor(reset);
}