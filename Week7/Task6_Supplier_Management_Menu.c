#include <stdio.h>
#include <string.h>

int main(void)
{
    char name[100] = "";
    char email[100] = "";
    char phone[30] = "";
    char town[50] = "";
    char searchName[100];
    int hasSupplier = 0;
    int choice;

    do
    {
        printf("\n================================\n");
        printf(" MUNICIPAL FINANCIAL MANAGEMENT\n");
        printf("================================\n");
        printf("1. Add Supplier\n");
        printf("2. Display Supplier\n");
        printf("3. Search Supplier\n");
        printf("4. Show Name Length\n");
        printf("5. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Please enter a number.\n");
            return 1;
        }
        getchar(); /* Remove the newline left by scanf(). */

        switch (choice)
        {
            case 1:
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

                hasSupplier = 1;
                printf("Supplier added successfully.\n");
                break;

            case 2:
                if (hasSupplier)
                {
                    printf("\n--- SUPPLIER DETAILS ---\n");
                    printf("Name : %s\n", name);
                    printf("Email: %s\n", email);
                    printf("Phone: %s\n", phone);
                    printf("Town : %s\n", town);
                }
                else
                {
                    printf("Please add a supplier first.\n");
                }
                break;

            case 3:
                if (hasSupplier)
                {
                    printf("Enter supplier name to search: ");
                    fgets(searchName, sizeof(searchName), stdin);
                    searchName[strcspn(searchName, "\n")] = '\0';

                    if (strcmp(searchName, name) == 0)
                        printf("Supplier found.\n");
                    else
                        printf("Supplier not found.\n");
                }
                else
                {
                    printf("Please add a supplier first.\n");
                }
                break;

            case 4:
                if (hasSupplier)
                    printf("Supplier name length: %zu\n", strlen(name));
                else
                    printf("Please add a supplier first.\n");
                break;

            case 5:
                printf("Goodbye.\n");
                break;

            default:
                printf("Invalid choice. Choose from 1 to 5.\n");
        }
    } while (choice != 5);

    return 0;
}
