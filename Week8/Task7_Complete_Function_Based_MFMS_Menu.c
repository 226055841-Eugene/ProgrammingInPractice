#include <stdio.h>

float calculateVAT(float amount);
float calculateSalary(float basic, float housing, float transport);
float calculateBudget(float revenue, float expenses);
void displayMenu(void);
int searchEmployee(int id, int ids[], int size);

int main(void)
{
    int choice;
    int employeeIDs[] = {101, 102, 103, 104, 105};
    int id, position;
    int size = (int)(sizeof(employeeIDs) / sizeof(employeeIDs[0]));
    float amount, vat;
    float basic, housing, transport, salary;
    float revenue, expenses, balance;

    do
    {
        displayMenu();

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Please restart and enter a number.\n");
            return 1;
        }

        switch (choice)
        {
            case 1:
                printf("Enter amount: ");
                if (scanf("%f", &amount) != 1 || amount < 0)
                {
                    printf("Invalid amount.\n");
                    return 1;
                }
                vat = calculateVAT(amount);
                printf("VAT: %.2f\n", vat);
                break;

            case 2:
                printf("Basic salary: ");
                if (scanf("%f", &basic) != 1) return 1;
                printf("Housing allowance: ");
                if (scanf("%f", &housing) != 1) return 1;
                printf("Transport allowance: ");
                if (scanf("%f", &transport) != 1) return 1;

                salary = calculateSalary(basic, housing, transport);
                printf("Gross salary: %.2f\n", salary);
                break;

            case 3:
                printf("Enter revenue: ");
                if (scanf("%f", &revenue) != 1) return 1;
                printf("Enter expenses: ");
                if (scanf("%f", &expenses) != 1) return 1;

                balance = calculateBudget(revenue, expenses);
                printf("Budget balance: %.2f\n", balance);

                if (balance > 0)
                    printf("SURPLUS\n");
                else if (balance < 0)
                    printf("DEFICIT\n");
                else
                    printf("BALANCED\n");
                break;

            case 4:
                printf("Enter employee ID: ");
                if (scanf("%d", &id) != 1) return 1;

                position = searchEmployee(id, employeeIDs, size);
                if (position != -1)
                    printf("Employee found at position %d.\n", position);
                else
                    printf("Employee not found.\n");
                break;

            case 5:
                printf("Supplier Management is covered in Week 7 Lab Task 6.\n");
                printf("Run Week7_Task6_Supplier_Management_Menu.c to use it.\n");
                break;

            case 6:
                printf("Goodbye.\n");
                break;

            default:
                printf("Invalid choice. Choose from 1 to 6.\n");
        }

        printf("\n");
    } while (choice != 6);

    return 0;
}

void displayMenu(void)
{
    printf("============================================\n");
    printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("============================================\n");
    printf("1. Calculate VAT\n");
    printf("2. Calculate Salary\n");
    printf("3. Calculate Budget\n");
    printf("4. Search Employee\n");
    printf("5. Supplier Management\n");
    printf("6. Exit\n");
    printf("Enter choice: ");
}

float calculateVAT(float amount)
{
    return amount * 0.15f;
}

float calculateSalary(float basic, float housing, float transport)
{
    return basic + housing + transport;
}

float calculateBudget(float revenue, float expenses)
{
    return revenue - expenses;
}

/* Returns the zero-based array index, or -1 if the ID is absent. */
int searchEmployee(int id, int ids[], int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        if (ids[i] == id)
            return i;
    }

    return -1;
}
