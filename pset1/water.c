#include <stdio.h>
#include <cs50.h>
int main(void)
{
    printf("Minutes: ");
    int x = get_int();
    int y = 12;
    printf("Bottles: %i \n", x * y);
}
