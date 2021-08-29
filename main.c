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
    int *parr = NULL;
    int len = 0;
    char *op = NULL;
    feature4(fin, &parr, &len, &op);
    feature5(fout, parr, len, op);
    struct Obj_t pobj;
    feature6(fin, &pobj);
    feature7(fout, &pobj);

    fclose(fin);
    fclose(fout);

    return EXIT_SUCCESS;
}