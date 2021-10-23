#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trabajo.h"
#include "servicio.h"
#include "fecha.h"
#include "notebook.h"
#include "bibiliotecaPersonal.h"
#define CARGADO 0
#define VACIO 1
int iniciarTrabajo(eTrabajo listaTrabajos[],int tamTrabajos)
{
    int todoOk = 0;
    if(listaTrabajos != NULL && tamTrabajos > 0)
    {
        todoOk = 1;
        for(int i  = 0; i < tamTrabajos ; i++)
        {
            listaTrabajos[i].isEmpty = VACIO;
        }
    }
    return todoOk;
}

int buscarLibreTrabajo(eTrabajo listaTrabajos[],int tamTrabajos)
{
    int indice = -1;
    if(listaTrabajos != NULL && tamTrabajos > 0)
    {
        for(int i = 0; i < tamTrabajos ; i++)
        {
            if(listaTrabajos[i].isEmpty == VACIO)
            {
                indice = i;
                break;
            }

        }
    }
    return indice;
}
int altaTrabajo(eTrabajo listaTrabajos[], int tamTrabajos, eServicio listaServicios[],int tamServicios ,
                eNotebook listaNotebooks [],int tamNotebooks, int *pIdTrabajo, eMarca listaMarcas[],
                int tamMarcas, eTipo listaTipos[], int tamTipos)
{
    int todoOk = 0;
    int indice;
    eTrabajo auxTrabajo;
    if(listaTrabajos != NULL && tamTrabajos > 0 && listaServicios != NULL && tamServicios > 0
            && listaNotebooks != NULL && tamNotebooks > 0 && listaMarcas != NULL && tamMarcas > 0
            && listaTipos != NULL && tamTipos > 0 )
    {
        system("cls");
        printf("  ***Alta Trabajo*** \n\n");
        indice = buscarLibreTrabajo(listaTrabajos,tamTrabajos);
        if(indice == -1)
        {
            printf("Error..\n");
        }
        else
        {
            auxTrabajo.id = *pIdTrabajo;
            (*pIdTrabajo)++;

            mostrarNotebooks(listaNotebooks,tamNotebooks,listaMarcas,tamMarcas,listaTipos,tamTipos);
            auxTrabajo.idNotebook = ingresarEntero("Ingresa el id de la notebook : ");
            while(!validarIdNotebook(auxTrabajo.idNotebook,listaNotebooks,tamNotebooks))
            {
                printf("Error, ingrese un id valido  \n");
                auxTrabajo.idNotebook = ingresarEntero("Ingresa el id de la notebook: ");
            }
            mostrarServicios(listaServicios,tamServicios);
            auxTrabajo.idServicio = ingresarEntero("Ingresa el id del servicio : ");
            while(!validarIdServicio(auxTrabajo.idServicio,listaServicios,tamServicios))
            {
                printf("Error, ingrese el id del servicio valido : ");
                auxTrabajo.idServicio = ingresarEntero("Ingresa el id del servicio : ");
            }
            printf("Ingrese fecha: ");
            scanf("%d/%d/%d", &auxTrabajo.fecha.dia, &auxTrabajo.fecha.mes, &auxTrabajo.fecha.anio);
            while(!validarRangoEntero(auxTrabajo.fecha.dia,1,31) || (!validarRangoEntero(auxTrabajo.fecha.mes,1,12))
                    ||(!validarRangoEntero(auxTrabajo.fecha.anio,2021,2022))
                 )
            {
                printf("Error.Ingrese fecha: ");
                scanf("%d/%d/%d", &auxTrabajo.fecha.dia, &auxTrabajo.fecha.mes, &auxTrabajo.fecha.anio);
            }
            auxTrabajo.isEmpty = CARGADO;
            listaTrabajos[indice] = auxTrabajo;
            todoOk = 1;
        }
    }

    return todoOk;
}

void mostrarTrabajo(eTrabajo unTrabajo, eServicio listaServicios[],int tamServicios)
{
    char descServicio[20];
    int precio;
    if(cargarDescripcionServicio(listaServicios,tamServicios,unTrabajo.idServicio,descServicio,&precio) == 1)
    {
        printf("  %4d           %4d     %15s                $%4d           %02d/%02d/%04d    \n",
               unTrabajo.id,
               unTrabajo.idNotebook,
               descServicio,
               precio,
               unTrabajo.fecha.dia,
               unTrabajo.fecha.mes,
               unTrabajo.fecha.anio);
    }


}
int mostrarTrabajos(eTrabajo listaTrabajos[],int tamTrabajos, eServicio listaServicios[],int tamServicios)
{

    int todoOk = 0;
    int flag = 1;
    if(listaServicios!= NULL && tamTrabajos > 0 && listaServicios != NULL && tamServicios > 0)
    {
        system("cls");
        printf("       *** Listado de Trabajos ***      \n");
        printf("   IdTrabajo        IdNotebook          Servicio        Precio       Fecha\n");
        printf("--------------------------------------------------------------------------------------\n");
        for(int i = 0; i < tamTrabajos; i++)
        {
            if(!listaTrabajos[i].isEmpty)
            {
                mostrarTrabajo(listaTrabajos[i],listaServicios,tamServicios);
                flag = 0;

            }
        }
        if(flag)
        {
            printf("No hay Trabajos para mostrar");

        }
        todoOk = 1;
    }
    return todoOk;

}
