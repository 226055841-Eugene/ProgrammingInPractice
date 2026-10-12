#include <stdio.h>
#include <string.h>

int main(void)
{
    char original[100];
    char backup[100];

    printf("Enter supplier name: ");
    fgets(original, sizeof(original), stdin);
    original[strcspn(original, "\n")] = '\0';

    strcpy(backup, original);

    printf("\nOriginal supplier name: %s\n", original);
    printf("Copied supplier name:   %s\n", backup);

    return 0;
}
