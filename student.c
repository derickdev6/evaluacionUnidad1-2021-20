#include <stdlib.h>
#include <string.h>
#include "student.h"
#include <stdint.h>

// Declaring functions
void reverse(char *, int, int);

void feature1(FILE *fin, FILE *fout);
void feature2(FILE *fin, FILE *fout);

void feature1(FILE *fin, FILE *fout)
{
    // Feature 1 Read first inputFile line and write into outputFile
    // Basic for reading lines
    char buffer[70];
    char *status = NULL;

    status = fgets(buffer, sizeof(buffer), fin);
    if (status != NULL)
    {
        printf("%s", buffer);
        fputs(buffer, fout);
    }
}

void feature2(FILE *fin, FILE *fout)
{
    // Feature 2 Read second line, reverse and write it
    char buffer[70];
    char *status = NULL;

    status = fgets(buffer, sizeof(buffer), fin);
    if (status != NULL)
    {
        reverse(buffer, 0, strlen(buffer) - 1);
        printf("%s", buffer);
        fputs(buffer, fout);
    }
}
void reverse(char *x, int begin, int end)
{
    char c;

    if (begin >= end)
        return;

    c = *(x + begin);
    *(x + begin) = *(x + end);
    *(x + end) = c;

    reverse(x, ++begin, --end);
}