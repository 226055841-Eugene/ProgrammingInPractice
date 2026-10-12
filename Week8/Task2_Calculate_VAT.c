#include <stdio.h>

float calculateVAT(float amount);

int main(void)
{
    float amount, vat;

    printf("Enter amount: ");
    if (scanf("%f", &amount) != 1 || amount < 0)
    {
        printf("Please enter a valid non-negative amount.\n");
        return 1;
    }

    vat = calculateVAT(amount);
    printf("VAT: %.2f\n", vat);

    return 0;
}

float calculateVAT(float amount)
{
    return amount * 0.15f; /* VAT rate is 15%, as specified in the lab. */
}
