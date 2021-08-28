#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

void reverse(char *, int, int);

int main(int argc, char *argv[])
{
    // Getting filenames as args

    // Declaring files as NULL
    FILE *inFile = NULL;
    FILE *outFile = NULL;

    // Checking for args
    for (int i = 0; i < argc; i++)
    {
        printf("argv[%d]: %s\n", i, argv[i]);

        // First arg will be taken as read
        if (i == 1)
        {
            inFile = fopen(argv[i], "r");
            if (inFile == NULL)
            {
                perror("Failed read file opening: ");
                return (EXIT_FAILURE);
            }
        }

        // Second arg will be taken as write
        if (i == 2)
        {
            outFile = fopen(argv[i], "w");
            if (outFile == NULL)
            {
                perror("Failed write file opening: ");
                return (EXIT_FAILURE);
            }
        }
    }

    // Basic for reading lines
    char buffer[70];
    char *status = NULL;

    // Feature 1 Read first inputFile line and write into outputFile
    status = fgets(buffer, sizeof(buffer), inFile);
    if (status != NULL)
    {
        printf("%s", buffer);
        fputs(buffer, outFile);
    }
    // fclose(inFile);
    // fclose(outFile);

    // Feature 2 Read second line, reverse it and put it in O file
    // status = fgets(buffer, sizeof(buffer), inFile);
    status = fgets(buffer, sizeof(buffer), inFile);
    if (status != NULL)
    {
        reverse(buffer, 0, strlen(buffer) - 1);
        printf("%s", buffer);
        fputs(buffer, outFile);
    }
    fclose(inFile);
    fclose(outFile);

    return EXIT_SUCCESS;
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