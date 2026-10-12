#include <stdio.h>

float calculateSalary(float basic, float housing, float transport);

int main(void)
{
    float basic, housing, transport, grossSalary;

    printf("Basic salary: ");
    if (scanf("%f", &basic) != 1) return 1;

    printf("Housing allowance: ");
    if (scanf("%f", &housing) != 1) return 1;

    printf("Transport allowance: ");
    if (scanf("%f", &transport) != 1) return 1;

    grossSalary = calculateSalary(basic, housing, transport);
    printf("Gross salary: %.2f\n", grossSalary);

    return 0;
}

float calculateSalary(float basic, float housing, float transport)
{
    return basic + housing + transport;
}
