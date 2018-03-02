#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int coinsgiven = 0;

    printf("O hai! How much change is owed? \n");
    float change = GetFloat();
    // ensure we get a non-negative amount
    while (change < 0) {
        printf("O hai! How much change is owed? \n");
        change = GetFloat();
    }


    int amount =  round(change * 100);

    while (amount > 0) {
        if ((amount - 25) >= 0)
        {
            amount = amount - 25; coinsgiven++;

        }
        else if ((amount - 10) >= 0)
        {
            amount = amount - 10; coinsgiven++;

        }
        else if ((amount - 5) >= 0)
        {
            amount = amount - 5; coinsgiven++;
            }
        else if ((amount - 1) >= 0)
        {
            amount = amount - 1; coinsgiven++;
        }
    }

    printf("%d\n", coinsgiven);
}
