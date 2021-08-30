#include <stdlib.h>
#include <string.h>
#include "student.h"
#include <stdint.h>

int main(int argc, char *argv[])
{
    char line[32];

    printf("Curso #: nombre, creditos, nota\n");
    scanf("%s", line);
    if (line == NULL)
    {
        perror("line is empty");
        EXIT_FAILURE;
    }
    printf("%s\n", line);
    char token[] = ",";
    char *pnombre = strtok(line, token);
    char *strcred = strtok(NULL, token);
    char *strnota = strtok(NULL, token);

    char name[32];
    strcpy(name, pnombre);
    int cred = atoi(strcred);
    float nota = atof(strnota);

    printf("%s\n", name);
    printf("%d\n", cred);
    printf("%f\n", nota);
}