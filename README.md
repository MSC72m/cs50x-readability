# Readability

## Project Description
This project is a solution to a CS50x problem set that involves calculating the readability grade level of a given text using the Coleman-Liau index. The program prompts the user for a text input and then analyzes the text to determine the reading grade level.

## Table of Contents
- [Installation](#installation)
- [Usage](#usage)
- [Code Explanation](#code-explanation)

## Installation
No special installation is required for this project. 

## Usage
To compile and run the project, use the following commands:

make readability
./readability
You will be prompted to enter a text input, and the program will output the readability grade level.

## Code Explanation
Main Function
``` C
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string input = get_string("Text: ");
```

#include <cs50.h>, #include <ctype.h>, #include <math.h>, #include <stdio.h>, and #include <string.h> include the necessary libraries for CS50 functions, character type functions, mathematical functions, standard input/output functions, and string handling functions respectively.
int main(void) is the entry point of the program where the execution starts.
string input = get_string("Text: "); prompts the user for a text input and stores it in the input variable.
Variable Initialization

``` C
    int text_len = strlen(input);
    int letters = 0;
    int words = 0;
    int sentences = 0;
```
int text_len = strlen(input); calculates the length of the input text.
int letters = 0;, int words = 0;, and int sentences = 0; initialize counters for letters, words, and sentences respectively.
Counting Letters, Words, and Sentences

``` C

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
```

The for loop iterates over each character in the input text.
char c = input[i]; retrieves the current character.
if (isalpha(c) != 0) checks if the character is an alphabetic letter and increments the letters counter if true.
if (c == ' ') checks if the character is a space and increments the words counter if true.
if (c == '.' || c == '!' || c == '?') checks if the character is a period, exclamation mark, or question mark and increments the sentences counter if true.
words++; increments the words counter to account for the last word in the text.
Calculating the Readability Index

``` C
    float L = ((float) letters / (float) words) * 100;
    float s = ((float) sentences / (float) words) * 100;
    float subindex = 0.0588 * L - 0.296 * s - 15.8;
    int index = round(subindex);
float L = ((float) letters / (float) words) * 100; // calculates the average number of letters per 100 words.
float s = ((float) sentences / (float) words) * 100; // calculates the average number of sentences per 100 words.
float subindex = 0.0588 * L - 0.296 * s - 15.8; // calculates the Coleman-Liau index using the formula.
int index = round(subindex); // rounds the index to the nearest whole number.
```
Outputting the Grade Level

``` C
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
```
if (index > 16) checks if the index is greater than 16 and prints "Grade 16+" if true.
else if (index < 1) checks if the index is less than 1 and prints "Before Grade 1" if true.
else prints the grade level as "Grade %i\n" for indices between 1 and 16.
