#include <stdio.h>

void displayMenu(void);

int main(void)
{
    displayMenu();
    return 0;
}

void displayMenu(void)
{
    printf("==================================\n");
    printf(" MUNICIPAL FINANCIAL MANAGEMENT\n");
    printf("==================================\n");
    printf("1. Calculate VAT\n");
    printf("2. Calculate Salary\n");
    printf("3. Calculate Budget\n");
    printf("4. Exit\n");
    printf("Enter choice: ");
}
