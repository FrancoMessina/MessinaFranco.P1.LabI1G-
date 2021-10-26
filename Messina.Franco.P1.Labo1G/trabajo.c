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
int altaTrabajo(eTrabajo listaTrabajos[], int tamTrabajos, eServicio listaServicios[],int tamServicios,
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
            while(verificarFecha(auxTrabajo.fecha.dia, auxTrabajo.fecha.mes, auxTrabajo.fecha.anio) == 0)
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

int mostrarTrabajo(eTrabajo unTrabajo, eServicio listaS[],int tamS,
                   eMarca listaM[],int tamM, eTipo listaT[], int tamT, eNotebook listaN[], int tamN)
{
    int todoOk = 0;
    char descServicio[20];
    char descTipo[20];
    char descMarca[20];
    int precio;
    int indice;
    indice = buscarNotebookId(listaN,tamN,unTrabajo.idNotebook);
    if(listaS != NULL && tamS > 0 && listaM != NULL && tamM > 0 && listaT != NULL && tamT > 0 && listaN != NULL && tamN > 0 )
    {
        if(cargarDescripcionServicio(listaS,tamS,unTrabajo.idServicio,descServicio,&precio) == 1
                && cargarDescripcionMarca(listaM,tamM,listaN[indice].idMarca,descMarca) == 1 &&
                cargarDescripcionTipo(listaT,tamT,listaN[indice].idTipo,descTipo) == 1 )
        {

            printf(" %d               %d                %10s      %10s     %10s      %10s              $%2d          %02d/%02d/%04d\n",
                   unTrabajo.id,
                   unTrabajo.idNotebook,
                   descMarca,
                   descTipo,
                   listaN[indice].modelo,
                   descServicio,
                   precio,
                   unTrabajo.fecha.dia,
                   unTrabajo.fecha.mes,
                   unTrabajo.fecha.anio);

        }

        todoOk = 1;
    }
    return todoOk;
}
int mostrarTrabajos(eTrabajo listaTrabajos[],int tamTrabajos, eServicio listaS[],int tamS,
                    eMarca listaM[],int tamM, eTipo listaT[], int tamTipos, eNotebook listaN[], int tamN)
{

    int todoOk = 0;
    int flag = 1;
    if(listaTrabajos != NULL &&  tamTrabajos > 0 && listaS != NULL && tamS
            > 0 && listaM != NULL && tamM > 0 && listaT != NULL && tamTipos > 0 && listaN != NULL && tamN > 0)
    {
        system("cls");
        printf("       ***                                          Listado de Trabajos ***      \n");
        printf("*******************************************************************************************************************************************\n");
        printf("[ID TRABAJO]        [ID NOTEBOOK]            [MARCA]         [TIPO]        [MODELO]       [SERVICIO]            [PRECIO]       [FECHA]\n");
        printf("*******************************************************************************************************************************************\n");
        for(int i = 0; i < tamTrabajos; i++)
        {
            if(listaTrabajos[i].isEmpty == CARGADO)
            {
                mostrarTrabajo(listaTrabajos[i],listaS,tamS,listaM,tamM,listaT,tamTipos,listaN,tamN);
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
