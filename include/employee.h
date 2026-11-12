#ifndef EMPLOYEE_H
#define EMPLOYEE_H

struct Employee {
    char name[15];
    int age;
    int id;
};

void allocatFun(int &size, Employee **ptr);
void displayEmployees(Employee *ptr, int size);

#endif