#ifndef EMPLOYEES_H
#define EMPLOYEES_H

typedef struct {
    int id;
    char name[50];
    double salary;
} Employee;

void addEmployee(void);
void listEmployees(void);
void saveEmployeesText(void);
void loadEmployeesText(void);
void saveEmployeesBinary(void);
void loadEmployeesBinary(void);

#endif