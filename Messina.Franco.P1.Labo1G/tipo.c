#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo.h"

int cargarDescripcionTipo(eTipo listaTipos[], int tam, int idTipo, char descripcion[])
{
    int todoOk = 0;
    int flag = 1;
    if (listaTipos!= NULL && tam > 0 && descripcion != NULL)
    {
        todoOk = 1;
        for (int i = 0; i < tam; i++)
        {
            if (listaTipos[i].id == idTipo)
            {
                strcpy(descripcion, listaTipos[i].descripcion);
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            todoOk = -1;
        }
    }
    return todoOk;
}

int mostrarTipos(eTipo listaTipos[], int tam)
{
    int todoOk = 0;
    if (listaTipos!= NULL && tam > 0 )
    {
        printf("      *** TIPOS *** \n\n");
        printf("  Id         Descripcion\n");
        for (int i = 0; i < tam; i++)
        {
            printf("  %d       %-10s\n", listaTipos[i].id, listaTipos[i].descripcion);
        }
        todoOk = 1;
    }

    return todoOk;
}

int validarIdTipo(int id, eTipo listaTipos[], int tam)
{
    int esValido = 0;
    if (listaTipos != NULL && tam > 0)
    {
        for (int i = 0; i < tam; i++)
        {
            if (id == listaTipos[i].id)
            {
                esValido = 1;
                break;
            }
        }
    }
    return esValido;
}
