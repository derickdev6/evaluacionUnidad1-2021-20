#include <stdlib.h>
#include <string.h>
#include "student.h"
#include <stdint.h>

// Declaring functions
void reverse(char *, int, int);

void feature1(FILE *fin, FILE *fout);
void feature2(FILE *fin, FILE *fout);
void feature3(FILE *fin, FILE *fout);

void feature1(FILE *fin, FILE *fout)
{
    // Feature 1 Read first inputFile line and write into outputFile
    // Will read hexadecimal data
    uint8_t data = 0;
    uint8_t lfcount = 0;
    while ((data = fgetc(fin)) != EOF)
    {
        if (data == 10) //When value is NewLine
            lfcount++;
        if (lfcount < 1) //Only works once
        {
            fputc(data, fout);
        }
        else
            break;
    }
}

void feature2(FILE *fin, FILE *fout)
{
    // Feature 2 Read second line, reverse and write it
    char buffer[100];
    char *status = NULL;

    status = fgets(buffer, sizeof(buffer), fin);
    if (status != NULL)
    {
        reverse(buffer, 0, strlen(buffer) - 1);
        fputs(buffer, fout);
    }
}

void feature3(FILE *fin, FILE *fout)
{
    fputs("\n", fout);
    char buffer[300];
    char *status = NULL;

    // status = fgets(buffer, sizeof(buffer), fin);
    status = fgets(buffer, sizeof(buffer), fin);
    if (status != NULL)
    {
        char *pch;
        int sum = 0;
        pch = strtok(buffer, " ");
        while (pch != NULL)
        {
            int x = atoi(pch);
            sum += x;
            printf("%s \t->\t %d\n", pch, x);
            pch = strtok(NULL, " ");
        }
        printf("Total = %d\n", sum);
        // char strsum[10];
        // snprintf(strsum, sizeof(strsum), "%s");

        // printf("%s", strsum);
        fprintf(fout, "%d", sum);
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