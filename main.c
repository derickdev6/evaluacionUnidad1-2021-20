#include <stdio.h>
#include <stdlib.h>
#include "student.h"

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

    // Feature 1 Read first inputFile line and write into outputFile
    char buffer[64];
    char *status = NULL;
    status = fgets(buffer, sizeof(buffer), inFile);
    if (status != NULL)
    {
        printf("%s\n", buffer);
        fputs(buffer, outFile);
    }
    fclose(inFile);
    fclose(outFile);

    return EXIT_SUCCESS;
}
