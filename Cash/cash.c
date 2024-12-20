
#include <cs50.h>
#include <stdio.h>

int calculate_coins(int cents);
int main(void)
{
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents <= 0);
    int coins = calculate_coins(cents);
    printf("coins: %i\n", coins);
}
int calculate_coins(int cents)
{
    int coins = 0;
    while (cents != 0)
    {
        while (cents >= 25)
        {
            coins++;
            cents = cents - 25;
        }

        while (cents >= 10 && cents < 25)
        {
            coins++;
            cents = cents - 10;
        }

        while (cents >= 5 && cents < 10)
        {
            coins++;
            cents = cents - 5;
        }

        while (cents >= 1 && cents < 5)
        {
            coins++;
            cents = cents - 1;
        }
    }
    return coins;
}
