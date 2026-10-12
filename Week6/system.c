#include <stdio.h>
#include <string.h>

#define SALARY_COUNT 50
#define BUDGET_COUNT 10
#define REG_COUNT 20

// Function prototypes
void manageSalaries();
void manageBudgets();
void manageRegistrations();

int main() {
    int choice;
    do {
        printf("\n=====================================\n");
        printf(" Municipal Information Management System\n");
        printf("=====================================\n");
        printf("1. Employee Salaries\n");
        printf("2. Department Budgets\n");
        printf("3. Vehicle Registrations\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: manageSalaries(); break;
            case 2: manageBudgets(); break;
            case 3: manageRegistrations(); break;
            case 0: printf("Exiting program...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 0);

    return 0;
}

// A. Employee Salaries
void manageSalaries() {
    float salaries[SALARY_COUNT];
    float sum = 0, avg, max, min;
    int i;
    float search;

    printf("\n--- Capture 50 Salaries ---\n");
    for(i = 0; i < SALARY_COUNT; i++) {
        printf("Enter salary %d: ", i+1);
        scanf("%f", &salaries[i]);
    }

    printf("\nAll Salaries:\n");
    for(i = 0; i < SALARY_COUNT; i++) {
        printf("%.2f ", salaries[i]);
        sum += salaries[i];
    }
    printf("\n");

    avg = sum / SALARY_COUNT;
    max = salaries[0];
    min = salaries[0];
    for(i = 1; i < SALARY_COUNT; i++) {
        if(salaries[i] > max) max = salaries[i];
        if(salaries[i] < min) min = salaries[i];
    }

    printf("Average Salary: %.2f\n", avg);
    printf("Highest Salary: %.2f\n", max);
    printf("Lowest Salary: %.2f\n", min);

    printf("Enter salary to search: ");
    scanf("%f", &search);
    int found = 0;
    for(i = 0; i < SALARY_COUNT; i++) {
        if(salaries[i] == search) {
            printf("Salary %.2f found at position %d\n", search, i+1);
            found = 1;
            break;
        }
    }
    if(!found) printf("Salary %.2f not found.\n", search);
}

// B. Department Budgets
void manageBudgets() {
    float budgets[BUDGET_COUNT];
    float sum = 0, avg;
    int i, j;
    float temp;

    printf("\n--- Capture 10 Department Budgets ---\n");
    for(i = 0; i < BUDGET_COUNT; i++) {
        printf("Enter budget %d: ", i+1);
        scanf("%f", &budgets[i]);
    }

    printf("\nAll Budgets:\n");
    for(i = 0; i < BUDGET_COUNT; i++) {
        printf("%.2f ", budgets[i]);
        sum += budgets[i];
    }
    printf("\n");

    avg = sum / BUDGET_COUNT;
    printf("Total Budget: %.2f\n", sum);
    printf("Average Budget: %.2f\n", avg);

    // Sort budgets (Bubble Sort)
    for(i = 0; i < BUDGET_COUNT-1; i++) {
        for(j = 0; j < BUDGET_COUNT-i-1; j++) {
            if(budgets[j] > budgets[j+1]) {
                temp = budgets[j];
                budgets[j] = budgets[j+1];
                budgets[j+1] = temp;
            }
        }
    }

    printf("Budgets sorted (lowest to highest):\n");
    for(i = 0; i < BUDGET_COUNT; i++) {
        printf("%.2f ", budgets[i]);
    }
    printf("\n");
}

// C. Vehicle Registrations
void manageRegistrations() {
    char registrations[REG_COUNT][20];
    char search[20];
    int i;

    printf("\n--- Capture 20 Vehicle Registrations ---\n");
    for(i = 0; i < REG_COUNT; i++) {
        printf("Enter registration %d: ", i+1);
        scanf("%19s", registrations[i]);
    }

    printf("\nAll Registrations:\n");
    for(i = 0; i < REG_COUNT; i++) {
        printf("%s ", registrations[i]);
    }
    printf("\n");

    printf("Enter registration to search: ");
    scanf("%19s", search);

    int found = 0;
    for(i = 0; i < REG_COUNT; i++) {
        if(strcmp(registrations[i], search) == 0) {
            printf("Registration %s found at position %d\n", search, i+1);
            found = 1;
            break;
        }
    }
    if(!found) printf("Registration %s not found.\n", search);
}
