#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "bibiliotecaPersonal.h"

int validarRangoEntero(int valor, int limiteInferior, int limiteSuperior)
{
    int todoOk = 0;
    if(valor >= limiteInferior && valor <= limiteSuperior )
    {
        todoOk = 1;
    }
    return todoOk;
}
int stringPrimerLetraMayuscula(char string[])
{
    int todoOk = 0;
    int i = 0;

    if(string != NULL)
    {
        strlwr(string);
        string[0] = toupper(string[0]);
        while(string[i] != '\0')
        {
            if(string[i] == ' ')
            {
                string[i+1] = toupper(string[i+1]);
            }

            i++;
        }
        todoOk = 1;
    }

    return todoOk;
}

int validarLargoString(char string[], int min, int max)
{
    int todoOk = 0;
    if(string != NULL)
    {

        if(strlen(string) < min || strlen(string) > max)
        {
            todoOk = 1;
        }

    }
    return todoOk;

}
int verificarSueldo(float numero,int min, int max)
{
    int todoOk = 0;
    if(numero >= min && numero <= max)
    {
        todoOk = 1;
    }
    return todoOk;
}
int verificarSiContieneNumero(char list[])
{
    int todoOk = 0;
    if(list!= NULL)
    {
        for (int i = 0; i < strlen(list); i++)
        {
            todoOk = -1;
            if(!(isalpha(list[i])) && list[i] != ' ')
            {
                todoOk = 1;
                break;
            }
        }

    }

    return todoOk;
}
int ingresarString(char mensaje[], char dato[])
{
    int todoOk = 0;

    if(mensaje != NULL && dato !=NULL)
    {
        printf("%s", mensaje);
        fflush(stdin);
        gets(dato);

        todoOk = 1;
    }

    return todoOk;
}
int ingresarEntero(char mensaje[])
{
    int numeroIngresado;
    printf("%s",mensaje);

    scanf("%d",&numeroIngresado);

    return numeroIngresado;

}
float ingresarFlotante(char mensaje[])
{
    float numeroIngresado;
    printf("%s",mensaje);

    scanf("%f",&numeroIngresado);

    return numeroIngresado;

}


void mostrarOpciones(void)
{
    system("cls");
    printf("-------------------------------\n");
    printf("  *** ABM NOTEBOOKS ***\n\n");
    printf("-------------------------------\n");
    printf(" [A]-Alta NOTEBOOK \n");
    printf(" [B]-Modificar NOTEBOOK\n");
    printf(" [C]-Baja NOTEBOOK \n");
    printf(" [D]-Listar NOTEBOOKS \n");
    printf(" [E]-Listar MARCAS \n");
    printf(" [F]-Listar TIPOS\n");
    printf(" [G]-Listar Servicios\n");
    printf(" [H]-Alta Trabajo\n");
    printf(" [I]-Listar Trabajos\n");
    printf(" [J]-Menu Informes\n");
    printf(" [K]-Salir\n");

}
int menuInformes(void)
{
    int opcion;

    system("cls");
    printf("        *** Menu de Informes ***          \n");
    printf("------------------------------------------------\n");
    printf("   1-Mostrar las notebooks del tipo seleccionado por el usuario. \n");
    printf("   2-Mostrar notebooks de una marca seleccionada. \n");
    printf("   3-Informar la o las notebooks mas baratas.\n");
    printf("   4-Mostrar un listado de las notebooks separadas por marca. \n");
    printf("   5-Elegir un tipo y una marca y contar cuantas notebooks hay de ese tipo y esa marca. \n");
    printf("   6-Mostrar la o las marcas mas elegidas por los clientes. \n");
    printf("   7-Pedir una notebook y mostrar todos los trabajos que se le hicieron a la misma. \n");
    printf("   8-Pedir un notebook e informar la suma de los importes de los servicios se le hicieron a la misma \n");
    printf("   9-Pedir un servicio y mostrar las notebooks a las que se realizo ese servicio y la fecha. \n");
    printf("   10-Pedir una fecha y mostrar todos los servicios realizados en la misma. \n");
    printf("   11- Salir\n");

    opcion = ingresarEntero("Ingresa opcion : ");

    return opcion;
}
