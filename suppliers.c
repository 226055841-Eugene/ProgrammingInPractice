#include <stdio.h>
#include "suppliers.h"
#include "utilities.h"

#define MAX_SUPPLIERS 100
static Supplier supplierList[MAX_SUPPLIERS];
static int supplierCount = 0;

void addSupplier(void) {
    if (supplierCount >= MAX_SUPPLIERS) {
        printf("Supplier list full!\n");
        return;
    }
    supplierList[supplierCount].supplierId = readInt("Enter Supplier ID: ");
    printf("Enter Supplier Name: ");
    scanf("%49s", supplierList[supplierCount].supplierName);
    supplierCount++;
    printf("Supplier added successfully.\n");
}

void listSuppliers(void) {
    printf("\n--- Supplier Records ---\n");
    if (supplierCount == 0) {
        printf("No suppliers found.\n");
        return;
    }
    for (int i = 0; i < supplierCount; i++) {
        printf("ID: %d | Name: %s\n", supplierList[i].supplierId, supplierList[i].supplierName);
    }
}

void saveSuppliersText(void) {
    FILE *fp = fopen("data/suppliers.txt", "w");
    if (fp == NULL) { perror("data/suppliers.txt"); return; }
    for (int i = 0; i < supplierCount; i++) {
        fprintf(fp, "%d|%s\n", supplierList[i].supplierId, supplierList[i].supplierName);
    }
    fclose(fp);
}

void loadSuppliersText(void) {
    FILE *fp = fopen("data/suppliers.txt", "r");
    if (fp == NULL) { perror("data/suppliers.txt"); return; }
    supplierCount = 0;
    while (fscanf(fp, "%d|%49s\n", &supplierList[supplierCount].supplierId, supplierList[supplierCount].supplierName) == 2) {
        supplierCount++;
    }
    fclose(fp);
}