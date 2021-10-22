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

int validarLargoString(char string[], int min , int max)
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
int verificarSueldo(float numero,int min , int max)
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

int pedirOpcion(void)
{
	printf("-------------------------------\n");
	printf("  *** ABM LAVADERO AUTOS ***\n\n");
	printf("-------------------------------\n");
	int opcion;
	system("cls");
    printf(" 1-Alta Bicicleta\n");
    printf(" 2-Modificar Bicicleta\n");
    printf(" 3-Baja Bicicleta\n");
    printf(" 4-Listar Bicicletas \n");
    printf(" 5-Listar Tipos\n");
    printf(" 6-Listar Colores\n");
    printf(" 7-Listar Servicios\n");
    printf(" 8-Alta Trabajo\n");
    printf(" 9-Listar Trabajos\n");
    printf(" 10-Salir\n");
	fflush(stdin);
	scanf("%d",&opcion);
	return opcion;
}
