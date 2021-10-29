#include "notebook.h"
#include "bibiliotecaPersonal.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "tipo.h"
#include "marca.h"
#include "string.h"
#define VACIO 1
#define CARGADO 0

int iniciarNotebooks(eNotebook lista[],int tam)
{
    int todoOk = 0;
    if (lista != NULL && tam > 0)
    {
        todoOk = 1;
        for (int i = 0; i < tam; i++)
        {
            lista[i].isEmpty = VACIO;
        }
    }
    return todoOk;
}
int buscarLibre(eNotebook lista[], int tam)
{
    int indice = -1;
    for (int i = 0; i < tam; i++)
    {
        if (lista[i].isEmpty)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int altaNotebook(eNotebook lista[],int tamN,int *pId, eTipo listaT[],int tamT, eMarca listaM[], int tamM)
{
    int todoOk = 0;
    int indice;
    eNotebook auxNotebook;
    char auxModelo[100];
    if(lista != NULL && tamN > 0 && listaT!= NULL && tamT > 0 && listaM != NULL && tamM> 0)
    {
        system("cls");
        printf("  ***Alta Notebook*** \n\n");
        indice = buscarLibre(lista,tamN);
        if(indice == -1)
        {
            printf("Error..\n");
        }
        else
        {
            auxNotebook.id = *pId;
            (*pId)++;//ID

            ingresarString("Ingresa el modelo de la notebook : ", auxModelo);//Modelo
            while(validarLargoString(auxModelo,1, 20))
            {
                printf("Error no se puede ingresar más de 20 caracteres \n");
                ingresarString("Ingresa el modelo de la notebook : ", auxModelo);
            }
            strcpy(auxNotebook.modelo,auxModelo);
            mostrarMarcas(listaM, tamM);
            auxNotebook.idMarca = ingresarEntero("Ingresar marca: ");

            while (!validarIdMarca(auxNotebook.idMarca, listaM, tamM))
            {
                printf("Error, ingrese id de  Marca valido: ");
                auxNotebook.idMarca = ingresarEntero("Ingresar marca: ");
            }

            mostrarTipos(listaT,tamT);
            auxNotebook.idTipo = ingresarEntero("Ingresar tipo: ");

            while (!validarIdTipo(auxNotebook.idTipo, listaT, tamT))
            {
                printf("Error, ingrese id de  tipo valido \n");
                auxNotebook.idTipo = ingresarEntero("Ingresar tipo: ");
            }
            auxNotebook.precio = ingresarFlotante("Ingresa el precio de la Notebook : ");
            while(auxNotebook.precio <= 0)
            {

                printf("Ingrese un precio valido : ");
                auxNotebook.precio = ingresarFlotante("Ingresa el precio de la Notebook : ");
            }

            auxNotebook.isEmpty = CARGADO;
            lista[indice] = auxNotebook;
            todoOk = 1;
        }
    }

    return todoOk;
}
int mostrarNotebook(eNotebook unaNotebook,eMarca listaM[],int tamM, eTipo listaT[],int tamT)
{
    int todoOk = 0;
    char descTipo[20];
    char descMarca[20];
    if(listaM != NULL && listaM != NULL  && tamM > 0 && listaT != NULL && tamT > 0)
    {
        if (cargarDescripcionTipo(listaT,tamT,unaNotebook.idTipo,descTipo) == 1 &&
                cargarDescripcionMarca(listaM,tamM,unaNotebook.idMarca, descMarca) == 1)
        {
            printf(" %d     %-10s           %-10s       %-10s     $%.2f     \n",
                   unaNotebook.id,
                   unaNotebook.modelo,
                   descMarca,
                   descTipo,
                   unaNotebook.precio
                  );
        }
        todoOk = 1;
    }

    return todoOk;
}
int mostrarNotebooks(eNotebook lista[],int tamN , eMarca listaM[],int tamM, eTipo listaT[],int tamT)
{
    int todoOk = 0;
    int flag = 1;
    if (lista != NULL && tamN> 0 && listaM != NULL && listaT != NULL && tamM > 0 && tamT > 0)
    {
        system("cls");
        printf("                     ***Lista de NOTEBOOKS  ***\n");
        printf("--------------------------------------------------------------------------\n");
        printf(" ID         MODELO             MARCA              TIPO         PRECIO\n");
        printf("---------------------------------------------------------------------------\n");
        for (int i = 0; i < tamN; i++)
        {
            if (lista[i].isEmpty == CARGADO)
            {
                mostrarNotebook(lista[i],listaM,tamM,listaT,tamT);
                flag = 0;
            }
        }
        if (flag)
        {
            printf("No hay Notebooks para mostrar.\n");

        }
        todoOk = 1;
    }
    return todoOk;
}
int buscarNotebookId(eNotebook lista[], int tam, int Id)
{
    int indice = -1;
    if(lista != NULL && tam > 0)
    {
        for (int i = 0; i < tam; i++)
        {
            if (lista[i].id == Id && lista[i].isEmpty == CARGADO)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;
}
int bajaNotebook(eNotebook lista[], int tamN, eMarca listaM[], int tamM, eTipo listaT[],int tamT)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    if (lista != NULL && tamN > 0 && listaM != NULL && tamM > 0 && listaT != NULL && tamT > 0)
    {
        system("cls");
        printf("   *** Baja Notebook *** \n\n");
        mostrarNotebooks(lista,tamN,listaM,tamM,listaT,tamT);
        printf("------------------------------------------------------------\n");
        id = ingresarEntero("Ingresa Id : ");

        indice = buscarNotebookId(lista,tamN,id);

        if (indice == -1)
        {
            printf("El Id: %d no esta registrado en el sistema\n", id);
        }
        else
        {
            mostrarNotebook(lista[indice],listaM,tamM,listaT,tamT);
            printf("Confirma baja? (S/N): ");
            fflush(stdin);
            scanf("%c", &confirma);
            if (confirma == 's')
            {
                lista[indice].isEmpty = VACIO;
                todoOk = 1;
            }
            else
            {
                printf("Baja cancelada por el usuario.\n");
            }
        }
    }
    return todoOk;
}
int modificarNotebook(eNotebook lista[], int tamN, eMarca listaM[], int tamM, eTipo listaT[],int tamT)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    char seguir = 's';
    eNotebook auxNotebook;
    if (lista != NULL && tamN > 0  &&  listaM != NULL && tamM> 0 && listaT != NULL && tamT > 0)
    {
        system("cls");
        printf("   *** Modificar Notebook *** \n\n");
        mostrarNotebooks(lista,tamN,listaM,tamM,listaT,tamT);
        printf("-----------------------------------------------------------------------------\n");
        id = ingresarEntero("Ingresar Id : ");

        indice = buscarNotebookId(lista,tamN,id);

        if (indice == -1)
        {
            printf("El Id : %d no esta registrado en el sistema\n", id);
        }
        else
        {
            do
            {
                switch (menuModificar(lista,tamN,listaM,tamM,listaT,tamT,indice))
                {
                case 1:
                    mostrarNotebook(lista[indice],listaM,tamM,listaT,tamT);
                    auxNotebook.precio = ingresarFlotante("Ingresa el precio de la Notebook : ");
                    while(auxNotebook.precio <= 0)
                    {

                        printf("Ingrese un precio valido : ");
                        auxNotebook.precio = ingresarFlotante("Ingresa el precio de la Notebook: ");
                    }
                    printf("Confirma cambio de precio? (S/N)\n");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = tolower(confirma);

                    if (confirma == 's')
                    {
                        lista[indice].precio = auxNotebook.precio;
                    }
                    else
                    {
                        printf("Cancelado. No se modifico.\n");
                    }
                    printf("Estado Actual de la notebook \n");
                    mostrarNotebook(lista[indice],listaM,tamM,listaT,tamT);
                    break;
                case 2:
                    mostrarNotebook(lista[indice],listaM,tamM,listaT,tamT);
                    mostrarTipos(listaT,tamT);
                    auxNotebook.idTipo = ingresarEntero("Ingresar tipo: ");

                    while (!validarIdTipo(auxNotebook.idTipo, listaT, tamT))
                    {
                        printf("Error, ingrese id de  tipo valido \n");
                        auxNotebook.idTipo = ingresarEntero("Ingresar tipo: ");
                    }
                    printf("Confirma cambio de tipo? (S/N)\n");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = tolower(confirma);
                    if (confirma == 's')
                    {
                        lista[indice].idTipo = auxNotebook.idTipo;
                    }
                    else
                    {
                        printf("Cancelado. No se modifico.\n");
                    }
                    printf("Estado Actual de la notebook \n");
                     mostrarNotebook(lista[indice],listaM,tamM,listaT,tamT);
                    break;
                case 3:
                    seguir = 'n';
                    break;
                default:
                    printf("Opcion invalida\n");
                }
            }
            while(seguir == 's');

            todoOk = 1;
        }
    }
    return todoOk;
}
int menuModificar(eNotebook lista[], int tamN, eMarca listaM[], int tamM, eTipo listaT[],int tamT, int indice)
{
    int opcion = 0;
    if(lista != NULL && tamN > 0 && listaM != NULL && tamM > 0 && listaT != NULL && tamT > 0)
    {
        system("cls");
        printf("------------------------------------------------------------\n");
        mostrarNotebook(lista[indice],listaM,tamM,listaT,tamT);
        printf("------------------------------------------------------------\n");
        printf("1- Editar Precio \n");
        printf("2- Editar Tipo \n");;
        printf("3- Salir\n");
        opcion = ingresarEntero("Ingresa una opcion : ");
    }

    return opcion;
}
int ordenarNotebook(eNotebook lista[], int tamNotebooks, eMarca marcas[], int tamMarcas)
{
    int todoOk = 0;
    eNotebook auxNotebook;
    char descMarcaUno[20];
    char descMarcaDos[20];

    if(lista != NULL && tamNotebooks > 0 && marcas != NULL && tamMarcas > 0)
    {
        for(int i = 0; i < tamNotebooks - 1; i++)
        {
            for(int j = i + 1; j < tamNotebooks ; j++)
            {

                cargarDescripcionMarca(marcas,tamMarcas,lista[i].idMarca,descMarcaUno);
                cargarDescripcionMarca(marcas, tamMarcas, lista[j].idMarca, descMarcaDos);
                if((strcmp(descMarcaUno, descMarcaDos) > 0) || (strcmp(descMarcaUno, descMarcaDos) == 0 && lista[i].precio > lista[j].precio))
                {
                    auxNotebook = lista[i];
                    lista[i] = lista[j];
                    lista[j] = auxNotebook;
                }
            }
        }
        todoOk = 1;
    }
    return todoOk;
}
int validarIdNotebook(int id, eNotebook lista[], int tam)
{
    int esValido = 0;
    if (lista != NULL && tam > 0)
    {
        for (int i = 0; i < tam; i++)
        {
            if (id == lista[i].id && lista[i].isEmpty == CARGADO)
            {
                esValido = 1;
                break;
            }
        }
    }
    return esValido;
}
