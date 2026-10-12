#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "reports.h"

int main(void) {
    int choice;
    printf("Municipal Financial Management System (MFMS)\n");

    do {
        printf("\n=============================\n");
        printf("       MFMS MAIN MENU        \n");
        printf("=============================\n");
        printf("1. Add Employee\n");
        printf("2. List Employees\n");
        printf("3. Add Budget\n");
        printf("4. List Budgets\n");
        printf("5. Add Supplier\n");
        printf("6. List Suppliers\n");
        printf("7. Add Asset\n");
        printf("8. List Assets\n");
        printf("9. Save All Data (Text & Binary)\n");
        printf("10. Load All Data (Text & Binary)\n");
        printf("11. Generate Reports\n");
        printf("12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: listEmployees(); break;
            case 3: addBudget(); break;
            case 4: listBudgets(); break;
            case 5: addSupplier(); break;
            case 6: listSuppliers(); break;
            case 7: addAsset(); break;
            case 8: listAssets(); break;
            case 9:
                saveEmployeesText();
                saveEmployeesBinary();
                saveBudgetsText();
                saveSuppliersText();
                saveAssetsText();
                printf("All records saved successfully.\n");
                break;
            case 10:
                loadEmployeesText();
                loadEmployeesBinary();
                loadBudgetsText();
                loadSuppliersText();
                loadAssetsText();
                printf("All records loaded successfully.\n");
                break;
            case 11:
                employeeReport();
                budgetReport();
                break;
            case 12:
                printf("Exiting application. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 12);

    return 0;
}