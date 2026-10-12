#include <stdio.h>
#include <string.h>

int main(void)
{
    char name[100], email[100], phone[30], town[50];
    char copiedName[100], searchName[100];

    printf("Enter supplier name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Enter email: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';

    printf("Enter phone: ");
    fgets(phone, sizeof(phone), stdin);
    phone[strcspn(phone, "\n")] = '\0';

    printf("Enter town: ");
    fgets(town, sizeof(town), stdin);
    town[strcspn(town, "\n")] = '\0';

    printf("\n--- SUPPLIER DETAILS ---\n");
    printf("Name : %s\n", name);
    printf("Email: %s\n", email);
    printf("Phone: %s\n", phone);
    printf("Town : %s\n", town);

    printf("\nSupplier name length: %zu\n", strlen(name));

    strcpy(copiedName, name);
    printf("Copied supplier name: %s\n", copiedName);

    printf("\nEnter supplier name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    if (strcmp(searchName, name) == 0)
        printf("Supplier found.\n");
    else
        printf("Supplier not found.\n");

    return 0;
}
