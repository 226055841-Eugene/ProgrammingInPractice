#include <stdio.h>
#include <string.h>
#include "employees.h"
#include "utilities.h"

#define MAX_EMPLOYEES 100
static Employee empList[MAX_EMPLOYEES];
static int empCount = 0;

void addEmployee(void) {
    if (empCount >= MAX_EMPLOYEES) {
        printf("Employee database is full!\n");
        return;
    }
    empList[empCount].id = readInt("Enter Employee ID: ");
    printf("Enter Employee Name: ");
    scanf("%49s", empList[empCount].name);
    empList[empCount].salary = readDouble("Enter Employee Salary: ");
    empCount++;
    printf("Employee added successfully.\n");
}

void listEmployees(void) {
    printf("\n--- Employee Records ---\n");
    if (empCount == 0) {
        printf("No employee records found.\n");
        return;
    }
    for (int i = 0; i < empCount; i++) {
        printf("ID: %d | Name: %s | Salary: %.2f\n", empList[i].id, empList[i].name, empList[i].salary);
    }
}

void saveEmployeesText(void) {
    FILE *fp = fopen("data/employees.txt", "w");
    if (fp == NULL) {
        perror("data/employees.txt");
        return;
    }
    for (int i = 0; i < empCount; i++) {
        fprintf(fp, "%d|%s|%.2f\n", empList[i].id, empList[i].name, empList[i].salary);
    }
    fclose(fp);
    printf("Successfully saved %d employees to text file.\n", empCount);
}

void loadEmployeesText(void) {
    FILE *fp = fopen("data/employees.txt", "r");
    if (fp == NULL) {
        perror("data/employees.txt (File may not exist yet)");
        return;
    }
    empCount = 0;
    while (fscanf(fp, "%d|%49[^|]|%lf\n", &empList[empCount].id, empList[empCount].name, &empList[empCount].salary) == 3) {
        empCount++;
        if (empCount >= MAX_EMPLOYEES) break;
    }
    fclose(fp);
    printf("Successfully loaded %d employees from text file.\n", empCount);
}

void saveEmployeesBinary(void) {
    FILE *fp = fopen("data/employees.dat", "wb");
    if (fp == NULL) {
        perror("data/employees.dat");
        return;
    }
    fwrite(&empCount, sizeof(int), 1, fp);
    fwrite(empList, sizeof(Employee), empCount, fp);
    fclose(fp);
    printf("Successfully saved %d employees to binary file.\n", empCount);
}

void loadEmployeesBinary(void) {
    FILE *fp = fopen("data/employees.dat", "rb");
    if (fp == NULL) {
        perror("data/employees.dat (File may not exist yet)");
        return;
    }
    fread(&empCount, sizeof(int), 1, fp);
    fread(empList, sizeof(Employee), empCount, fp);
    fclose(fp);
    printf("Successfully loaded %d employees from binary file.\n", empCount);
}