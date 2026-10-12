#ifndef SUPPLIERS_H
#define SUPPLIERS_H

typedef struct {
    int supplierId;
    char supplierName[50];
} Supplier;

void addSupplier(void);
void listSuppliers(void);
void saveSuppliersText(void);
void loadSuppliersText(void);

#endif