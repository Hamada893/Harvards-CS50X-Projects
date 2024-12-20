from cs50 import get_string


def main():
    text = get_string("Text: ")

    letter_count, word_count, sentence_count = 0, 0, 0

    length = len(text)
    for i in range(length):
        if text[i].isalpha():
            letter_count += 1

        if text[i] == ' ':
            word_count += 1

        if text[i] in ('.', '!', '?'):
            sentence_count += 1

    # Count the last word
    word_count += 1

    L = (letter_count / word_count) * 100
    S = (sentence_count / word_count) * 100

    index = 0.0588 * L - 0.296 * S - 15.8

    grade_level = round(index)

    if grade_level < 1:
        print("Before Grade 1")
    elif grade_level > 16:
        print("Grade 16+")
    else:
        print(f"Grade {grade_level}")


if __name__ == "__main__":
    main()
