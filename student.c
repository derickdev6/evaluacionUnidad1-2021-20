#include <stdlib.h>
#include <string.h>
#include "student.h"
#include <stdint.h>

// Declaring functions
void reverse(char *, int, int);

void feature1(FILE *fin, FILE *fout);
void feature2(FILE *fin, FILE *fout);
void feature3(FILE *fin, FILE *fout);
void feature4(FILE *inFile, int **parr, int *length, char **op);
void feature5(FILE *fout, int *parr, int length, char *op);
void feature6(FILE *fin, struct Obj_t *pobj);

// Array functions
char *create_array(int);
int *create_intarray(int size);
void destroy_array(char *);
void destroy_intarray(int *this);

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

void feature4(FILE *inFile, int **parr, int *length, char **op)
{
    //feature4: Lee er arreglo de entros de la linea 4
    // y la operacion separada por un espacio
    int size_buffer = 256;
    char *buffer = create_array(size_buffer); // contendra la linea 4
    uint8_t data = 0;
    uint8_t lfcount = 0;
    uint8_t i = 0;
    while ((data = fgetc(inFile)) != EOF)
    {
        if (data == 10)
            lfcount++;
        if (lfcount >= 1)
            break;
        buffer[i] = data; //lleno el buffer con la linea 4
        i++;
    }
    // Encontrando la Operacion
    uint8_t size_opp = 8;
    char *opp = create_array(size_opp);
    for (uint8_t j = 0; j < size_opp; j++)
        opp[j] = 0;
    char aux;
    uint8_t k = 0;
    for (uint8_t j = i; j > 0; j--)
    {
        if (buffer[j] == 32)
            break;
        if (buffer[j] > 31 && buffer[j] < 255 && buffer[j] != 127)
        {
            aux = buffer[j];
            opp[k] = aux;
            buffer[j] = 0;
            k++;
        }
    }
    char *temp = create_array(k); //contendra op
    for (uint8_t j = 0; j < k; j++)
        temp[j] = 0;
    uint8_t inv = k - 1;
    for (uint8_t j = 0; j < k; j++)
    {
        temp[inv] = opp[j]; //OP
        inv--;
    }
    //Encontrando parr y len
    int *arr = create_intarray(size_buffer);
    char *token;
    token = strtok(buffer, " ");
    if (token == NULL)
        EXIT_FAILURE;
    arr[0] = atoi(token);
    uint8_t n = 0;
    while (token != NULL)
    {
        if (token != NULL)
        {
            arr[n] = atoi(token);
        }
        else
            break;
        token = strtok(NULL, " ");
        n++;
    }
    uint8_t cont = 0;
    for (uint8_t j = 0; j < size_buffer - 1; j++)
    { //obteniendo len
        if (arr[j] == 0)
            break;
        cont++;
    }
    int *temp2 = create_intarray(cont); //parr
    for (uint8_t j = 0; j < cont; j++)
    {
        temp2[j] = (int)arr[j];
    }

    *length = cont;
    *op = temp;
    *parr = temp2;

    destroy_array(buffer);
}

void feature5(FILE *fout, int *parr, int length, char *op)
{
    // Feature 5 recibe direccion del arreglo y operaciion leida en feature 4
    // Realiza la operacion y guarde el resultado en linea 4 de fout

    unsigned int sumop = 0;
    for (uint8_t i = 0; i < 3; i++)
    {
        sumop += op[i];
    }
    if (sumop == 318)
    { //AVG
        int suma = 0;
        for (uint8_t i = 0; i < length; i++)
        {
            suma += parr[i];
        }
        int avg = suma / length;
        fprintf(fout, "\n");
        fprintf(fout, "%d", avg);
    }
    if (sumop == 326)
    { //MAX
        int max = 0;
        for (uint8_t i = 0; i < length; i++)
        {
            if (parr[i] > max)
                max = parr[i];
        }
        fprintf(fout, "\n");
        fprintf(fout, "%d", max);
    }
    if (sumop == 324)
    { //MIN
        int min = 99999;
        for (uint8_t i = 0; i < length; i++)
        {
            if (parr[i] < min)
                min = parr[i];
        }
        fprintf(fout, "\n");
        fprintf(fout, "%d", min);
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

void feature6(FILE *fin, struct Obj_t *pobj)
{
    // Feature 6 lee la quinta linea de fin, genera un objeto a partir
    // de la estructura de datos pasda por pobj

    uint8_t size = 160;
    char *buffer = create_array(size);
    uint8_t data = 0;
    uint8_t lfcount = 0;
    uint8_t i = 0;
    while ((data = fgetc(fin)) != EOF)
    {
        if (data == 10)
            lfcount++;
        if (lfcount >= 1)
            break;
        buffer[i] = data;
        i++;
    }
    char *token;
    token = strtok(buffer, ","); // Caracter por el cual dividiremos datos
    if (token == NULL)
        EXIT_FAILURE;
    char *nombre = token;
    char *token2 = strtok(NULL, "");
    int cedula = atoi(token2); // Convertimos cedula en int

    pobj->nombre = nombre;
    pobj->cedula = cedula;
    printf("Nombre\t%s\n", pobj->nombre);
    printf("Cedula\t%d\n", pobj->cedula);
}
// Array functions
char *create_array(int size)
{
    return (char *)malloc(sizeof(int) * size);
}
int *create_intarray(int size)
{
    return (int *)malloc(sizeof(int) * size);
}
void destroy_array(char *this)
{
    free(this);
}
void destroy_intarray(int *this)
{
    free(this);
}