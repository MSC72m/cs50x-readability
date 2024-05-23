#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
int main(void)
{

    string input = get_string("Text: ");

    int text_len = strlen(input);
    int letters = 0;
    int words = 0;
    int sentences = 0;

    for (int i = 0; i < text_len; i++)
    {
        char c = input[i];
        if (isalpha(c) != 0)
        {
            letters++;
        }

        if (c == ' ')
        {
            words++;
        }

        if (c == '.' || c == '!' || c == '?')
        {
            sentences++;
        }
    }
    words++;

    float L = ((float) letters / (float) words) * 100;
    float s = ((float) sentences / (float) words) * 100;
    float subindex = 0.0588 * L - 0.296 * s - 15.8;
    int index = round(subindex);
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
