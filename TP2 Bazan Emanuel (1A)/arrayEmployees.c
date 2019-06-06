
#ifndef arrayemployees_H_INCLUDED
#define arrayemployees_H_INCLUDED
#include "arrayemployees.h"
#endif //arrayemployees_H_INCLUDED

#ifndef input_H_INCLUDED
#define input_H_INCLUDED
#include "input.h"
#endif //_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void initEmployees(eEmpleado* vector, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        vector[i].isEmpty = 0;
    }
}

void  addEmployee(eEmpleado* vector, int tam, eSector* array, int arrayTam)
{
    int indice;
    int registrado;
    int numLegajo;

    indice = espacioLibre(vector, tam);

    if(indice == -1)
    {
        printf("\nNo queda espacio suficiente para nuevos registros.\n");
    }
    else
    {
        printf("Ingrese el numero de legajo del nuevo empleado: ");
        scanf("%d",&numLegajo);
        printf("\n");

        registrado = findEmployeeById(vector, tam, numLegajo);

        if(registrado != -1)
        {
            printf("\n El numero de legago ingresado ya se encuentra registrado: \n");

        }
            else
            {    vector[indice].id = numLegajo;
                vector[indice].isEmpty = 1;
                getString("Ingrese el apellido de su empleado: ", "ERROR! El apellido es muy largo.",vector[indice].apellido, 2, 50);
                getString("Ingrese el nombre de su empleado: ", "ERROR! El nombre es muy largo.",vector[indice].nombre, 2, 50);
                getFloat("Ingrese el sueldo bruto de su empleado: ", "ERROR! Ingreso un importe no valido.",&vector[indice].salario,0, 1000000);
                getInt("Ingrese el SectorID de su empleado: ","ERROR! El ID no es valido.",&vector[indice].idSector, 1, arrayTam);

                printf("\n Registro realizado con exito.\n\n");
            }
        }
    }


        int espacioLibre(eEmpleado* vector, int tam)
        {
            int libre = -1;
            for (int i = 0; i < tam; i++)
            {
                if(vector[i].isEmpty == 0)
                {
                    libre = i;
                }
            }

            return libre;
        }

        int findEmployeeById(eEmpleado* vector, int tam,int id)
        {
            int indice=-1;


            for(int i=0; i<tam; i++)
            {
                if(vector[i].isEmpty==1 && vector[i].id==id)
                {
                    indice= i;
                }
            }
            return indice;
        }

        int removeEmployee(eEmpleado* vector, int tam)
        {

            int id;
            char confirmar;
            int remover;
            printf("Ingrese el id del empleado que desea eliminar\n");
            scanf("%d",&id);

            remover = findEmployeeById(vector, tam, id);
            if(remover != -1)
            {
                do
                {
                    printf("Ingreso el numero de id: %d \n", id);
                    setbuf(stdin, NULL);
                    obtenerCaracterEspecifico("Confirma la baja de su empleado? (S/N)", "ERROR! Ha ingresado un caracter invalido", &confirmar, 's', 'n');
                    printf("\n");
                    system("pause");

                    if(tolower(confirmar) == 'n')
                    {
                        printf ("Se ha cancelado el la baja solicitada.\n");
                        break;
                    }
                    else
                    {
                        vector[remover].isEmpty = 0;
                        printf("\n Se ha gestionado la baja de forma exitosa.\n");
                    }
                }
                while(tolower(confirmar) != 's');
            }
            return remover;
        }

        void sortEmployees(eEmpleado* vector, int tam)
        {
            eEmpleado aux;

            for (int i = 0; i < tam-1 ; i++)
            {
                for (int j = i+1; j < tam; j++)
                {
                    if (stricmp(vector[i].apellido, vector[j].apellido) > 0)
                    {
                        aux = vector[i];
                        vector[i] = vector[j];
                        vector[j] = aux;
                    }

                    if (vector[i].idSector > vector[j].idSector)
                    {
                        aux = vector[i];
                        vector[i] = vector[j];
                        vector[j] = aux;
                    }
                }
            }
        }


        void printEmployees(eEmpleado* vector, int tam)
        {
            int contador = 0;
            printf ("\n Id     Apellido     Nombre     Sueldo     Sector\n");

            for (int i = 0; i < tam; i++)
            {
                if (vector[i].isEmpty == 1)
                {
                    printf ("  %d          %s      %s    %.2f     %d \n", vector[i].id, vector[i].apellido, vector[i].nombre, vector[i].salario, vector[i].idSector);
                    contador++;
                }
            }
            if (contador == 0)
            {
                printf("No hay empleados para mostrar.\n");
            }
        }

        void modifyEmployee (eEmpleado* vector, int tam, eSector* array, int arrayTam)
        {
            int indice;
            int numLegajo;
            char confirma;


            printf ("\n Ingrese el numero de legajo del empleado: ");
            scanf ("%d", &numLegajo);

            indice = findEmployeeById(vector, tam, numLegajo);

            if (indice == -1)
            {
                printf("\n El numero de legajo ingresado es inexistente. \n\n");
            }
            else
            {
                do
                {
                    printf ("Ha ingresado el siguiente legajo: %d \n", numLegajo);
                    setbuf(stdin, NULL);
                    obtenerCaracterEspecifico("Confirma que quiere modificar el registro? (S/N)", "ERROR!, opcion invalida",&confirma, 's', 'n');
                    printf ("\n");
                    system("pause");

                    if (tolower(confirma) == 'n')
                    {
                        printf ("Se ha cancelado la baja.\n\n");
                        break;
                    }
                    else
                    {
                        getString("Ingrese el apellido de su empleado: ", "ERROR! El apellido es muy largo.",vector[indice].apellido, 2, 50);
                        getString("Ingrese el nombre de su empleado: ", "ERROR! El apellido es muy largo.",vector[indice].nombre, 2, 50);
                        getFloat("Ingrese el sueldo bruto de su empleado: ", "ERROR! Ingreso un importe no valido.",&vector[indice].salario,0, 1000000);
                        getInt("Ingrese el SectorID de su empleado: ","ERROR! El ID no es valido.",&vector[indice].idSector, 1, arrayTam);

                        printf ("Se han realizado las modificaciones de forma exitosa.\n\n");
                    }

                }
                while (tolower(confirma) != 's');
            }
        }
        void informeSalarios(eEmpleado* vector, int tam)
        {
            float total = 0;
            int contador = 0;
            float promedio = 0;
            int superaPromedio = 0;

            for (int i = 0; i < tam; i++)
            {
                if(vector[i].isEmpty == 1)
                {
                    contador++;
                    total = total + vector[i].salario;
                    promedio = total / contador;

                    if(vector[i].salario > promedio)
                    {
                        superaPromedio++;
                    }
                }
            }

            if(contador == 0)
            {
                printf("No hay empleados cuyos sueldos calcular\n\n");
            }
            else
            {
                printf("\nReporte de sueldos:\n");
                printf("El total invertido en sueldos es de: $ %.2f \n", total);
                printf("El sueldo promedio es de: $ %.2f \n", promedio);
                printf("%d empleados superan el sueldo promedio \n\n", superaPromedio);
            }
        }

