#include <stdio.h>

float calculateBudget(float revenue, float expenses);

int main(void)
{
    float revenue, expenses, balance;

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

    return 0;
}

float calculateBudget(float revenue, float expenses)
{
    return revenue - expenses;
}
