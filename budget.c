#include <stdio.h>
#include "budget.h"
#include "utilities.h"

#define MAX_BUDGETS 100
static Budget budgetList[MAX_BUDGETS];
static int budgetCount = 0;

void addBudget(void) {
    if (budgetCount >= MAX_BUDGETS) {
        printf("Budget list is full!\n");
        return;
    }
    budgetList[budgetCount].budgetId = readInt("Enter Budget ID: ");
    printf("Enter Budget Category: ");
    scanf("%49s", budgetList[budgetCount].category);
    budgetList[budgetCount].allocatedAmount = readDouble("Enter Allocated Amount: ");
    budgetCount++;
    printf("Budget added successfully.\n");
}

void listBudgets(void) {
    printf("\n--- Budget Records ---\n");
    if (budgetCount == 0) {
        printf("No budget records found.\n");
        return;
    }
    for (int i = 0; i < budgetCount; i++) {
        printf("ID: %d | Category: %s | Amount: %.2f\n", budgetList[i].budgetId, budgetList[i].category, budgetList[i].allocatedAmount);
    }
}

void saveBudgetsText(void) {
    FILE *fp = fopen("data/budgets.txt", "w");
    if (fp == NULL) {
        perror("data/budgets.txt");
        return;
    }
    for (int i = 0; i < budgetCount; i++) {
        fprintf(fp, "%d|%s|%.2f\n", budgetList[i].budgetId, budgetList[i].category, budgetList[i].allocatedAmount);
    }
    fclose(fp);
    printf("Successfully saved %d budget records.\n", budgetCount);
}

void loadBudgetsText(void) {
    FILE *fp = fopen("data/budgets.txt", "r");
    if (fp == NULL) {
        perror("data/budgets.txt");
        return;
    }
    budgetCount = 0;
    while (fscanf(fp, "%d|%49[^|]|%lf\n", &budgetList[budgetCount].budgetId, budgetList[budgetCount].category, &budgetList[budgetCount].allocatedAmount) == 3) {
        budgetCount++;
        if (budgetCount >= MAX_BUDGETS) break;
    }
    fclose(fp);
    printf("Successfully loaded %d budget records.\n", budgetCount);
}