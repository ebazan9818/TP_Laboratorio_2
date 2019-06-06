
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

int menu (void)
{
    int eleccion;

    printf("Menu de opciones: \n\n");

    printf("1. Alta de empleado. \n");
    printf("2. Modificar registro de empleado. \n");
    printf("3. Dar de baja un empleado. \n");
    printf("4. Solicitar Informes. \n");
    printf("5. Salir \n\n");

    printf("Ingrese el numero de la opcion elegida: ");
    setbuf(stdin, NULL);
    scanf("%d",&eleccion);
    printf("\n");

    return eleccion;
}


void getInt(char mensaje[], char error[], int* numero, int min, int max)
{
    printf(mensaje);
    scanf("%d", numero);

    while(*numero < min ||	*numero > max)
    {
        printf(error);
        printf(mensaje);
        scanf("%d", numero);
    }

}


void getFloat(char mensaje[], char error[], float* numeroFloat, int min, int max)
{
    printf(mensaje);
    scanf("%f", numeroFloat);

    while(*numeroFloat < min ||	*numeroFloat > max)
    {
        printf(error);
        printf("\n");
        printf(mensaje);
        scanf("%f", numeroFloat);
    }

}

void getChar(char mensaje[], char error[], char* caracter, char min, char max)
{
    printf(mensaje);
    setbuf(stdin,NULL);
    scanf("%c", caracter);
    setbuf(stdin,NULL);
    while(*caracter < min ||	*caracter > max)
    {
        setbuf(stdin,NULL);
        printf(error);
        printf(mensaje);
        setbuf(stdin,NULL);
        scanf("%c", caracter);
    }

}

void obtenerCaracterEspecifico(char mensaje[], char error[], char* caracter, char car1, char car2)
{
    printf(mensaje);
    setbuf(stdin, NULL);
    scanf("%c", caracter);
    setbuf(stdin, NULL);

    while (*caracter != car1 && *caracter != car2)
    {
        printf(error);
        printf("\n\n");
        printf(mensaje);

        scanf("%c", caracter);
        setbuf(stdin, NULL);
    }
    *caracter = toupper(*caracter);
}

void getString (char mensaje[], char error[], char* cadena, int min, int max)
{
    printf(mensaje);
    setbuf(stdin,NULL);
    gets(cadena);
    *cadena = tolower(*cadena);

  while (strlen(cadena) < min || strlen(cadena) > max)
    {
        printf(error);
        printf("\n");
        printf(mensaje);
        setbuf(stdin, NULL);
        gets(cadena);
        *cadena = tolower(*cadena);
    }
}


