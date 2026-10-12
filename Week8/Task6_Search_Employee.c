#include <stdio.h>

int searchEmployee(int id, int ids[], int size);

int main(void)
{
    int employeeIDs[] = {101, 102, 103, 104, 105};
    int id;
    int position;
    int size = (int)(sizeof(employeeIDs) / sizeof(employeeIDs[0]));

    printf("Enter employee ID: ");
    if (scanf("%d", &id) != 1)
    {
        printf("Invalid employee ID.\n");
        return 1;
    }

    position = searchEmployee(id, employeeIDs, size);

    if (position != -1)
        printf("Employee found at position %d.\n", position);
    else
        printf("Employee not found.\n");

    return 0;
}

/* Returns the zero-based array index, or -1 if the ID is absent. */
int searchEmployee(int id, int ids[], int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        if (ids[i] == id)
            return i;
    }

    return -1;
}
