#ifndef BUDGET_H
#define BUDGET_H

typedef struct {
    int budgetId;
    char category[50];
    double allocatedAmount;
} Budget;

void addBudget(void);
void listBudgets(void);
void saveBudgetsText(void);
void loadBudgetsText(void);

#endif