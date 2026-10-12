#include <stdio.h>
#include <string.h>

int main(void)
{
    char name[100], email[100], phone[30], town[50];

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

    return 0;
}
