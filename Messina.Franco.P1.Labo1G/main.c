#include <stdio.h>
#include <stdlib.h>
#include "notebook.h"
#include "marca.h"
#include "tipo.h"
#include "bibiliotecaPersonal.h"
#include "servicio.h"
#include "trabajo.h"
#include "ctype.h"
#define TAM 10 // tamanio notebooks
#define TAM_TRABAJOS 20//tamanio trabajos
#define TAM_MARCA 4 // tamanio Marca
#define TAM_TIPO 4 // tamanio tipo
#define TAM_SERVICIO 4 //tamanio servicio
int main()
{
    char seguir = 's';
    int nextId = 2000;//ID incrementa por pedido de notebook
    int idTrabajos = 15000;//Id Trabajo
    int contadorNotebooks = 0;
    int contadorTrabajos = 0;
    char opcion;
    eNotebook listaNotebooks[TAM];
    eTrabajo listaTrabajos[TAM_TRABAJOS];
    eTipo listaTipos[TAM_TIPO] =
    {
        { 5000, "Gamer" },
        { 5001, "Disenio" },
        { 5002, "Ultrabook" },
        { 5003, "Normalita" }
    };

    eMarca listaMarca[TAM_MARCA] =
    {
        { 1000, "Compaq"},
        { 1001, "Asus"},
        { 1002, "Acer"},
        { 1003, "HP"}
    };
    eServicio listaServicios[TAM_SERVICIO] =
    {
        { 20000, "Bateria",2250},
        { 20001, "Display",10300},
        { 20002, "Mantemiento",4400},
        { 20003, "Fuente",5600}
    };
    if(iniciarNotebooks(listaNotebooks,TAM) == 0 || iniciarTrabajo(listaTrabajos,TAM_TRABAJOS) == 0 )
    {
        printf("Error \n");
    }
    do
    {
        mostrarOpciones();
        printf("Elige una opcion : \n");
        fflush(stdin);
        scanf("%c",&opcion);
        opcion = toupper(opcion);
        switch (opcion)
        {
        case 'A':
            if(!altaNotebook(listaNotebooks,TAM,&nextId,listaTipos,TAM_TIPO,listaMarca,TAM_MARCA))
            {
                printf("No se pudo realizar el alta\n");
            }
            else
            {
                printf("Alta exitosa\n");
                contadorNotebooks++;
            }
            break;
        case 'B':
            if(contadorNotebooks == 0)
            {
                printf("No hay notebooks para modificar \n");
            }
            else
            {
                if(!modificarNotebook(listaNotebooks,TAM,listaMarca,TAM_MARCA,listaTipos,TAM_TIPO))
                {
                    printf("No se pudo modificar\n");
                }
                else
                {
                    printf("Cambios realizados con exito\n");
                }
            }

            break;
        case 'C':
            if(contadorNotebooks == 0)
            {
                printf("No hay notebooks para dar de baja \n");
            }
            else
            {
                if(!bajaNotebook(listaNotebooks,TAM,listaMarca,TAM_MARCA,listaTipos,TAM_TIPO))
                {
                    printf("No se pudo realizar la baja\n");
                }
                else
                {
                    printf("Baja exitosa\n");
                    contadorNotebooks--;
                }
            }
            break;
        case 'D':
            if(contadorNotebooks == 0)
            {
                printf("No hay notebooks para mostrar \n");
            }
            else
            {
                if(!ordenarNotebook(listaNotebooks, TAM, listaMarca, TAM_MARCA))
                {
                    printf("No se pudo ordenar\n");
                }
                else
                {
                    mostrarNotebooks(listaNotebooks,TAM,listaMarca,TAM_MARCA,listaTipos,TAM_TIPO);
                    printf("Se ordenaron con exito\n");
                }
            }
            break;
        case 'E':
            if (!mostrarMarcas(listaMarca,TAM_MARCA))
            {
                printf("No se pudieron mostrar las marcas\n");
            }
            break;
        case 'F':
            if (!mostrarTipos(listaTipos,TAM_TIPO))
            {
                printf("No se pudieron mostrar los tipos \n");
            }
            break;
        case 'G':
            if (!mostrarServicios(listaServicios,TAM_SERVICIO))
            {
                printf("No se pudieron mostrar los servicios \n");
            }
            break;
        case 'H':
            if(contadorNotebooks == 0 )
            {
                printf("No hay notebooks para dar de alta de trabajos \n");
            }
            else
            {
                if(!altaTrabajo(listaTrabajos,TAM_TRABAJOS,listaServicios,TAM_SERVICIO,listaNotebooks,TAM,&idTrabajos,
                                listaMarca,TAM_MARCA,listaTipos,TAM_TIPO))
                {
                    printf("No se pudo realizar el alta\n");
                }
                else
                {
                    printf("Alta exitosa\n");
                    contadorTrabajos++;
                }

            }
            break;
        case 'I':
            if(contadorTrabajos == 0)
            {
                printf("No hay ningun trabajo para mostrar \n");
            }
            else
            {
                if (!mostrarTrabajos(listaTrabajos,TAM_TRABAJOS,listaServicios,TAM_SERVICIO))
                {
                    printf("No se pudieron mostrar los  Trabajos\n");
                }
            }
            break;
        case 'J':
            printf("Salida exitosa \n");
            seguir = 'n';
            break;
        default:
            printf("Opcion invalida\n");
            break;
        }
        system("pause");
    }
    while(seguir == 's');
    return 0;
}
