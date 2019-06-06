#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#define TAM 1000
#define TAM_SECTORES 10

#ifndef arrayEmployees_H_INCLUDED
#define arrayEmployees_H_INCLUDED
#include "arrayEmployees.h"
#endif //arrayEmployees_H_INCLUDED

#ifndef input_H_INCLUDED
#define input_H_INCLUDED
#include "input.h"
#endif //_H_INCLUDED


int main()
{

    eSector sectores[TAM_SECTORES] = {

    {1, "Ventas"},
    {2, "Adminitracion"},
    {3, "It"},
    {4, "Compras"},
    {5, "Gerencia"},
    {6, "Recursos Humanos"},
    {7, "Tesoreria"},
    {8, "Logistica"},
    {9, "Prensa"},
    {10, "Legales"}

    };

    eEmpleado empleados[TAM];
    initEmployees(empleados, TAM);


    char salir;
    char seguir = 's';

    do
    {
        switch(menu())
        {
            case 1:
                printf("Alta de empleado\n");
                addEmployee(empleados, TAM, sectores, TAM_SECTORES);
                system("pause");
                break;

            case 2:
                printf("Modificar el registro de un empleado\n");
                modifyEmployee(empleados, TAM, sectores, TAM_SECTORES);
                system("pause");
                break;

            case 3:
                printf ("Dar de baja un empleado.\n");
                removeEmployee(empleados, TAM);
                system("pause");
                break;

            case 4:
                 printf ("Lista de Empleados.\n");
                 sortEmployees(empleados, TAM);
                 printEmployees(empleados, TAM);
                 informeSalarios(empleados, TAM);
                 system("pause");
                 break;

           case 5:
                obtenerCaracterEspecifico(&salir, "Realmente desea salir?\n", "ERROR! opcion no valida.", 's', 'n');
                printf ("\n");
                system("pause");

                if (tolower(salir)=='s')
                {
                    seguir = 'n';
                }
                break;

            default:
                printf ("\n Ha ingresado una opcion de menu invalida\n\n");
                system("break");

        }
    }while(seguir == 's');
    return 0;


}
