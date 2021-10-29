#include <stdio.h>
#include <stdlib.h>
#include "notebook.h"
#include "marca.h"
#include "tipo.h"
#include "bibiliotecaPersonal.h"
#include "servicio.h"
#include "trabajo.h"
#include "ctype.h"
#define TAM_NOTEBOOKS 50 // tamanio notebooks
#define TAM_TRABAJOS 10//tamanio trabajos
#define TAM_MARCAS 4 // tamanio Marca
#define TAM_TIPOS 4 // tamanio tipo
#define TAM_SERVICIOS 4 //tamanio servicio
int main()
{
    char seguir = 's';
    int nextId = 2000;//ID incrementa por pedido de notebook
    int idTrabajos = 15000;//Id Trabajo
    int contadorNotebooks = 0;
    int contadorTrabajos = 0;
    char opcion;
    eNotebook listaNotebooks[TAM_NOTEBOOKS];
    eTrabajo listaTrabajos[TAM_TRABAJOS];
    eTipo listaTipos[TAM_TIPOS] =
    {
        { 5000, "Gamer" },
        { 5001, "Disenio" },
        { 5002, "Ultrabook" },
        { 5003, "Normalita" }
    };

    eMarca listaMarcas[TAM_MARCAS] =
    {
        { 1000, "Compaq"},
        { 1001, "Asus"},
        { 1002, "Acer"},
        { 1003, "HP"}
    };
    eServicio listaServicios[TAM_SERVICIOS] =
    {
        { 20000, "Bateria",2250},
        { 20001, "Display",10300},
        { 20002, "Mantemiento",4400},
        { 20003, "Fuente",5600}
    };
    if(iniciarNotebooks(listaNotebooks,TAM_NOTEBOOKS) == 0 || iniciarTrabajo(listaTrabajos,TAM_TRABAJOS) == 0 )
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
            if(!altaNotebook(listaNotebooks,TAM_NOTEBOOKS,&nextId,listaTipos,TAM_TIPOS,listaMarcas,TAM_MARCAS))
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
                if(!modificarNotebook(listaNotebooks,TAM_NOTEBOOKS,listaMarcas,TAM_MARCAS,listaTipos,TAM_TIPOS))
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
                if(!bajaNotebook(listaNotebooks,TAM_NOTEBOOKS,listaMarcas,TAM_MARCAS,listaTipos,TAM_TIPOS))
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
                if(!ordenarNotebook(listaNotebooks, TAM_NOTEBOOKS, listaMarcas, TAM_MARCAS))
                {
                    printf("No se pudo ordenar\n");
                }
                else
                {
                    mostrarNotebooks(listaNotebooks,TAM_NOTEBOOKS,listaMarcas,TAM_MARCAS,listaTipos,TAM_TIPOS);
                    printf("Se ordenaron con exito\n");
                }
            }
            break;
        case 'E':
            if (!mostrarMarcas(listaMarcas,TAM_MARCAS))
            {
                printf("No se pudieron mostrar las marcas\n");
            }
            break;
        case 'F':
            if (!mostrarTipos(listaTipos,TAM_TIPOS))
            {
                printf("No se pudieron mostrar los tipos \n");
            }
            break;
        case 'G':
            if (!mostrarServicios(listaServicios,TAM_SERVICIOS))
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
                if(!altaTrabajo(listaTrabajos,TAM_TRABAJOS,listaServicios,TAM_SERVICIOS,listaNotebooks,TAM_NOTEBOOKS,&idTrabajos,
                                listaMarcas,TAM_MARCAS,listaTipos,TAM_TIPOS))
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
                if (!mostrarTrabajos(listaTrabajos,TAM_TRABAJOS,listaServicios,TAM_SERVICIOS,listaMarcas,TAM_MARCAS,listaTipos,TAM_TIPOS,listaNotebooks,TAM_NOTEBOOKS))
                {
                    printf("No se pudieron mostrar los  Trabajos\n");
                }
            }
            break;
        case 'J':
            switch(menuInformes())
            {
            case 1:
                if(contadorNotebooks == 0)
                {
                    printf("No hay notebooks para mostrar \n");
                }
                else
                {
                    if (!mostrarNoteboksTipo(listaNotebooks,TAM_NOTEBOOKS,listaMarcas,TAM_MARCAS,listaTipos,TAM_TIPOS))
                    {
                        printf("No se pudieron mostrar las notebooks por tipo\n");
                    }
                }
                break;
            case 2:
                if(contadorNotebooks == 0)
                {
                    printf("No hay notebooks para mostrar \n");
                }
                else
                {
                    if (!mostrarNotebooksMarca(listaNotebooks,TAM_NOTEBOOKS,listaMarcas,TAM_MARCAS,listaTipos,TAM_TIPOS))
                    {
                        printf("No se pudieron mostrar las notebooks por marca\n");
                    }
                }
                break;
            case 3:
                if(contadorNotebooks == 0)
                {
                    printf("No hay notebooks para mostrar \n");
                }
                else
                {
                    if (!mostrarNotebooksMenorPrecio(listaNotebooks,TAM_NOTEBOOKS,listaMarcas,TAM_MARCAS,listaTipos,TAM_TIPOS))
                    {
                        printf("No se pudieron mostrar las notebooks de menor precio\n");
                    }
                }
                break;
            case 4:
                if(contadorNotebooks == 0)
                {
                    printf("No hay notebooks para mostrar \n");
                }
                else
                {
                    if (!mostrarNotebooksAllMarcas(listaNotebooks,TAM_NOTEBOOKS,listaMarcas, TAM_MARCAS,listaTipos,TAM_TIPOS))
                    {
                        printf("No se pudieron mostrar las notebooks por marca\n");
                    }
                }
                break;
            case 5:
                if(contadorNotebooks == 0)
                {
                    printf("No hay notebooks para mostrar \n");
                }
                else
                {
                    if (!cantidadNotebooksMarcaTipo(listaNotebooks,TAM_NOTEBOOKS, listaMarcas, TAM_MARCAS, listaTipos,TAM_TIPOS))
                    {
                        printf("No se pudieron mostrar las notebooks por tipo y marca \n");
                    }
                }
                break;
            case 6:
                if(contadorNotebooks == 0)
                {
                    printf("No hay notebooks para mostrar \n");
                }
                else
                {
                    if (!marcaMasElegida(listaNotebooks,TAM_NOTEBOOKS,listaMarcas,TAM_MARCAS,listaTipos,TAM_TIPOS))
                    {
                        printf("No se pudieron mostrar las notebooks mas elegida por marca\n");
                    }
                }
                break;
            case 7:
                if(contadorTrabajos == 0)
                {
                    printf("No hay trabajos para mostrar \n");
                }
                else
                {
                    if (!mostrarTrabajosNotebook(listaTrabajos,TAM_TRABAJOS,listaServicios,TAM_SERVICIOS,listaMarcas,TAM_MARCAS,listaTipos,TAM_TIPOS,listaNotebooks,TAM_NOTEBOOKS))
                    {
                        printf("No se pudieron mostrar los trabajos de una notebook\n");
                    }
                }
                break;
            case 8:
                if(contadorTrabajos == 0)
                {
                    printf("No hay trabajos para mostrar \n");
                }
                else
                {
                    if (!montoTrabajosNotebook(listaTrabajos,TAM_TRABAJOS,listaServicios,TAM_SERVICIOS,listaMarcas,TAM_MARCAS,listaTipos,TAM_TIPOS,listaNotebooks,TAM_NOTEBOOKS))
                    {
                        printf("No se pudieron mostrar el monto de serivicios a una notebook\n");
                    }
                }
                break;
            case 9:
                if(contadorTrabajos == 0)
                {
                    printf("No hay trabajos para mostrar \n");
                }
                else
                {
                    if (!mostrarServicioANotebooks(listaTrabajos,TAM_TRABAJOS,listaServicios,TAM_SERVICIOS,listaMarcas,TAM_MARCAS,listaTipos,TAM_TIPOS,listaNotebooks,TAM_NOTEBOOKS))
                    {
                        printf("No se pudieron mostrar los servicios realizados a notebooks\n");
                    }
                }
                break;
            case 10:
                if(contadorTrabajos == 0)
                {
                    printf("No hay trabajos para mostrar \n");
                }
                else
                {
                    if (!mostrarServiciosFecha(listaTrabajos,TAM_TRABAJOS,listaServicios,TAM_SERVICIOS,listaMarcas,TAM_MARCAS,listaTipos,TAM_TIPOS,listaNotebooks,TAM_NOTEBOOKS))
                    {
                        printf("No se pudieron mostrar los servicios en esa fecha\n");
                    }
                }
                break;
            case 11:
                printf("Salida del menu informes \n");
                break;
            default:
                printf("Opcion invalida\n");
                break;
            }
            break;
        case 'K':
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
