#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicio.h"


int cargarDescripcionServicio(eServicio listaServicios[], int tam, int idServicio, char descripcion[], int *precio)
{
    int todoOk = 0;
    int flag = 1;
    if (listaServicios != NULL && tam > 0 && descripcion != NULL)
    {
        todoOk = 1;
        for (int i = 0; i < tam; i++)
        {
            if (listaServicios[i].id == idServicio)
            {
                strcpy(descripcion, listaServicios[i].descripcion);
                *precio = listaServicios[i].precio;
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            todoOk = -1; // no habia localidad con el id que le pasaron
        }
    }
    return todoOk;
}

int mostrarServicios(eServicio listaServicios[], int tam)
{
    int todoOk = 0;
    if (listaServicios != NULL && tam > 0 )
    {
        printf("      *** SERVICIOS*** \n\n");
        printf("  Id         Descripcion        Precio\n");
        for (int i = 0; i < tam; i++)
        {
            printf("  %d       %-10s        $%d\n", listaServicios[i].id, listaServicios[i].descripcion, listaServicios[i].precio);
        }
        todoOk = 1;
    }

    return todoOk;
}

int validarIdServicio(int id, eServicio listaServicios[], int tam)
{
    int esValido = 0;
    if (listaServicios!= NULL && tam > 0)
    {
        for (int i = 0; i < tam; i++)
        {
            if (id == listaServicios[i].id)
            {
                esValido = 1;
                break;
            }
        }
    }
    return esValido;
}
