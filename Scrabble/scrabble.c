#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int Calculate_score(string word);
int POINTS[] = {1, 3, 3, 2, 1, 4, 2,  4, 1, 8, // A-J
                5, 1, 3, 1, 1, 3, 10, 1, 1, 1, // K-T
                1, 4, 4, 8, 4, 10};

int main(void)
{
    string word1 = get_string("Player_1: ");
    string word2 = get_string("Player_2: ");

    int score_1 = Calculate_score(word1);
    int score_2 = Calculate_score(word2);
    // print winner

    if (score_1 > score_2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score_1 < score_2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// strlen removes the null character and len processes each character individually
// characters are then calculated by removing A (if isupper which is uppercase letters)
// or removing a (islower which is lowercase letters)
int Calculate_score(string word)
{
    int score = 0;
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        if (isupper(word[i]))
        {
            score += POINTS[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            score += POINTS[word[i] - 'a'];
        }
    }
    return score;
}
