#include <stdio.h>
#include <string.h>

int main(void)
{
    char searchName[100];

    const char supplier1[] = "ABC Office Supplies";
    const char supplier2[] = "Namibia Stationery";

    printf("Enter supplier name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    if (strcmp(searchName, supplier1) == 0 ||
        strcmp(searchName, supplier2) == 0)
    {
        printf("Supplier found.\n");
    }
    else
    {
        printf("Supplier not found.\n");
    }

    return 0;
}
