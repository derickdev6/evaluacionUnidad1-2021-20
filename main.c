#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Args must be 3");
        return (EXIT_FAILURE);
    }

    FILE *fin = fopen(argv[1], "r");
    if (fin == NULL)
    {
        perror("Failed to open fin: ");
        return (EXIT_FAILURE);
    }

    FILE *fout = fopen(argv[2], "a+");
    if (fout == NULL)
    {
        perror("Failed to open fout: ");
        return (EXIT_FAILURE);
    }

    feature1(fin, fout);
    feature2(fin, fout);
    feature3(fin, fout);

    fclose(fin);
    fclose(fout);

    return EXIT_SUCCESS;
}