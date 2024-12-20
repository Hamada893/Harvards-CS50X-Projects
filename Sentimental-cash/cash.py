from cs50 import get_float


def calculate_coins(cents):
    coins = 0
    while cents != 0:
        while cents >= 25:
            coins += 1
            cents -= 25

        while cents >= 10 and cents < 25:
            coins += 1
            cents -= 10

        while cents >= 5 and cents < 10:
            coins += 1
            cents -= 5

        while cents >= 1 and cents < 5:
            coins += 1
            cents -= 1

    return coins


def main():
    cents = 0
    # Prompt user until a positive value is entered
    while cents <= 0:
        cents = get_float("Change owed: ")
        cents = round(cents * 100)

    coins = calculate_coins(cents)
    print(coins)


if __name__ == "__main__":
    main()
