#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    string text = get_string("Text: ");

    int letter_count = 0;
    int word_count = 0;
    int sentence_count = 0;

    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {

        if (isalpha(text[i]))

        {
            letter_count++;
        }

        if (text[i] == ' ')

        {
            word_count++;
        }

        if (text[i] == '.' || text[i] == '!' || text[i] == '?')

        {
            sentence_count++;
        }
    }
    word_count += 1;

    float L = ((float) letter_count / word_count) * 100;
    float S = ((float) sentence_count / word_count) * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;

    int grade_level = round(index);

    if (grade_level < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (grade_level > 16)
    {
        printf("Grade 16+\n");
    }

    else
    {
        printf("Grade %i\n", grade_level);
    }
}
