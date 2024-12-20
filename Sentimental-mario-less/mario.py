from cs50 import get_int

height, row, space, column = 0, 0, 0, 0

while True:
    height = get_int("Enter height here: ")
    if height >= 1 and height <= 8:
        break

for row in range(height):
    # Print spaces
    for space in range(height - row - 1):
        print(" ", end="")
    # Print hashes
    for column in range(row + 1):
        print("#", end="")

    print()
