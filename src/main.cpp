#include "../include/employee.h"
#include "../include/menu.h"
#include "../include/color.h"
#include "../include/arrowInput.h"
#include <iostream>
#include <string>

using namespace std;

const string green = "\033[32m";

int main() {
    const int optionNum = 3;
    string menuOptions[optionNum] = {"New", "Display", "Exit"};
    int currentOption = 0;

    Employee *employees = nullptr;
    int employeeSize = 0;
    bool dataInitialized = false;

    while (true) {

        menu(menuOptions, optionNum, currentOption, green);

        char byte1 = getch_linux();
        if (byte1 == '\033') {
            char byte2 = getch_linux(); 
            char byte3 = getch_linux(); 

            switch (byte3) {
                case 'A': 
                    currentOption = (currentOption - 1 + optionNum) % optionNum;
                    break;
                case 'B': 
                    currentOption = (currentOption + 1) % optionNum;
                    break;
                case 'H': 
                    currentOption = 0;
                    break;
                case 'F': 
                    currentOption = optionNum - 1;
                    break;
            }
        } else if (byte1 == '\n' || byte1 == '\r') { 
            if (currentOption == 0) { 
                system("clear");
                cout << "How many employees do you need to enter? ";
                cin >> employeeSize;
                allocatFun(employeeSize, &employees);
                dataInitialized = true;
            } else if (currentOption == 1) { 
                if (!dataInitialized) {
                    system("clear");
                    cout << "Please add employees first using 'New' option!\n";
                    cout << "Press 'q' to return.";
                    while (getch_linux() != 'q');
                } else {
                    displayEmployees(employees, employeeSize);
                }
            } else if (currentOption == 2) { 
                system("clear");
                cout << "Exiting program. Goodbye!\n";
                break;
            }
        }
    }

    delete[] employees;
    return 0;
}