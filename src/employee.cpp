#include "../include/employee.h"
#include "../include/arrowInput.h"
#include <iostream>

using namespace std;

void allocatFun(int &size, Employee **ptr) {
    *ptr = new Employee[size];
    
    cout << " Enter Initial Employee Data (" << size << " records) ===" << endl;
    for (int i = 0; i < size; i++) {
        cout << "\nEmployee " << i + 1 << ":" << endl;
        cout << "Name: ";
        cin >> (*ptr)[i].name;
        cout << "Age: ";
        cin >> (*ptr)[i].age;
        cout << "ID: ";
        cin >> (*ptr)[i].id;
    }
    
    cout << "\nDo you want to double the size and add more employees? (y/n): ";
    char answer;
    cin >> answer;

    if (answer == 'y' || answer == 'Y') {
        int oldSize = size;
        int newSize = size * 2;
        
        Employee *temp = new Employee[newSize];
        
        for (int i = 0; i < oldSize; i++) {
            temp[i] = (*ptr)[i];
        }
        
        delete[] *ptr;
        *ptr = temp;
        size = newSize; 

        system("clear");
        cout << "=== Enter Data for New Slots (" << oldSize << " to " << size << ") ===" << endl;
        for (int i = oldSize; i < size; i++) {
            cout << "\nEmployee " << i + 1 << ":" << endl;
            cout << "Name: ";
            cin >> (*ptr)[i].name;
            cout << "Age: ";
            cin >> (*ptr)[i].age;
            cout << "ID: ";
            cin >> (*ptr)[i].id;
        }

        cout << "\nAll records updated! Press 'q' to return to the menu.";
    } else {
        cout << "\nSaved! Press 'q' to return to the menu.";
    }
    
    while (true) {
        if (getch_linux() == 'q') break;
    }
}

void displayEmployees(Employee *ptr, int size) {
    system("clear");
    cout << "=== Employee Records ===" << endl;
    if (ptr == nullptr || size == 0) {
        cout << "No records found!" << endl;
    } else {
        for (int i = 0; i < size; i++) {
            cout << "Record " << i + 1 << " -> Name: " << ptr[i].name 
                 << ", Age: " << ptr[i].age 
                 << ", ID: " << ptr[i].id << endl;
        }
    }
    cout << "\nPress 'q' to return to the menu.";
    while (true) {
        if (getch_linux() == 'q') break;
    }
}